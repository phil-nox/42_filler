#include "filler.h"

int get_val(t_map *map, int row, int col)
{
    return (map->map[row][col]);
}

int get_val_pnt(t_map *map, int pnt[2])
{
    return (get_val(map, pnt[0], pnt[1]));
}

int in_borders(t_map *map, int row, int col)
{
    if (row < 0 || col < 0 || row >= map->row || col >= map->col)
        return (0);
    return (1);
}

int set_val(t_map *map, int row, int col, int val)
{
    map->map[row][col] = val;
    return (1);
}

int set_around(t_map *map, int pnt[2], int to_set)
{
    int out;
    int row;
    int col;

    row = pnt[0];
    col = pnt[1];
    out = 0;

    if (in_borders(map, row, col + 1) && get_val(map, row, col + 1) == -1) //"."
        out += set_val(map, row, col + 1, to_set);
    if (in_borders(map, row, col - 1) && get_val(map, row, col - 1) == -1)
        out += set_val(map, row, col - 1, to_set);
    if (in_borders(map, row + 1, col) && get_val(map, row + 1, col) == -1)
        out += set_val(map, row + 1, col, to_set);
    if (in_borders(map, row - 1, col) && get_val(map, row - 1, col) == -1)
        out += set_val(map, row - 1, col, to_set);
    return (out);
}

void set_val_map(t_game *game, t_map *map, int to_find)
{
    int pnt[2];
    int stop;
    
    stop = 1;
    while (stop != 0)
    {
        stop = 0;
        pnt[0] = -1;
        while (++pnt[0] < map->row)
        {
            pnt[1] = -1;
            while (++pnt[1] < map->col)
            {
                if (get_val_pnt(map, pnt) != to_find) // 0
                    continue;
                stop += set_around(map, pnt, to_find + 1);
            }
        }
        to_find++;
        if (game->show_set_wave_debug)
            debug_value_map_color(map);
    }
    if (game->show_set_wave_debug)
        debug_print("|||||||| END SET ||||||||", 1, 0);
}