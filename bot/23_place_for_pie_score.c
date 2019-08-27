#include "filler.h"

/*
int calc_score(t_map *map, t_map *pie, int pos)
{
    int score;
    int r;
    int c;
    char tmp;

    score = 0;
    r = -1;
    c = -1;
    while (++r < pie->row)
    {
        c = -1;
        while(++c < pie->col)
        {
            if (pie->map[r][c] == '.')
                continue;
            tmp = map->map[row_p(map, pos) + r][col_p(map, pos) + c];
            if (tmp == 'y' || tmp == 'z' || tmp == '.')
                continue;
            score += tmp - 48;
        }
    }
    return (score);
}

int calc_iso_score(t_map *map, t_map *adv)
{
    int pos;
    int out;

    pos = -1;
    out = 0;
    while (++pos / map->col < map->row)
        if(get_val(adv, pos) == '.' && get_val(map, pos) != '.')
            out += 1;
        
    return (out);
}

int calc_diff_score(t_map *map, t_map *adv)
{
    int pos;
    int ad;
    int ma;
    int out;

    pos = -1;
    out = 0;
    while (++pos / map->col < map->row)
    {
        ad = get_val(adv, pos);
        ma = get_val(map, pos);

        if (SHOW_VALUE_MAP_ADV == 2)
        {
            if(ad > 48 && ad < 119 && ma > 48 && ma < 119)
            {
                if (ad == ma)
                    set_val(adv, pos, 48);
                else
                {
                    set_val(adv, pos, ad - ma + 48);
                    out += ad - ma;
                } 
            }
        }
        else
        {
            if(ad > 48 && ad < 119 && ma > 48 && ma < 119 && ad !=ma)
                out += ad - ma;
        }
    }   
    return (out);
}

t_score get_score(int pos, t_map *map, t_map *pie, t_map *adv)
{
    t_score out;
    out.enemy_dist = 1;
    (void) map;

    place_pie(pos, pie, adv);
    set_val_map(adv, adv->player);
    
    out.pos = pos;
    out.enemy_dist = calc_score(map, pie, pos);
    out.diff_map = calc_diff_score(map, adv);
    out.isolated = calc_iso_score(map, adv);

    out.decision = out.enemy_dist * 1 - out.diff_map / 10 - out.isolated * 1;

    if (SHOW_VALUE_MAP_ADV)
    {
        score_debug(map, pos, &out);
        debug_value_map_color_adv(adv, "\t\t\t");
    }
    return (out);
}
*/