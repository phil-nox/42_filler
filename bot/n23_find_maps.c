/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n23_find_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 22:06:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	enemy_shadow(t_game *game, t_score *score, int row, int col)
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
}

void	expansion_front(t_game *game, int row, int col)
{
	as_map(game->att, game->fld);
	place_pie(game, game->fld, row, col);
	set_val_map_force(game, game->fld, -3);
	zones(game->fre, game->fld, game->map);
	zone_diff(game->fre, game->zon);
	diff_for_field(game->fld, game->att);
}

void	math_maps(t_game *game, t_score *score, int row, int col)
{
	enemy_shadow(game, score, row, col);
	expansion_front(game, row, col);
	if (game->show_general_debug)
		debug_metric(game, "");
}

void	init_best_score(t_score *score)
{
	score->place_score = -1;
	score->unreachable = 0;
	score->diff_average = 0;
	score->diff_num = 0;
	score->diff_sum = 0;
	score->expansion_num = 0;
	score->expansion_sum = 0;
	score->expansion_avr = 0;
	score->front_num = 0;
	score->front_sum = 0;
	score->front_avr = 0;
	score->un_score = 0;
	score->df_score = 0;
	score->fn_score = 0;
}

void	init_find_place(t_game *game, int *count)
{
	//game->best_score.place_score = -1;
	init_best_score(&(game->best_score));
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
	if (game->show_general_debug)
		debug_init_maps(game, "");
}
