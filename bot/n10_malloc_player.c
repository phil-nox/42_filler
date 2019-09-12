/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n10_malloc_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:55:40 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 16:44:30 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		set_player_adv(char *line, t_game *game)
{
	if (ft_strstr(line, PLY_KW) != NULL)
	{
		game->player = *(line + 10) - 48;
		return (1);
	}
	else
		return (0);
}

int		one_time_game_malloc(t_game *game)
{
	int idx;
	int id_map;

	id_map = -1;
	while (game->fields[++id_map])
	{
		game->fields[id_map]->map = \
			(int **)malloc((game->org->row) * sizeof(int **));
		if (add_mstack(game->fields[id_map]->map))
			return (1);
	}
	idx = -1;
	while (++idx < game->org->row)
	{
		id_map = -1;
		while (game->fields[++id_map])
		{
			game->fields[id_map]->map[idx] = \
				(int *)malloc((game->org->col) * sizeof(int *));
			if (add_mstack(game->fields[id_map]->map[idx]))
				return (1);
		}
	}
	return (0);
}
