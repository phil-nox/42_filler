#include "filler.h"

int place_pie(t_game *game, int row, int col)
{
    int r;
    int c;
    int out;
    int tmp;

    r = -1;
    c = -1;
    out = 0;
    as_map(game->map, game->adv);
    while (++r < game->pie->row)
    {
        c = -1;
        while(++c < game->pie->col)
        {
            if (game->pie->map[r][c] == -1)
                continue;
            tmp = get_val(game->adv, row + r, col + c);
            out += (tmp > 0) ? tmp : 0;
            set_val(game->adv, row + r, col + c, -3);
        }
    }
    return (out);
}


int is_a_place(t_game *game, int row, int col)
{
    int r;
    int c;
    char tmp;
    int count;
    int row_game;
    int col_game;

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
            if (!in_borders(game, row + r, col + c))
                return (-1);
            if (row + r < 0)
                row_game = game->map->row + (row + r);
            else
                row_game = (row + r);
            
            if (col + c < 0)
                col_game = game->map->col + (col + c);
            else
                col_game = (col + c);

            tmp = game->map->map[row_game][col_game];
            if (tmp == 0)
                return (-2);
            if (tmp == -2)
                count += 1;
            if (count > 1)
                return (-3);
        }
    }
    if (count == 0)
        return (0);
    return (1);
}

void calc_decision(t_game *game, t_score *score)
{
    int max_edge;
    int all;
    
    all = game->adv->row * game->adv->col;
    max_edge = (game->adv->row > game->adv->col) ? game->adv->row : game->adv->col;

    score->diff_average = (score->diff_num) ? score->diff_sum / score->diff_num : 0;
    if (score->diff_average != 0 && score->diff_sum - score->diff_average * score->diff_num > score->diff_num / 2)
        score->diff_average += 1;

    score->un_score = (score->unreachable * 1000) / all;
    score->df_score = ((score->diff_average * 1000 * 2) / (max_edge + 1)) * (score->diff_num * 10 / all);

    score->fn_score = (score->df_score > score->un_score) ? score->df_score : score->un_score;
    
    if (game->show_score_debug)
    {
        debug_print("\nplace_score= ", 0, 0); debug_num(score->place_score, 0);
        debug_print("\nun_score= ", 0, 0); debug_num(score->un_score, 0);
        debug_print("\ndf_score= ", 0, 0); debug_num(score->df_score, 0);
        debug_print("\nfn_score= ", 0, 0); debug_num(score->fn_score, 0);
        debug_print("\nunreachable= ", 0, 0); debug_num(score->unreachable, 0);
        debug_print("\ndiff_average= ", 0, 0); debug_num(score->diff_average, 0);
        debug_print("\ndiff_num= ", 0, 0); debug_num(score->diff_num, 0);
        debug_print("\ndiff_sum= ", 0, 0); debug_num(score->diff_sum, 0);
        debug_print("\n$$$$$$$$ SCORE $$$$$$$$", 1, 0);
    }
}

int change_decision(t_score *curr_sc, t_score *aspi_sc)
{
    if (curr_sc->place_score == 0 && aspi_sc->place_score != 0)
        return (1);
    if (aspi_sc->place_score == 0)
        return (0);
    if (curr_sc->fn_score > aspi_sc->fn_score)
        return (0);
    if (curr_sc->fn_score == aspi_sc->fn_score && curr_sc->place_score < aspi_sc->place_score)
        return (0);
    return (1);
}

int find_place(t_game *game)
{
    int row;
    int col;
    int plc;
    int count;
    int min_border_val;
    t_map *map;
    t_map *pie;
    t_score score;
    t_score best_score;

    best_score.place_score = -1;

    map = game->map;
    pie = game->pie;

    count = 0;
    row = - pie->row;
    while(++row < map->row)
    {
        col = - pie->col;
        while(++col < map->row)
        {
            plc = is_a_place(game, row, col);
            if (plc == 1)
            {
                count++;
                score.place_score = place_pie(game, row, col);
                if (game->show_place)
                {
                    debug_value_map_color(game->adv);
                    ft_putstrfile("\n");
                }
                reset_val_map(game, row, col);
                min_border_val = glob_min_val_around(game, game->adv);
                if (min_border_val > -1) // ok
                    set_val_map(game, game->adv, min_border_val);
                if (game->show_reset_wave_debug)
                {
                    ft_putstrfile("\n");
                    debug_value_map_color(game->adv);
                    ft_putstrfile("|||||||| END SET after reSET ||||||||\n");
                }
                diff_val_map(game, min_border_val, &score);
                calc_decision(game, &score);

                if (best_score.place_score == -1 || change_decision(&best_score, &score))
                {
                    best_score = score;
                    game->pnt[0] = row;
                    game->pnt[1] = col;
                }
            }
        }

    }
    if (game->show_place)
        ft_putstrfile("........ END PLACE ........\n");
    return (count);
}