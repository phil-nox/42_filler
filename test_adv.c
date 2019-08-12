#include "filler.h"

// How to run
// make -C./libft && gcc 1_read_map.c test_put.c -L./libft/build -lft -I./libft -o read.filler
// touch test_out test_debug
// ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1
//
// or
//
// ./test_run.sh


int main(void)
{
    int fdw;
    int fd_debug;
    char *path2file;
    char *line;

    int player;
    t_map org;
    t_map map;
    t_map tmp;
    t_map pie;

    t_score score;
    int out;

    player = 0;

    path2file = "test_out";
    fdw = open(path2file, O_RDWR);

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
        write(fdw, line, ft_strlen(line));
        write(fdw, "\n", 1);
		free(line);
	}

    debug_print(NULL, 0, -1);
    
}