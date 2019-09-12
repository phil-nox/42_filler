#include "filler.h"

int is_around(t_map *map, int pos, char to_find)
{
    int r;
    int cg;
    int c;

    r = row_p(map, pos);
    cg = col_pg(map, pos);
    c = col_p(map, pos);

    if (cg + 1 < map->col && get(map, pos + 1) == to_find)
        return (1);
    if (cg - 1 >= 0 && get(map, pos - 1) == to_find)
        return (1);
    if (r > 0)
    {
        if (get(map, pos - map->col) == to_find)
            return (1);
        if (cg + 1 < map->col && get(map, pos + 1 - map->col) == to_find)
            return (1);
        if (cg - 1 >= 0 && get(map, pos - 1 - map->col) == to_find)
            return (1);
    }
    if (r < map->row - 1)
    {
        if (get(map, pos + map->col) == to_find)
            return (1);
        if (cg + 1 < map->col && get(map, pos + 1 + map->col) == to_find)
            return (1);
        if (cg - 1 >= 0 && get(map, pos - 1 + map->col) == to_find)
            return (1);
    }
    return (0);
}
