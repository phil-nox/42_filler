/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n40_map_set_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:28:34 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 17:41:37 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	get(t_map *map, int row, int col)
{
	return (map->map[row][col]);
}

int	get_pnt(t_map *map, int pnt[2])
{
	return (get(map, pnt[0], pnt[1]));
}

int	set_val(t_map *map, int row, int col, int val)
{
	int row_game;
	int col_game;

	if (row < 0)
		row_game = map->row + row;
	else
		row_game = row % map->row;
	if (col < 0)
		col_game = map->col + col;
	else
		col_game = col % map->col;
	map->map[row_game][col_game] = val;
	return (1);
}
