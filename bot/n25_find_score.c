/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n25_find_score.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:18:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 21:58:39 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	score_init(t_score *score)
{
	score->expansion_num = 0;
	score->expansion_sum = 0;
	score->expansion_avr = 0;
	score->front_num = 0;
	score->front_sum = 0;
	score->front_avr = 0;
}

void    calc_expansion(t_game *game, t_score *score)
{
    int row;
	int col;
    int val;

	row = -1;
	while (++row < game->org->row)
	{
		col = -1;
		while (++col < game->org->col)
		{
            val = game->fld->map[row][col];
            if (val < 1)
                continue;
            score->expansion_num += 1;
            score->expansion_sum += val;
        }
	}
}

void    calc_front(t_game *game, t_score *score)
{
    int row;
	int col;
    int val;

	row = -1;
	while (++row < game->org->row)
	{
		col = -1;
		while (++col < game->org->col)
		{
            val = game->fre->map[row][col];
            if (val != -7 && val != -6)
                continue;
            score->front_num += 1;
            score->front_sum += -val - 5;
        }
	}
}

void    calc_unreachable(t_game *game, t_score *score)
{
    int max;

    max = (game->map->row > game->map->col) ? game->map->row : game->map->col;

    score->diff_num += score->unreachable;
    score->diff_sum += score->unreachable * max;
}

void    score_debug(t_score *score)
{
    debug_print("plce_scr= ", 0, 0);
	debug_num(score->place_score, 0);
    debug_print("\ndiff_num= ", 0, 0);
	debug_num(score->diff_num, 0);
    debug_print("\t\t\t\t\t\t\t\texpn_num= ", 0, 0);
	debug_num(score->expansion_num, 0);
    debug_print("\t\t\t\t\t\t\t\tfrnt_num= ", 0, 0);
	debug_num(score->front_num, 0);

    debug_print("\ndiff_sum= ", 0, 0);
	debug_num(score->diff_sum, 0);
    debug_print("\t\t\t\t\t\t\t\texpn_sum= ", 0, 0);
	debug_num(score->expansion_sum, 0);
    debug_print("\t\t\t\t\t\t\t\tfrnt_sum= ", 0, 0);
	debug_num(score->front_sum, 0);
    
	debug_print("\n\n\n", 0, 0);
}

void	math_score(t_game *game, t_score *score)
{
    (void)game;
    (void)score;
    
    score_init(score);
    calc_expansion(game, score);
    calc_front(game, score);
    calc_unreachable(game, score);
}