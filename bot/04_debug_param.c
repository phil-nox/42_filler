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