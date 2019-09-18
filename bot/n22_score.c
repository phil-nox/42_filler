/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n22_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:09:41 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 19:36:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	debug_score(t_score *score)
{
	debug_print("place_score= ", 0, 0);
	debug_num(score->place_score, 0);
	debug_print("\nun_score= ", 0, 0);
	debug_num(score->un_score, 0);
	debug_print("\ndf_score= ", 0, 0);
	debug_num(score->df_score, 0);
	debug_print("\nfn_score= ", 0, 0);
	debug_num(score->fn_score, 0);
	debug_print("\nunreachable= ", 0, 0);
	debug_num(score->unreachable, 0);
	debug_print("\ndiff_average= ", 0, 0);
	debug_num(score->diff_average, 0);
	debug_print("\ndiff_num= ", 0, 0);
	debug_num(score->diff_num, 0);
	debug_print("\ndiff_sum= ", 0, 0);
	debug_num(score->diff_sum, 0);
	debug_print("\n$$$$$$$$ SCORE $$$$$$$$", 1, 0);
}

void	debug_score_tab(t_score *score)
{
	debug_print("\t\t\tplace_score= ", 0, 0);
	debug_num(score->place_score, 0);
	debug_print("\n\t\t\tun_score= ", 0, 0);
	debug_num(score->un_score, 0);
	debug_print("\n\t\t\tdf_score= ", 0, 0);
	debug_num(score->df_score, 0);
	debug_print("\n\t\t\tfn_score= ", 0, 0);
	debug_num(score->fn_score, 0);
	debug_print("\n\t\t\tunreachable= ", 0, 0);
	debug_num(score->unreachable, 0);
	debug_print("\n\t\t\tdiff_average= ", 0, 0);
	debug_num(score->diff_average, 0);
	debug_print("\n\t\t\tdiff_num= ", 0, 0);
	debug_num(score->diff_num, 0);
	debug_print("\n\t\t\tdiff_sum= ", 0, 0);
	debug_num(score->diff_sum, 0);
	debug_print("\n\t\t\t$$$$$$$$ SCORE $$$$$$$$", 1, 0);
}

void	calc_decision(t_game *game, t_score *score, char show)
{
	int max_edge;
	int all;

	all = game->adv->row * game->adv->col;
	max_edge = (game->adv->row > game->adv->col) ? game->adv->row \
		: game->adv->col;
	score->diff_average = (score->diff_num) ? \
		score->diff_sum / score->diff_num : 0;
	if (score->diff_average != 0
		&& score->diff_sum - score->diff_average * \
		score->diff_num > score->diff_num / 2)
		score->diff_average += 1;
	score->un_score = (score->unreachable * 1000) / all;
	score->df_score = ((score->diff_average * 1000 * 2) / (max_edge + 1)) * \
		(score->diff_num * 10 / all);
	score->fn_score = (score->df_score > score->un_score) ? \
		score->df_score : score->un_score;
	score->fn_score = (score->fn_score < 100) ? 0 : score->fn_score;
	if (show)
		debug_score_tab(score);
	if (!show && game->show_score_debug)
		debug_score(score);
}

int		change_decision(t_score *curr_sc, t_score *aspi_sc)
{
	if (curr_sc->place_score == 0 && aspi_sc->place_score != 0)
		return (1);
	if (aspi_sc->place_score == 0)
		return (0);
	if (curr_sc->fn_score > aspi_sc->fn_score)
		return (0);
	if (curr_sc->fn_score == aspi_sc->fn_score
		&& curr_sc->place_score < aspi_sc->place_score)
		return (0);
	return (1);
}
