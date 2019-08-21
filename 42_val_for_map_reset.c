#include "filler.h"

int reset_this(t_game *game, int row, int col, int to_set)
{
    int cur;

    cur = get_val(game->adv, row, col);
    if (cur < 1)
        return (0);

    if (in_borders(game->adv, row, col + 1) && get_val(game->adv, row, col + 1) == cur - 1)
        return (0);
    if (in_borders(game->adv, row, col - 1) && get_val(game->adv, row, col - 1) == cur - 1)
        return (0);
    if (in_borders(game->adv, row + 1, col) && get_val(game->adv, row + 1, col) == cur - 1)
        return (0);
    if (in_borders(game->adv, row - 1, col) && get_val(game->adv, row - 1, col) == cur - 1)
        return (0);

    
    if (in_borders(game->adv, row + 1, col + 1) && get_val(game->adv, row + 1, col + 1) == cur - 1)
        return (0);
    if (in_borders(game->adv, row + 1, col - 1) && get_val(game->adv, row + 1, col - 1) == cur - 1)
        return (0);
    if (in_borders(game->adv, row - 1, col + 1) && get_val(game->adv, row - 1, col + 1) == cur - 1)
        return (0);
    if (in_borders(game->adv, row - 1, col - 1) && get_val(game->adv, row - 1, col - 1) == cur - 1)
        return (0);

    set_val(game->adv, row, col, to_set);
    return (1);
}

int reset_around(t_game *game, int row, int col, int to_set)
{
    int out;

    out = 0;
    if (in_borders(game->adv, row, col + 1) && get_val(game->adv, row, col + 1) > 0)
        out += reset_this(game, row, col + 1, to_set);
    if (in_borders(game->adv, row, col - 1) && get_val(game->adv, row, col - 1) > 0)
        out += reset_this(game, row, col - 1, to_set);
    if (in_borders(game->adv, row + 1, col) && get_val(game->adv, row + 1, col) > 0)
        out += reset_this(game, row + 1, col, to_set);
    if (in_borders(game->adv, row - 1, col) && get_val(game->adv, row - 1, col) > 0)
        out += reset_this(game, row - 1, col, to_set);

    if (in_borders(game->adv, row + 1, col + 1) && get_val(game->adv, row + 1, col + 1) > 0)
        out += reset_this(game, row + 1, col + 1, to_set);
    if (in_borders(game->adv, row + 1, col - 1) && get_val(game->adv, row + 1, col - 1) > 0)
        out += reset_this(game, row + 1, col - 1, to_set);
    if (in_borders(game->adv, row - 1, col + 1) && get_val(game->adv, row - 1, col + 1) > 0)
        out += reset_this(game, row - 1, col + 1, to_set);
    if (in_borders(game->adv, row - 1, col - 1) && get_val(game->adv, row - 1, col - 1) > 0)
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
            reset_around(game, row + r,  col + c, -5);
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
        debug_value_map_color(game->adv);
    stop = 1;
    val = -6;
    while (stop != 0)
    {
        stop = 0;
        pnt[0] = -1;
        while (++pnt[0] < game->adv->row)
        {
            pnt[1] = -1;
            while (++pnt[1] < game->adv->col)
            {
                if (get_val_pnt(game->adv, pnt) != val + 1)
                    continue;
                stop += reset_around(game, pnt[0], pnt[1], val);
                set_val(game->adv, pnt[0], pnt[1], -1);
            }
        }
        val--;
        if (game->show_reset_wave_debug)
            debug_value_map_color(game->adv);
    }
    if (game->show_reset_wave_debug)
        debug_print("-------- END WAVE reSET --------", 1, 0);
}
