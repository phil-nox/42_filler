#include "filler.h"

int row_p(t_map *map, int pos)
{
    return (pos / map->col);
}

int col_p(t_map *map, int pos)
{
    return (pos % map->col + SHIFT_M);
}

int not_in_borders(t_map *map, int pos, int t_r, int t_c)
{
    if (row_p(map, pos) + t_r >= map->row)
        return (1);
    if (col_p(map, pos) - SHIFT_M + t_c >= map->col)
        return (1);
    return (0);
}

int is_enemy(int player, char trg)
{
    if (player == 1 && (trg == 'x' || trg == 'X')) 
        return (1);
    if (player == 2 && (trg == 'o' || trg == 'O')) 
        return (1);  
    return (0);
}

void is_ally_inc(int player, char trg, int *count)
{
    if (player == 1 && (trg == 'o' || trg == 'O')) 
        (*count)++;
    if (player == 2 && (trg == 'x' || trg == 'X')) 
        (*count)++;  
}

int is_a_place(int player, t_map *map, t_map *pie, int pos)
{
    int r;
    int c;
    char tmp;
    int count;

    r = -1;
    c = -1;
    count = 0;
    while (++r < pie->row)
    {
        c = -1;
        while(++c < pie->col)
        {
            if (pie->map[r][c] == '.')
                continue;
            if (not_in_borders(map, pos, r, c))
                return (-1);
            tmp = map->map[row_p(map, pos) + r][col_p(map, pos) + c];
            if (is_enemy(player, tmp))
                return (-2);
            is_ally_inc(player, tmp, &count);
            if (count > 1)
                return (-3);
        }
    }
    if (count == 0)
        return (0);
    return (1);
}

void find_place(int player, t_map *map, t_map *pie)
{
    int pos;
    int res;

    pos = -1;
    while (++pos / map->col < map->row)
    {
        res = is_a_place(player, map, pie, pos);
        if (SHOW_FIND_DEBUG)
            find_debug(map, pos, res);
    }
}