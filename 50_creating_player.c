#include "filler.h"

int main(void)
{
    char *line;

    t_game game;
    t_map org;
    t_map map;
    t_map adv;
    t_map pie;
    game.org = &org;
    game.map = &map;
    game.adv = &adv;
    game.pie = &pie;
    game.show_read_debug = 1;
    game.show_find_debug = 0;
    game.show_value_map = 0;
    game.show_send = 0;
    game.show_value_map_adv = 0;
    t_score score;

    //gcc -Wall -Wextra -Werror 50_creating_player.c obj/*.o -L./libft/build -lft -I./ -I./libft -o ./build/boa.filler
    (void)score;

    while (get_next_line(0, &line) == 1)
	{
        if (init_map(line, &game, PIE_KW)) // -1 bad malloc
        {
            /*
            make_map(&org, &map);
            make_map(&org, &tmp);
            set_val_map(&map, player);
            if (SHOW_VALUE_MAP)
                debug_value_map_color(&map);
            score = find_place_adv(&org, &map, &pie, &tmp);
            if(SHOW_SEND)
                send_debug_adv(&map, &score);
            send_position(&map, score.pos);
            */
            //send_position(0, 0);
            continue;
        }

        if (init_map(line, &game, MAP_KW)) // -1 bad malloc
            continue;

        set_player_adv(line, &game);
		free(line);
	}

    debug_print(NULL, 0, -1);
    
}