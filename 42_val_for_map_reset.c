#include "filler.h"

int reset_around(t_map *map, int pos)
{
    (void)map;
    (void)pos;
    
    return (1);
}

void reset_val_map(t_map *map, int init_val)
{
    int pos;
    int count;
    char to_find;

    count = 1;
    to_find = init_val + 1;

    while (count != 0)
    {
        count = 0;
        pos = -1;
        while (++pos / map->col < map->row)
        {
            if (get_val(map, pos) != to_find)
                continue;
            count += reset_around(map, pos);
        }
        to_find++;
    }
}