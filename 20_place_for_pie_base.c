#include "filler.h"

int row_p(t_map *map, int pos)
{
    return (pos / map->col);
}

int col_p(t_map *map, int pos)
{
    return (pos % map->col + SHIFT_M);
}

int col_pg(t_map *map, int pos)
{
    return (pos % map->col);
}

int not_in_borders(t_map *map, int pos, int t_r, int t_c)
{
    if (row_p(map, pos) + t_r >= map->row)
        return (1);
    if (col_p(map, pos) - SHIFT_M + t_c >= map->col)
        return (1);
    return (0);
}