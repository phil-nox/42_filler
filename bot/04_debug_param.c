#include "filler.h"

void debug_set(t_map *map) 
{
	ft_putstrfile("\n");
    debug_value_map_color(map, "");
    ft_putstrfile("|||||||| END SET ||||||||\n");
}

void debug_place(t_map *map) 
{
	ft_putstrfile("\n");
    debug_value_map_color(map, "");
	ft_putstrfile("........ END PLACE ........\n");
}

void debug_reset(t_map *map) 
{
	ft_putstrfile("\n");
    debug_value_map_color(map, "");
	ft_putstrfile("|||||||| END SET after reSET ||||||||\n");
}

void debug_diff(t_map *map)
{
	debug_value_map_color(map, "");
    debug_print("@@@@@@@@ END DIFF @@@@@@@@", 1, 0);
}

void debug_att(t_map *map)
{
	debug_value_map_color(map, "");
    debug_print("^^^^^^^^ END ATT ^^^^^^^^", 1, 0);
}

void debug_metric (t_game *game, char *begin)
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