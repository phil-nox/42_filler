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

int set_around(t_map *map, int pos, char to_set)
{
    int r;
    int cg;
    int c;
    int out;

    r = row_p(map, pos);
    cg = col_pg(map, pos);
    c = col_p(map, pos);
    out = 0;

    if (cg + 1 < map->col && get_val(map, pos + 1) == '.')
        out += set_val(map, pos + 1, to_set);
    if (cg - 1 >= 0 && get_val(map, pos - 1) == '.')
        out += set_val(map, pos - 1, to_set);
    if (r > 0)
    {
        if (get_val(map, pos - map->col) == '.')
            out += set_val(map, pos - map->col, to_set);
        if (cg + 1 < map->col && get_val(map, pos + 1 - map->col) == '.')
            out += set_val(map, pos + 1 - map->col, to_set);
        if (cg - 1 >= 0 && get_val(map, pos - 1 - map->col) == '.')
            out += set_val(map, pos - 1 - map->col, to_set);
    }
    if (r < map->row - 1)
    {
        if (get_val(map, pos + map->col) == '.')
            out += set_val(map, pos + map->col, to_set);
        if (cg + 1 < map->col && get_val(map, pos + 1 + map->col) == '.')
            out += set_val(map, pos + 1 + map->col, to_set);
        if (cg - 1 >= 0 && get_val(map, pos - 1 + map->col) == '.')
            out += set_val(map, pos - 1 + map->col, to_set);
    }
    return (out);
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
            if (get_val(map, pos) != to_find)
                continue;
            count += set_around(map, pos, val);
        }
        to_find = val;
        val++;
    }
}