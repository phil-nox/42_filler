/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n11_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:55:40 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:14:38 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_map_push(t_game *game, int *to_set, char gage)
{
	if (gage == 'o' || gage == 'O')
		*to_set = (game->player == 1) ? -2 : 0;
	else if (gage == 'x' || gage == 'X')
		*to_set = (game->player == 2) ? -2 : 0;
	else if (gage == '.')
		*to_set = -1;
	else if (gage == '*')
		*to_set = -3;
	else
		*to_set = -4;
}

/*
**	trg->map[idx][idxc] = -4; //error
*/

int		set_map_job(t_game *game, char *keyword, int fd_in)
{
	int		idx;
	int		idxc;
	char	*line;
	char	tmp;
	t_map	*trg;

	trg = (keyword == MAP_KW) ? game->org : game->pie;
	idx = -1;
	while (++idx < trg->row)
	{
		get_next_line(fd_in, &line);
		if (add_mstack(line))
			return (-1);
		idxc = -1;
		while (++idxc < trg->col)
		{
			tmp = (keyword == MAP_KW) ? line[idxc + SHIFT_M] : line[idxc];
			set_map_push(game, trg->map[idx] + idxc, tmp);
		}
		free_mstack(line);
	}
	return (0);
}

int		set_map(t_game *game, char *keyword, int fd_in)
{
	char	*line;
	t_map	*trg;

	trg = (keyword == MAP_KW) ? game->org : game->pie;
	if (keyword == MAP_KW)
	{
		if (trg->map == NULL)
			if (one_time_game_malloc(game))
				return (-1);
		get_next_line(fd_in, &line);
		if (add_mstack(line))
			return (-1);
		free_mstack(line);
	}
	set_map_job(game, keyword, fd_in);
	return (1);
}

void	warning_size_of_pie(char *line, t_game *game, t_map *trg)
{
	if (trg->map != NULL && \
		(game->pie->row > game->org->row || game->pie->col > game->org->col))
	{
		debug_print_fd("⚠️⚠️⚠️⚠️ pie > org ⚠️⚠️⚠️⚠️", 1, 0);
		debug_print_fd(line, 1, 0);
	}
}

int		init_map(char *line, t_game *game, char *keyword, int fd_in)
{
	t_map	*trg;
	int		out;
	char	*num;

	if (!ft_strstr(line, keyword))
		return (0);
	if (game->show_read_debug)
		debug_print_fd(line, 1, 0);
	trg = (keyword == MAP_KW) ? game->org : game->pie;
	trg->row = ft_atoi(line + ft_strlen(keyword));
	num = ft_itoa(trg->row);
	if (add_mstack(num))
		return (-1);
	trg->col = ft_atoi(line + ft_strlen(keyword) + ft_strlen(num));
	warning_size_of_pie(line, game, trg);
	free_mstack(num);
	free_mstack(line);
	out = set_map(game, keyword, fd_in);
	if (out != -1 && game->show_read_debug)
	{
		debug_value_map_color(trg, "");
		if (keyword == PIE_KW)
			debug_print_fd("<<<<<<<< END INPUT <<<<<<<<", 1, 0);
	}
	return (out);
}
