/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n77_human_over_roll.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:10:36 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/19 14:02:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

void	find_over_down(t_game *game)
{
	int		row;

	row = -game->pie->row;
	while (++row < game->map->row)
	{
		if (is_a_place(game, game->map, row, game->pnt[1]) != -1)
		{
			game->pnt[0] = row;
			return ;
		}
	}
}

void	find_over_up(t_game *game)
{
	int		row;

	row = game->map->row;
	while (--row > -game->pie->row)
	{
		if (is_a_place(game, game->map, row, game->pnt[1]) != -1)
		{
			game->pnt[0] = row;
			return ;
		}
	}
}

void	find_over_right(t_game *game)
{
	int		col;

	col = -game->pie->col;
	while (++col < game->map->col)
	{
		if (is_a_place(game, game->map, game->pnt[0], col) != -1)
		{
			game->pnt[1] = col;
			return ;
		}
	}
}

void	find_over_left(t_game *game)
{
	int		col;

	col = game->map->col;
	while (--col > -game->pie->col)
	{
		if (is_a_place(game, game->map, game->pnt[0], col) != -1)
		{
			game->pnt[1] = col;
			return ;
		}
	}
}

void	over_roll(t_game *game, char input, int row, int col)
{
	game->pnt[0] = row;
	game->pnt[1] = col;
	if (input == 's')
		find_over_down(game);
	if (input == 'w')
		find_over_up(game);
	if (input == 'd')
		find_over_right(game);
	if (input == 'a')
		find_over_left(game);
}
