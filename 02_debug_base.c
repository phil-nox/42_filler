#include "filler.h"

void find_debug(t_map *map, int pos, int res, int tmp_score)
{
	if (SHOW_FIND_DEBUG != 1 && res != 1)
		return ;
	debug_print(ft_itoa(pos), 0, 1);
	debug_print("\t ", 0, 0);
	debug_print(ft_itoa(row_p(map, pos)), 0, 1);
	debug_print(" ", 0, 0);
	debug_print(ft_itoa(col_p(map, pos) - SHIFT_M), 0, 1);
	if(res == -1)
		debug_print("\t- out border", 1, 0);
	if(res == -2)
		debug_print("\t- enemy", 1, 0);
	if(res == -3)
		 debug_print("\t- more then one", 1, 0);
	 if(res == 0)
		 debug_print("\t- void", 1, 0);
	 if(res == 1)
	 {
		debug_print("\t- <== good ", 0, 0);
		debug_print(ft_itoa(tmp_score), 1, 1);
	 }
	 if(res == 2)
	 {
		debug_print("\t- => SEND ", 0, 0);
		debug_print(ft_itoa(tmp_score), 1, 1);
	 }
}

void send_debug(t_map *map, int pos, int tmp_score)
{
	debug_print(ft_itoa(pos), 0, 1);
	debug_print("\t ", 0, 0);
	debug_print(ft_itoa(row_p(map, pos)), 0, 1);
	debug_print(" ", 0, 0);
	debug_print(ft_itoa(col_pg(map, pos)), 0, 1);
	debug_print("\t- => SEND ", 0, 0);
	debug_print(ft_itoa(tmp_score), 1, 1);
}

void debug_value_map(t_map *map)
{
	int idx;

	idx = -1;
	while (++idx < map->row)
		debug_print(map->map[idx], 1, 0);
	 debug_print("\n", 1, 0);
}