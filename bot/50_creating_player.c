#include "filler.h"

int main(void)
{
    char *line;

    t_game game;
    t_map org;
    t_map map;
    t_map adv;
    t_map pie;
    game.pnt[0] = -1;
    game.pnt[1] = -1;
    org.map = NULL;
    map.map = NULL;
    adv.map = NULL;
    pie.map = NULL;
    game.org = &org;
    game.map = &map;
    game.adv = &adv;
    game.pie = &pie;
    game.show_read_debug = 1;
    game.show_make_debug = 0;
    game.show_set_wave_debug = 0;
    game.show_set_debug = 1;
    game.show_place = 1;
    game.show_find_debug = 0;
    game.show_value_map = 0;
    game.show_send = 1;
    game.show_value_map_adv = 0;
    game.show_reset_wave_debug = 1;
    game.show_diff_debug = 1;
    t_score score;

    int found_places;
    int error;

    error = 0;
    (void)score;

    while (get_next_line(0, &line) == 1 && add_mstack(line) == 0)
	{
        if ((error = init_map(line, &game, PIE_KW, 0))) // -1 bad malloc
        {
            make_map(&game, game.org, game.map);
            set_val_map(&game, game.map, 0);
            make_map(&game, game.org, game.adv);
            
            if (game.show_set_debug) 
            {
                ft_putstrfile("\n");
                debug_value_map_color(game.map);
                ft_putstrfile("|||||||| END SET ||||||||\n");
            }

            found_places = find_place(&game);
            /*
            score = find_place_adv(&org, &map, &pie, &adv);
            if(SHOW_SEND)
                send_debug_adv(&map, &score);
            send_position(&map, score.pos);
            */

            if (game.show_send)
            {
                ft_putstrfile("📩 SENDED: => ");
                send_position(game.pnt[0], game.pnt[1], 1);
                ft_putstrfile("\n");
            }
            send_position(game.pnt[0], game.pnt[1], 0);

            if (found_places == 0)
            {
                free_all_mstack();
                return (0);
            }
            continue;
        }
        if (error == -1)
        {
            free_all_mstack();
            return (1);
        }

        if ((error = init_map(line, &game, MAP_KW, 0))) // -1 bad malloc
            continue;
        if (error == -1)
        {
            free_all_mstack();
            return (1);
        }

        set_player_adv(line, &game);
		free_mstack(line);
	}

    debug_print(NULL, 0, -1);
    
}