#include "filler.h"


void shadow_math(t_game *game, t_score *score, int row, int col) 
{
    int min_border_val;

    as_map(game->map, game->adv);
    score->place_score = place_pie(game, game->adv, row, col);
    if (game->show_place)
        debug_place(game->adv); 
    reset_val_map(game, row, col);
    while ((min_border_val = glob_min_val_around(game, game->adv)) != -1)
        set_val_map(game, game->adv, min_border_val);
    if (game->show_reset_wave_debug)
        debug_reset(game->adv);
    diff_val_map(game, min_border_val, score, 0);

    as_map(game->att, game->fld);
    place_pie(game, game->fld, row, col);
    set_val_map_force(game, game->fld, -3);
    diff_for_field(game->fld, game->att);
    field_and_shadow(game->fld, game->adv);
    if (game->show_att_debug)
        debug_att(game->fld);
}


int find_place(t_game *game)
{
    int row;
    int col;
    int plc;
    int count;
    t_score score;

    game->best_score.place_score = -1;
    count = 0;

    // copie org to map
    // set val for map for all case of placement
    as_map(game->org, game->map);
    set_val_map(game, game->map, 0);

    as_map(game->org, game->att);
    set_val_map(game, game->att, -2);
    if (game->show_att_debug)
        debug_att(game->att);

    row = - game->pie->row;
    while(++row < game->map->row)
    {
        col = - game->pie->col;
        while(++col < game->map->col)
        {
            plc = is_a_place(game, game->map, row, col);
            if (plc == 1)
            {
                count++;
                shadow_math(game, &score, row, col);
                calc_decision(game, &score, 0);

                if (game->best_score.place_score == -1 || change_decision(&(game->best_score), &score))
                {
                    game->best_score = score;
                    game->pnt[0] = row;
                    game->pnt[1] = col;
                }
            }
        }

    }
    return (count);
}

int find_first_place(t_game *game, t_map *map)
{
    int row;
    int col;

    row = - game->pie->row;
    while(++row < map->row)
    {
        col = - game->pie->col;
        while(++col < map->col)
        {
            if (is_a_place(game, map, row, col) == 1)
            {
                game->pnt[0] = row;
                game->pnt[1] = col;
                return (1);
            }
        }
    }
    return (0);
}