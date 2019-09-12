/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n43_map_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:21:33 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 18:54:12 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	diff_val_map_init(t_score *score)
{
	score->unreachable = 0;
	score->diff_sum = 0;
	score->diff_num = 0;
	score->diff_average = 0;
}

int		diff_val_map_skip(int val_map, int val_adv, t_score *score)
{
	if (val_adv == -1 && val_map != -1)
	{
		score->unreachable += 1;
		return (1);
	}
	if (val_map < 1 || val_adv < 1)
		return (1);
	return (0);
}

void	diff_val_job(t_game *game, int min_val, t_score *score)
{
	int row;
	int col;
	int val_adv;
	int val_map;

	row = -1;
	while (++row < game->adv->row)
	{
		col = -1;
		while (++col < game->adv->col)
		{
			val_map = get(game->map, row, col);
			val_adv = get(game->adv, row, col);
			if (diff_val_map_skip(val_map, val_adv, score))
				continue;
			if (val_adv <= min_val || val_map == val_adv)
			{
				set_val(game->adv, row, col, -8);
				continue;
			}
			set_val(game->adv, row, col, val_adv - val_map);
			score->diff_num += 1;
			score->diff_sum += val_adv - val_map;
		}
	}
}

void	diff_val_map(t_game *game, int min_val, t_score *score, char show)
{
	diff_val_map_init(score);
	diff_val_job(game, min_val, score);
	if (show)
		debug_value_map_color(game->adv, "\t\t\t");
	if (!show && game->show_diff_debug)
		debug_diff(game->adv);
}
