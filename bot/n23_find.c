/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n23_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 18:08:18 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	shadow_math(t_game *game, t_score *score, int row, int col)
{
	int min_border_val;

	as_map(game->map, game->adv);
	score->place_score = place_pie(game, game->adv, row, col);
	if (game->show_place)
		debug_place(game->adv);
	reset_val_map(game, row, col);
	while ((min_border_val = glob_min_val_around(game->adv)) != -1)
		set_val_map(game, game->adv, min_border_val);
	if (game->show_reset_wave_debug)
		debug_reset(game->adv);
	diff_val_map(game, min_border_val, score, 0);
	as_map(game->att, game->fld);
	place_pie(game, game->fld, row, col);
	set_val_map_force(game, game->fld, -3);
	zones(game->fre, game->fld, game->map);
	zone_diff(game->fre, game->zon);
	diff_for_field(game->fld, game->att);
	debug_metric(game, "");
}

void	init_find_place(t_game *game, int *count)
{
	game->best_score.place_score = -1;
	count = 0;
	as_map(game->org, game->map);
	set_val_map(game, game->map, 0);
	as_map(game->org, game->att);
	set_val_map(game, game->att, -2);
	if (game->show_att_debug)
		debug_att(game->att);
	as_map(game->org, game->zon);
	as_map(game->org, game->fre);
	zones(game->zon, game->att, game->map);
	debug_value_map_color(game->zon, "");
}

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
				shadow_math(game, &score, row, col);
				calc_decision(game, &score, 0);
				if (game->best_score.place_score == -1
					|| change_decision(&(game->best_score), &score))
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
