/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n41_map_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:28:34 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 17:56:16 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	get(map, row, col + 1) == -1) //"."
*/

int	set_around(t_game *game, t_map *map, int pnt[2], int to_set)
{
	int out;
	int row;
	int col;

	row = pnt[0];
	col = pnt[1];
	out = 0;
	if (in_borders(game, row, col + 1) && get(map, row, col + 1) == -1)
		out += set_val(map, row, col + 1, to_set);
	if (in_borders(game, row, col - 1) && get(map, row, col - 1) == -1)
		out += set_val(map, row, col - 1, to_set);
	if (in_borders(game, row + 1, col) && get(map, row + 1, col) == -1)
		out += set_val(map, row + 1, col, to_set);
	if (in_borders(game, row - 1, col) && get(map, row - 1, col) == -1)
		out += set_val(map, row - 1, col, to_set);
	if (in_borders(game, row + 1, col + 1) && get(map, row + 1, col + 1) == -1)
		out += set_val(map, row + 1, col + 1, to_set);
	if (in_borders(game, row + 1, col - 1) && get(map, row + 1, col - 1) == -1)
		out += set_val(map, row + 1, col - 1, to_set);
	if (in_borders(game, row - 1, col + 1) && get(map, row - 1, col + 1) == -1)
		out += set_val(map, row - 1, col + 1, to_set);
	if (in_borders(game, row - 1, col - 1) && get(map, row - 1, col - 1) == -1)
		out += set_val(map, row - 1, col - 1, to_set);
	return (out);
}

void set_val_map_job(t_game *game, t_map *map, int *stop, int to_find, int to_set)
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
			stop += set_around(game, map, pnt, to_set);
		}
	}
}

int	set_val_map(t_game *game, t_map *map, int to_find)
{
	int pnt[2];
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
		pnt[0] = -1;
		while (++pnt[0] < map->row)
		{
			pnt[1] = -1;
			while (++pnt[1] < map->col)
			{
				if (get_pnt(map, pnt) != to_find)
					continue;
				stop += set_around(game, map, pnt, to_set);
			}
		}
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

/*
**	(tmp = get(map, row, col + 1)) > -1 //"."
*/

int	min_val_around(t_game *game, t_map *map, int pnt[2])
{
	int tmp;
	int min_val;
	int row;
	int col;

	row = pnt[0];
	col = pnt[1];
	min_val = 2147483647;
	if (in_borders(game, row, col + 1) && (tmp = get(map, row, col + 1)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row, col - 1) && (tmp = get(map, row, col - 1)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row + 1, col) && (tmp = get(map, row + 1, col)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row - 1, col) && (tmp = get(map, row - 1, col)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row + 1, col + 1) && (tmp = get(map, row + 1, col + 1)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row + 1, col - 1) && (tmp = get(map, row + 1, col - 1)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row - 1, col + 1) && (tmp = get(map, row - 1, col + 1)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (in_borders(game, row - 1, col - 1) && (tmp = get(map, row - 1, col - 1)) > -1)
		min_val = (tmp < min_val) ? tmp : min_val;
	if (min_val < 2147483647)
		return (min_val);
	return (-1);
}

int	glob_min_val_around(t_game *game, t_map *map)
{
	int pnt[2];
	int min;
	int tmp;

	min = 2147483647;
	pnt[0] = -1;
	while (++pnt[0] < map->row)
	{
		pnt[1] = -1;
		while (++pnt[1] < map->col)
		{
			tmp = get_pnt(map, pnt);
			if (tmp != -1)
				continue;
			tmp = min_val_around(game, map, pnt);
			if (tmp > -1)
				min = (tmp < min) ? tmp : min;
		}
	}
	return ((min < 2147483647) ? min : -1);
}
