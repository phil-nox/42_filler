#include "filler.h"

char get_val(t_map *map, int pos)
{
    return (map->map[row_p(map, pos)][col_p(map, pos)]);
}

int set_val(t_map *map, int pos, char val)
{
    map->map[row_p(map, pos)][col_p(map, pos)] = val;
    return (1);
}

void pre_set_val(t_map *map)
{
    int pos;
    char tmp;

    pos = -1;
    while (++pos / map->col < map->row)
    {
        tmp = get_val(map, pos);
        if (tmp == 'o' || tmp == 'O')
            map->map[row_p(map, pos)][col_p(map, pos)] = 'y';
        if (tmp == 'x' || tmp == 'X')
            map->map[row_p(map, pos)][col_p(map, pos)] = 'z';   
    }
}