#include "filler.h"

/*
void score_debug(t_map *map, int pos, t_score *score)
{
	debug_print("pos= ", 0, 0);
	debug_print(ft_itoa(pos), 0, 1);
	debug_print(" [", 0, 0);
	debug_print(ft_itoa(row_p(map, pos)), 0, 1);
	debug_print(" ,", 0, 0);
	debug_print(ft_itoa(col_p(map, pos) - SHIFT_M), 0, 1);
	debug_print("]\t enemy_dist= ", 0, 0);
	debug_print(ft_itoa(score->enemy_dist), 0, 1);
	debug_print(" diff_map= ", 0, 0);
	debug_print(ft_itoa(score->diff_map), 0, 1);
	debug_print(" isolated= ", 0, 0);
	debug_print(ft_itoa(score->isolated), 0, 1);
	debug_print(" decision= ", 0, 0);
	debug_print(ft_itoa(score->decision), 1, 1);
}

void send_debug_adv(t_map *map, t_score *score)
{
	debug_print(" => SEND <= ", 0, 0);
	score_debug(map, score->pos, score);
}
*/