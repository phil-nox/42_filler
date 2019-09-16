/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n44_map_force_set.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:58:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 19:25:25 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	get(map, row, col + 1) > to_set)) //"."
*/

void	set_around_force_part0(t_map *map, int pnt[2], int to_set, int *out)
{
	if (in_gm(map, pnt[0], pnt[1] + 1) && (get(map, pnt[0], pnt[1] + 1) == -1
		|| get(map, pnt[0], pnt[1] + 1) > to_set))
		*out += set_val(map, pnt[0], pnt[1] + 1, to_set);
	if (in_gm(map, pnt[0], pnt[1] - 1) && (get(map, pnt[0], pnt[1] - 1) == -1
		|| get(map, pnt[0], pnt[1] - 1) > to_set))
		*out += set_val(map, pnt[0], pnt[1] - 1, to_set);
	if (in_gm(map, pnt[0] + 1, pnt[1]) && (get(map, pnt[0] + 1, pnt[1]) == -1
		|| get(map, pnt[0] + 1, pnt[1]) > to_set))
		*out += set_val(map, pnt[0] + 1, pnt[1], to_set);
	if (in_gm(map, pnt[0] - 1, pnt[1]) && (get(map, pnt[0] - 1, pnt[1]) == -1
		|| get(map, pnt[0] - 1, pnt[1]) > to_set))
		*out += set_val(map, pnt[0] - 1, pnt[1], to_set);
}

void	set_around_force_part1(t_map *map, int pnt[2], int to_set, int *out)
{
	if (in_gm(map, pnt[0] + 1, pnt[1] + 1)
		&& (get(map, pnt[0] + 1, pnt[1] + 1) == -1
		|| get(map, pnt[0] + 1, pnt[1] + 1) > to_set))
		*out += set_val(map, pnt[0] + 1, pnt[1] + 1, to_set);
	if (in_gm(map, pnt[0] + 1, pnt[1] - 1)
		&& (get(map, pnt[0] + 1, pnt[1] - 1) == -1
		|| get(map, pnt[0] + 1, pnt[1] - 1) > to_set))
		*out += set_val(map, pnt[0] + 1, pnt[1] - 1, to_set);
	if (in_gm(map, pnt[0] - 1, pnt[1] + 1)
		&& (get(map, pnt[0] - 1, pnt[1] + 1) == -1
		|| get(map, pnt[0] - 1, pnt[1] + 1) > to_set))
		*out += set_val(map, pnt[0] - 1, pnt[1] + 1, to_set);
	if (in_gm(map, pnt[0] - 1, pnt[1] - 1)
		&& (get(map, pnt[0] - 1, pnt[1] - 1) == -1
		|| get(map, pnt[0] - 1, pnt[1] - 1) > to_set))
		*out += set_val(map, pnt[0] - 1, pnt[1] - 1, to_set);
}

int		set_around_force(t_map *map, int pnt[2], int to_set)
{
	int out;

	out = 0;
	set_around_force_part0(map, pnt, to_set, &out);
	set_around_force_part1(map, pnt, to_set, &out);
	return (out);
}

void	set_val_map_force_job(t_map *map, int *stop, int to_find, int to_set)
{
	int pnt[2];

	pnt[0] = -1;
	while (++pnt[0] < map->row)
	{
		pnt[1] = -1;
		while (++pnt[1] < map->col)
		{
			if (get_pnt(map, pnt) != to_find)
				continue;
			*stop += set_around_force(map, pnt, to_set);
		}
	}
}

int		set_val_map_force(t_game *game, t_map *map, int to_find)
{
	int stop;
	int how_far;
	int to_set;

	stop = 1;
	to_set = (to_find > 0) ? to_find + 1 : 1;
	how_far = 0;
	while (stop != 0)
	{
		how_far += 1;
		stop = 0;
		set_val_map_force_job(map, &stop, to_find, to_set);
		to_find = to_set++;
		if (game->show_set_wave_debug)
			debug_value_map_color(map, "");
	}
	if (game->show_set_wave_debug)
		debug_print("|||||||| END WAVE SET ||||||||", 1, 0);
	if (game->show_set_debug)
		debug_set(map);
	return (how_far);
}
