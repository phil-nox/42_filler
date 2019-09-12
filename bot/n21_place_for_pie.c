/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n21_place_for_pie.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:54:57 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 17:41:37 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Uncomment this line and human model
** will start work with a bug of the borders,
** but bot will start doing Segfault
**  //if (row <= - game->pie->row || col <= - game->pie->col
**    //|| row >= game->map->row || col >= game->map->col)
*/

int	in_borders(t_game *game, int row, int col)
{
	if (row < 0 || col < 0 || row >= game->map->row || col >= game->map->col)
		return (0);
	return (1);
}

int	place_pie(t_game *game, t_map *map, int row, int col)
{
	int r;
	int c;
	int out;
	int tmp;

	r = -1;
	c = -1;
	out = 0;
	while (++r < game->pie->row)
	{
		c = -1;
		while (++c < game->pie->col)
		{
			if (game->pie->map[r][c] == -1)
				continue;
			tmp = get(map, row + r, col + c);
			out += (tmp > 0) ? tmp : 0;
			set_val(map, row + r, col + c, -3);
		}
	}
	return (out);
}

int	is_a_place(t_game *game, t_map *map, int row, int col)
{
	int		r;
	int		c;
	char	tmp;
	int		count;

	r = -1;
	count = 0;
	while (++r < game->pie->row)
	{
		c = -1;
		while (++c < game->pie->col)
		{
			if (game->pie->map[r][c] == -1)
				continue;
			if (!in_borders(game, row + r, col + c))
				return (-1);
			tmp = map->map[row + r][col + c];
			if (tmp == -2)
				count += 1;
			if (count > 1 || tmp == 0)
				return ((count > 1) ? -3 : -2);
		}
	}
	return ((count == 0) ? 0 : 1);
}
