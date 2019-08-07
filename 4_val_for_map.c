#include "filler.h"

char get_val(t_map *map, int pos)
{
    return (map->map[row_p(map, pos)][col_p(map, pos)]);
}

void set_val(t_map *map, int pos, char val)
{
    map->map[row_p(map, pos)][col_p(map, pos)] = val;
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

int is_around(t_map *map, int pos, char to_find)
{
    int r;
    int cg;
    int c;

    r = row_p(map, pos);
    cg = col_pg(map, pos);
    c = col_p(map, pos);

    if (cg + 1 < map->col && get_val(map, pos + 1) == to_find)
        return (1);
    if (cg - 1 >= 0 && get_val(map, pos - 1) == to_find)
        return (1);
    if (r > 0)
    {
        if (get_val(map, pos - map->col) == to_find)
            return (1);
        if (cg + 1 < map->col && get_val(map, pos + 1 - map->col) == to_find)
            return (1);
        if (cg - 1 >= 0 && get_val(map, pos - 1 - map->col) == to_find)
            return (1);
    }
    if (r < map->row - 1)
    {
        if (get_val(map, pos + map->col) == to_find)
            return (1);
        if (cg + 1 < map->col && get_val(map, pos + 1 + map->col) == to_find)
            return (1);
        if (cg - 1 >= 0 && get_val(map, pos - 1 + map->col) == to_find)
            return (1);
    }
    return (0);
}

void set_val_map(t_map *map, int trg_ply)
{
    (void)trg_ply;
    int pos;
    int count;
    char val;
    char to_find;

    count = 1;
    val = 49;
    to_find = (trg_ply == 1) ? 'z' : 'y';
    pre_set_val(map);

    while (count != 0)
    {
        count = 0;
        pos = -1;
        while (++pos / map->col < map->row)
        {
            if (get_val(map, pos) != '.')
                continue;
            if (is_around(map, pos, to_find))
            {
                set_val(map, pos, val);
                count++;
            }
        }
        to_find = val;
        val++;
    }
    if (SHOW_VALUE_MAP)
        debug_value_map(map);
}