#include "filler.h"

int set_around_force(t_game *game, t_map *map, int pnt[2], int to_set)
{
    int out;
    int row;
    int col;

    row = pnt[0];
    col = pnt[1];
    out = 0;

    if (in_borders(game, row, col + 1) && (get_val(map, row, col + 1) == -1 || get_val(map, row, col + 1) > to_set)) //"."
        out += set_val(map, row, col + 1, to_set);
    if (in_borders(game, row, col - 1) && (get_val(map, row, col - 1) == -1 || get_val(map, row, col - 1) > to_set))
        out += set_val(map, row, col - 1, to_set);
    if (in_borders(game, row + 1, col) && (get_val(map, row + 1, col) == -1 || get_val(map, row + 1, col) > to_set))
        out += set_val(map, row + 1, col, to_set);
    if (in_borders(game, row - 1, col) && (get_val(map, row - 1, col) == -1 || get_val(map, row - 1, col) > to_set))
        out += set_val(map, row - 1, col, to_set);

    
    if (in_borders(game, row + 1, col + 1) && (get_val(map, row + 1, col + 1) == -1 || get_val(map, row + 1, col + 1) > to_set))
        out += set_val(map, row + 1, col + 1, to_set);
    if (in_borders(game, row + 1, col - 1) && (get_val(map, row + 1, col - 1) == -1 || get_val(map, row + 1, col - 1) > to_set))
        out += set_val(map, row + 1, col - 1, to_set);
    if (in_borders(game, row - 1, col + 1) && (get_val(map, row - 1, col + 1) == -1 || get_val(map, row - 1, col + 1) > to_set))
        out += set_val(map, row - 1, col + 1, to_set);
    if (in_borders(game, row - 1, col - 1) && (get_val(map, row - 1, col - 1) == -1 || get_val(map, row - 1, col - 1) > to_set))
        out += set_val(map, row - 1, col - 1, to_set);
    return (out);
}


int set_val_map_force(t_game *game, t_map *map, int to_find)
{
    int pnt[2];
    int stop;
    int how_far;
    int to_set;
    
    stop = 1;
    to_set = (to_find > 0) ? to_find + 1 : 1;
    how_far = 0;
    while (stop != 0)
    {
        how_far += 1;
        stop = 0;
        pnt[0] = -1;
        while (++pnt[0] < map->row)
        {
            pnt[1] = -1;
            while (++pnt[1] < map->col)
            {
                if (get_val_pnt(map, pnt) != to_find) // 0
                    continue;
                stop += set_around_force(game, map, pnt, to_set);
            }
        }
        to_find = to_set++;
        if (game->show_set_wave_debug)
            debug_value_map_color(map, "");
    }
    if (game->show_set_wave_debug)
        debug_print("|||||||| END WAVE SET ||||||||", 1, 0);
    if (game->show_set_debug) 
        debug_set(map);
    return (how_far);
}

void diff_for_field(t_map *fld, t_map *att)
{
    int row;
    int col;
    int tmp_fld;
    int tmp_att;

    row = -1;
    while (++row < fld->row)
    {
        col = -1;
        while (++col < fld->col)
        {
            tmp_fld = get_val(fld, row, col);
            if (tmp_fld < 1)
                continue;
            tmp_att = get_val(att, row, col);
            if (tmp_att != tmp_fld)
                set_val(fld, row, col, tmp_att - tmp_fld);
            else
                set_val(fld, row, col, -8);
        }
    }
}

void field_and_shadow(t_map *fld, t_map *adv)
{
    int row;
    int col;
    int tmp_fld;
    int tmp_adv;

    row = -1;
    while (++row < fld->row)
    {
        col = -1;
        while (++col < fld->col)
        {
            tmp_fld = get_val(fld, row, col);
            tmp_adv = get_val(adv, row, col);
            if (tmp_adv < 1 && tmp_fld < 1)
                continue;
            if (tmp_adv > 0)
            {
                set_val(fld, row, col, tmp_adv);
                continue;
            }
            if (tmp_fld > 0)
                set_val(fld, row, col, -4);
        }
    }
}