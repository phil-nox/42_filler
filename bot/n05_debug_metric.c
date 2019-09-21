/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n05_debug_metric.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:51:15 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:14:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	debug_init_maps(t_game *game, char *begin)
{
	int row;
	int col;

	row = -1;
	while (++row < game->org->row)
	{
		ft_putstrfile(begin);
		col = -1;
		while (++col < game->org->col)
			map_print(game->map->map[row][col]);
		ft_putstrfile(" ");
		col = -1;
		while (++col < game->org->col)
			map_print(game->att->map[row][col]);
		ft_putstrfile(" ");
		col = -1;
		while (++col < game->org->col)
			map_print(game->zon->map[row][col]);
		ft_putstrfile("\n");
	}
	ft_putstrfile("\n");
}

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
			map_print(game->fld->map[row][col]);
		ft_putstrfile(" ");
		col = -1;
		while (++col < game->org->col)
			map_print(game->fre->map[row][col]);
		ft_putstrfile("\n");
	}
	ft_putstrfile("\n");
}

void	score_debug(t_score *score)
{
	debug_print_fd("plce_scr= ", 0, 0);
	debug_num(score->place_score, 0);
	debug_print_fd("\ndiff_num= ", 0, 0);
	debug_num(score->diff_num, 0);
	debug_print_fd("\t\t\t\t\t\t\t\texpn_num= ", 0, 0);
	debug_num(score->expansion_num, 0);
	debug_print_fd("\t\t\t\t\t\t\t\tfrnt_num= ", 0, 0);
	debug_num(score->front_num, 0);
	debug_print_fd("\ndiff_sum= ", 0, 0);
	debug_num(score->diff_sum, 0);
	debug_print_fd("\t\t\t\t\t\t\t\texpn_sum= ", 0, 0);
	debug_num(score->expansion_sum, 0);
	debug_print_fd("\t\t\t\t\t\t\t\tfrnt_sum= ", 0, 0);
	debug_num(score->front_sum, 0);
	debug_print_fd("\n\n\n", 0, 0);
}
