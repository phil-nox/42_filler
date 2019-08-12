#include "filler.h"

int main(void)
{
    char *line;

    int player;
    t_map org;
    t_map map;
    t_map tmp;
    t_map pie;

    t_score score;

    player = 0;

    while (get_next_line(0, &line) == 1)
	{
        if (init_map(line, &pie, PIE_KW))
        {
            make_map(&org, &map);
            make_map(&org, &tmp);
            set_val_map(&map, player);
            if (SHOW_VALUE_MAP)
                debug_value_map_color(&map);
            //out = find_place(player, &map, &pie);
            score = find_place_adv(&org, &map, &pie, &tmp);
            if(SHOW_SEND)
                send_debug_adv(&map, &score);
            //debug_print(ft_itoa(score.pos), 1, 1);
            send_position(&map, score.pos);
            continue;
        }
        if (init_map(line, &org, MAP_KW))
            continue;
        //set_player(line, &player);
        set_player_adv(line, &player, &org);
		free(line);
	}

    debug_print(NULL, 0, -1);
    
}