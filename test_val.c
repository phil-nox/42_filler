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
    t_map map;
    t_map pie;

    int out;

    player = 0;

    path2file = "test_out";
    fdw = open(path2file, O_RDWR);

    while (get_next_line(0, &line) == 1)
	{
        if (init_map(line, &pie, PIE_KW))
        {
            set_val_map(&map, player);
            //out = find_place(player, &map, &pie);
            //send_position(&map, out);
            continue;
        }
        if (init_map(line, &map, MAP_KW))
            continue;
        set_player(line, &player);
        write(fdw, line, ft_strlen(line));
        write(fdw, "\n", 1);
		free(line);
	}

    debug_print("last possible position ", 0, 0);
    line = ft_itoa(out);
    debug_print(line, 1, 1);





    # define DB_PLY "player= "
    # define DB_ROW "map->row= "
    # define DB_COL "map->col= "
    # define DB_ROW_P "pie->row= "
    # define DB_COL_P "pie->col= "

    debug_print(DB_PLY, 0, 0);
    line = ft_itoa(player);
    debug_print(line, 1, 1);

    debug_print(DB_ROW, 0, 0);
    line = ft_itoa(map.row);
    debug_print(line, 1, 1);

    debug_print(DB_COL, 0, 0);
    line = ft_itoa(map.col);
    debug_print(line, 1, 1);

    int idx;

    idx = -1;
    while (++idx < map.row)
        debug_print(map.map[idx], 1, 0);

    debug_print(DB_ROW_P, 0, 0);
    line = ft_itoa(pie.row);
    debug_print(line, 1, 1);

    debug_print(DB_COL_P, 0, 0);
    line = ft_itoa(pie.col);
    debug_print(line, 1, 1);

    idx = -1;
    while (++idx < pie.row)
        debug_print(pie.map[idx], 1, 0);

    debug_print(NULL, 0, -1);
    
}