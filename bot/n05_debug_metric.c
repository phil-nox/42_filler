/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n05_debug_metric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:51:15 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 15:54:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	debug_metric(t_game *game, char *begin)
{
	int row;
	int col;

	row = -1;
	while (++row < game->org->row)
	{
		ft_putstrfile(begin);
		col = -1;
		while (++col < game->org->col)
			map_print(game->adv->map[row][col]);
		ft_putstrfile(" ");
		col = -1;
		while (++col < game->org->col)
			map_print(game->fre->map[row][col]);
		ft_putstrfile(" ");
		col = -1;
		while (++col < game->org->col)
			map_print(game->fld->map[row][col]);
		ft_putstrfile("\n");
	}
	ft_putstrfile("\n");
}