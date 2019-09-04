#include "filler.h"

void calc_decision(t_game *game, t_score *score, char show)
{
    int max_edge;
    int all;
    
    all = game->adv->row * game->adv->col;
    max_edge = (game->adv->row > game->adv->col) ? game->adv->row : game->adv->col;

    score->diff_average = (score->diff_num) ? score->diff_sum / score->diff_num : 0;
    if (score->diff_average != 0 
        && score->diff_sum - score->diff_average * score->diff_num > score->diff_num / 2)
        score->diff_average += 1;

    score->un_score = (score->unreachable * 1000) / all;
    score->df_score = ((score->diff_average * 1000 * 2) / (max_edge + 1)) * (score->diff_num * 10 / all);

    score->fn_score = (score->df_score > score->un_score) ? score->df_score : score->un_score;
    score->fn_score = (score->fn_score < 100) ? 0 : score->fn_score;
    
    if (show)
    {
        debug_print("\t\t\tplace_score= ", 0, 0); debug_num(score->place_score, 0);
        debug_print("\n\t\t\tun_score= ", 0, 0); debug_num(score->un_score, 0);
        debug_print("\n\t\t\tdf_score= ", 0, 0); debug_num(score->df_score, 0);
        debug_print("\n\t\t\tfn_score= ", 0, 0); debug_num(score->fn_score, 0);
        debug_print("\n\t\t\tunreachable= ", 0, 0); debug_num(score->unreachable, 0);
        debug_print("\n\t\t\tdiff_average= ", 0, 0); debug_num(score->diff_average, 0);
        debug_print("\n\t\t\tdiff_num= ", 0, 0); debug_num(score->diff_num, 0);
        debug_print("\n\t\t\tdiff_sum= ", 0, 0); debug_num(score->diff_sum, 0);
        debug_print("\n\t\t\t$$$$$$$$ SCORE $$$$$$$$", 1, 0);
    }

    if (!show && game->show_score_debug)
    {
        debug_print("place_score= ", 0, 0); debug_num(score->place_score, 0);
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
    // minor case
    return (1);
}

void shadow_calc(t_game *game)
{
    int min_border_val;
    t_score tmp;
    
    if (is_a_place(game, game->map, game->pnt[0], game->pnt[1]) != 1)
        return ;
    as_map(game->map, game->adv);
    place_pie(game, game->adv, game->pnt[0], game->pnt[1]);
    reset_val_map(game, game->pnt[0], game->pnt[1]);
    while ((min_border_val = glob_min_val_around(game, game->adv)) != -1)
        set_val_map(game, game->adv, min_border_val);
    calc_decision(game, &(game->best_score), 1);
    diff_val_map(game, min_border_val, &tmp, 1);
}