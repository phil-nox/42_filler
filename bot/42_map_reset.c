#include "filler.h"

int reset_this(t_game *game, int row, int col, int to_set)
{
    int cur;

    cur = get(game->adv, row, col);
    if (cur < 1)
        return (-1);

    if (in_borders(game, row, col + 1) && get(game->adv, row, col + 1) == cur - 1)
        return (-1);
    if (in_borders(game, row, col - 1) && get(game->adv, row, col - 1) == cur - 1)
        return (-1);
    if (in_borders(game, row + 1, col) && get(game->adv, row + 1, col) == cur - 1)
        return (-1);
    if (in_borders(game, row - 1, col) && get(game->adv, row - 1, col) == cur - 1)
        return (-1);
    if (in_borders(game, row + 1, col + 1) && get(game->adv, row + 1, col + 1) == cur - 1)
        return (-1);
    if (in_borders(game, row + 1, col - 1) && get(game->adv, row + 1, col - 1) == cur - 1)
        return (-1);
    if (in_borders(game, row - 1, col + 1) && get(game->adv, row - 1, col + 1) == cur - 1)
        return (-1);
    if (in_borders(game, row - 1, col - 1) && get(game->adv, row - 1, col - 1) == cur - 1)
        return (-1);
    set_val(game->adv, row, col, to_set);
    return (cur);
}

int reset_around(t_game *game, int row, int col, int to_set)
{
    int out;

    out = 0;
    if (in_borders(game, row, col + 1) && get(game->adv, row, col + 1) > 0)
        out += reset_this(game, row, col + 1, to_set);
    if (in_borders(game, row, col - 1) && get(game->adv, row, col - 1) > 0)
        out += reset_this(game, row, col - 1, to_set);
    if (in_borders(game, row + 1, col) && get(game->adv, row + 1, col) > 0)
        out += reset_this(game, row + 1, col, to_set);
    if (in_borders(game, row - 1, col) && get(game->adv, row - 1, col) > 0)
        out += reset_this(game, row - 1, col, to_set);

    if (in_borders(game, row + 1, col + 1) && get(game->adv, row + 1, col + 1) > 0)
        out += reset_this(game, row + 1, col + 1, to_set);
    if (in_borders(game, row + 1, col - 1) && get(game->adv, row + 1, col - 1) > 0)
        out += reset_this(game, row + 1, col - 1, to_set);
    if (in_borders(game, row - 1, col + 1) && get(game->adv, row - 1, col + 1) > 0)
        out += reset_this(game, row - 1, col + 1, to_set);
    if (in_borders(game, row - 1, col - 1) && get(game->adv, row - 1, col - 1) > 0)
        out += reset_this(game, row - 1, col - 1, to_set);
    return (out);
}

void reset_pie(t_game *game, int row, int col)
{
    int r;
    int c;
    int count;

    r = -1;
    c = -1;
    count = 0;
    while (++r < game->pie->row)
    {
        c = -1;
        while(++c < game->pie->col)
        {
            if (game->pie->map[r][c] == -1)
                continue;
            reset_around(game, row + r,  col + c, -8);
        }
    }
}

void reset_val_map(t_game *game, int row, int col)
{
    int pnt[2];
    int stop;
    int val;

    reset_pie(game, row, col);
    if (game->show_reset_wave_debug)
        debug_value_map_color(game->adv, "");
    stop = 1;
    val = -9;
    while (stop != 0)
    {
        stop = 0;
        pnt[0] = -1;
        while (++pnt[0] < game->adv->row)
        {
            pnt[1] = -1;
            while (++pnt[1] < game->adv->col)
            {
                if (get_pnt(game->adv, pnt) != val + 1)
                    continue;
                stop += reset_around(game, pnt[0], pnt[1], val);
                set_val(game->adv, pnt[0], pnt[1], -1);
            }
        }
        val--;
        if (game->show_reset_wave_debug)
            debug_value_map_color(game->adv, "");
    }
    if (game->show_reset_wave_debug)
        debug_print("-------- END WAVE reSET --------", 1, 0);
}

void diff_val_map(t_game *game, int min_border_val, t_score *score, char show)
{
    int row;
    int col;
    int val_adv;
    int val_map;

    score->unreachable = 0;
    score->diff_sum = 0;
    score->diff_num = 0;
    score->diff_average = 0;

    row = -1;
    while (++row < game->adv->row)
    {
        col = -1;
        while (++col < game->adv->col)
        {
            val_map = get(game->map, row, col);
            val_adv = get(game->adv, row, col);
            if (val_adv == -1 && val_map != -1)
            {
                score->unreachable += 1;
                continue;
            }

            if (val_map < 1 || val_adv < 1)
                continue;
            
            if (val_adv <= min_border_val || val_map == val_adv)
            {
                set_val(game->adv, row, col, -8);
                continue;
            }
            
            set_val(game->adv, row, col, val_adv - val_map);
            score->diff_num += 1;
            score->diff_sum += val_adv - val_map;
        }
    }
    if (show)
        debug_value_map_color(game->adv, "\t\t\t");
    if (!show && game->show_diff_debug)
        debug_diff(game->adv);
}