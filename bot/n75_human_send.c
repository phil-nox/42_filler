/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n75_human_send.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:10:36 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 21:29:52 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

int		map_human(int input, int fd_map)
{
	if (input == -3)
		return (send_to_fd("F", fd_map));
	if (input == -2)
		return (send_to_fd("O", fd_map));
	if (input == 0)
		return (send_to_fd("X", fd_map));
	if (input == 1)
		return (send_to_fd("T", fd_map));
	return (send_to_fd(".", fd_map));
}

void	place_pie_for_view(t_game *game, int val)
{
	int r;
	int c;

	r = -1;
	c = -1;
	as_map(game->map, game->adv);
	while (++r < game->pie->row)
	{
		c = -1;
		while (++c < game->pie->col)
		{
			if (game->pie->map[r][c] == -1)
				continue;
			set_val(game->adv, game->pnt[0] + r, game->pnt[1] + c, val);
		}
	}
}

void	send_map_to_view(t_game *g, t_map *show, int fd_map, int with_pie)
{
	int row;
	int col;
	int valid;

	if (with_pie)
	{
		valid = (is_a_place(g, g->map, g->pnt[0], g->pnt[1]) == 1) ? 1 : -3;
		place_pie_for_view(g, valid);
	}
	row = -1;
	send_to_fd("++\n", fd_map);
	while (++row < show->row)
	{
		col = -1;
		while (++col < show->col)
			map_human(show->map[row][col], fd_map);
		send_to_fd("\n", fd_map);
	}
}

int		map_incoming(t_game *game, char *line, int fd)
{
	int error;

	error = 0;
	if ((error = init_map(line, game, PIE_KW, fd)))
	{
		as_map(game->org, game->map);
		return (1);
	}
	if (error == -1)
	{
		free_all_mstack();
		return (-1);
	}
	if ((error = init_map(line, game, MAP_KW, fd)))
		return (0);
	if (error == -1)
	{
		free_all_mstack();
		return (-1);
	}
	set_player_adv(line, game);
	free_mstack(line);
	return (0);
}

int		cmd_apply(t_game *game, int fd_map, char input)
{
	int row;
	int col;

	row = game->pnt[0];
	col = game->pnt[1];
	if (input == 'e')
		return (send_position(game->pnt[0], game->pnt[1], 0));
	if (input == 's')
		game->pnt[0] += 1;
	if (input == 'w')
		game->pnt[0] -= 1;
	if (input == 'd')
		game->pnt[1] += 1;
	if (input == 'a')
		game->pnt[1] -= 1;
	if (is_a_place(game, game->map, game->pnt[0], game->pnt[1]) == -1)
	{
		game->pnt[0] = row;
		game->pnt[1] = col;
		return (0);
	}
	send_map_to_view(game, game->adv, fd_map, 1);
	return (0);
}
