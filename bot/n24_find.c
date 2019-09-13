/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n24_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 22:07:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	set_score(t_game *game, t_score *score, int row, int col)
{
	game->best_score = *score;
	game->pnt[0] = row;
	game->pnt[1] = col;
}

int		find_place(t_game *game)
{
	int		row;
	int		col;
	int		plc;
	int		count;
	t_score	score;

	init_find_place(game, &count);
	row = -game->pie->row;
	while (++row < game->map->row)
	{
		col = -game->pie->col;
		while (++col < game->map->col)
		{
			if ((plc = is_a_place(game, game->map, row, col)) == 1)
			{
				count++;
				math_maps(game, &score, row, col);
				math_score(game, &score);
				if (game->show_general_debug)
					score_debug(&score);
				if (game->best_score.place_score == -1
					|| math_decision(game, &score))
					set_score(game, &score, row, col);
			}
		}
	}
	return (count);
}

int		find_first_place(t_game *game, t_map *map)
{
	int row;
	int col;

	row = -game->pie->row;
	while (++row < map->row)
	{
		col = -game->pie->col;
		while (++col < map->col)
		{
			if (is_a_place(game, map, row, col) == 1)
			{
				game->pnt[0] = row;
				game->pnt[1] = col;
				return (1);
			}
		}
	}
	return (0);
}
