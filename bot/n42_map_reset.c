/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n42_map_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:21:33 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:14:58 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		reset_this(t_map *adv, int row, int col, int to_set)
{
	int cur;

	cur = get(adv, row, col);
	if (cur < 1)
		return (-1);
	if (in_gm(adv, row, col + 1) && get(adv, row, col + 1) == cur - 1)
		return (-1);
	if (in_gm(adv, row, col - 1) && get(adv, row, col - 1) == cur - 1)
		return (-1);
	if (in_gm(adv, row + 1, col) && get(adv, row + 1, col) == cur - 1)
		return (-1);
	if (in_gm(adv, row - 1, col) && get(adv, row - 1, col) == cur - 1)
		return (-1);
	if (in_gm(adv, row + 1, col + 1) && get(adv, row + 1, col + 1) == cur - 1)
		return (-1);
	if (in_gm(adv, row + 1, col - 1) && get(adv, row + 1, col - 1) == cur - 1)
		return (-1);
	if (in_gm(adv, row - 1, col + 1) && get(adv, row - 1, col + 1) == cur - 1)
		return (-1);
	if (in_gm(adv, row - 1, col - 1) && get(adv, row - 1, col - 1) == cur - 1)
		return (-1);
	set_val(adv, row, col, to_set);
	return (cur);
}

int		reset_around(t_map *adv, int row, int col, int to_set)
{
	int out;

	out = 0;
	if (in_gm(adv, row, col + 1) && get(adv, row, col + 1) > 0)
		out += reset_this(adv, row, col + 1, to_set);
	if (in_gm(adv, row, col - 1) && get(adv, row, col - 1) > 0)
		out += reset_this(adv, row, col - 1, to_set);
	if (in_gm(adv, row + 1, col) && get(adv, row + 1, col) > 0)
		out += reset_this(adv, row + 1, col, to_set);
	if (in_gm(adv, row - 1, col) && get(adv, row - 1, col) > 0)
		out += reset_this(adv, row - 1, col, to_set);
	if (in_gm(adv, row + 1, col + 1) && get(adv, row + 1, col + 1) > 0)
		out += reset_this(adv, row + 1, col + 1, to_set);
	if (in_gm(adv, row + 1, col - 1) && get(adv, row + 1, col - 1) > 0)
		out += reset_this(adv, row + 1, col - 1, to_set);
	if (in_gm(adv, row - 1, col + 1) && get(adv, row - 1, col + 1) > 0)
		out += reset_this(adv, row - 1, col + 1, to_set);
	if (in_gm(adv, row - 1, col - 1) && get(adv, row - 1, col - 1) > 0)
		out += reset_this(adv, row - 1, col - 1, to_set);
	return (out);
}

void	reset_pie(t_game *game, int row, int col)
{
	int r;
	int c;
	int count;

	r = -1;
	c = -1;
	count = 0;
	while (++r < game->pie->row)
	{
		c = -1;
		while (++c < game->pie->col)
		{
			if (game->pie->map[r][c] == -1)
				continue;
			reset_around(game->adv, row + r, col + c, -8);
		}
	}
}

void	reset_val_map_job(t_map *map, int *stop, int val)
{
	int pnt[2];

	pnt[0] = -1;
	while (++pnt[0] < map->row)
	{
		pnt[1] = -1;
		while (++pnt[1] < map->col)
		{
			if (get_pnt(map, pnt) != val + 1)
				continue;
			*stop += reset_around(map, pnt[0], pnt[1], val);
			set_val(map, pnt[0], pnt[1], -1);
		}
	}
}

void	reset_val_map(t_game *game, int row, int col)
{
	int stop;
	int val;

	reset_pie(game, row, col);
	if (game->show_reset_wave_debug)
		debug_value_map_color(game->adv, "");
	stop = 1;
	val = -9;
	while (stop != 0)
	{
		stop = 0;
		reset_val_map_job(game->adv, &stop, val);
		val--;
		if (game->show_reset_wave_debug)
			debug_value_map_color(game->adv, "");
	}
	if (game->show_reset_wave_debug)
		debug_print_fd("-------- END WAVE reSET --------", 1, 0);
}
