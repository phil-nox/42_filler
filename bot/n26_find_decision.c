/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n26_find_decision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 22:09:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
# define EPS_FRONT 10
# define EPS_SHADW 10

int		do_choice(t_game *game)
{
	if (game->show_general_debug)
	{
		score_debug(&(game->best_score));
		debug_print("👆👆👆👆👆👆👆👆", 1, 0);
	}
	return (1);
}

int		math_decision(t_game *game, t_score *score)
{
	int frnt_sum_del;
	int shdw_sun_del;

	frnt_sum_del = score->front_sum - game->best_score.front_sum;
	if (frnt_sum_del > EPS_FRONT)
		return (do_choice(game));
	if (frnt_sum_del < -EPS_FRONT)
		return (0);

	shdw_sun_del = score->diff_sum - game->best_score.diff_sum;
	if (shdw_sun_del > EPS_SHADW)
		return (do_choice(game));
	if (shdw_sun_del < -EPS_SHADW)
		return (0);
	if (frnt_sum_del > 0)
		return (do_choice(game));
	return (0);
}