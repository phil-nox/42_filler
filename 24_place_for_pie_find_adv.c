#include "filler.h"

t_score find_place_adv(t_map *org, t_map *map, t_map *pie, t_map *adv)
{
    int pos;
    int res;
    
    t_score score;
    t_score tmp_score;

    pos = -1;
    score.decision = MAX_INT;
    score.pos = -1;
    while (++pos / org->col < org->row)
    {
        res = is_a_place(org->player, map, pie, pos);
        if (res == 1)
        {
            as_map(org, adv);
            tmp_score = get_score(pos, map, pie, adv);

            if (tmp_score.enemy_dist != 0 && tmp_score.decision < score.decision)
            {
                score = tmp_score;
            }
        }
        if (SHOW_FIND_DEBUG)
            find_debug(map, pos, res, score.decision);
        //debug_print(ft_itoa(pos), 0, 1);
        //debug_print(" ", 0, 0);
        //debug_print(ft_itoa(score.pos), 1, 1);
    }
    if (score.pos == -1)
    {
        score = tmp_score;
    }
    if (SHOW_FIND_DEBUG)
    {
        debug_print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>", 1, 0);
        debug_print(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>", 1, 0);
        debug_print(">>>>>>>>>>>>>>>>", 1, 0);
    }
    return (score);
}