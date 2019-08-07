#include "filler.h"

// How to run
// make -C./libft && gcc 1_read_map.c test_1_read_map.c -L./libft/build -lft -I./libft -o read.filler
// touch test_out test_debug
// ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1

// Clean up
// make fclean -C./libft && rm -f a.out

int main(void)
{
    int fdw, fdd;
    int fd_debug;
    char *path2file;
    char *path2debug;
    char *line;

    int player;
    t_map map;
    t_map pie;



    player = 0;

    
    path2file = "test_out";
    path2debug = "test_debug"; 
    fdw = open(path2file, O_RDWR);
    fdd = open(path2debug, O_RDWR);

    while (get_next_line(0, &line) == 1)
	{

        if (init_map(line, &pie, PIE_KW))
            continue;
        if (init_map(line, &map, MAP_KW))
            continue;
        set_player(line, &player);
        write(fdw, line, ft_strlen(line));
        write(fdw, "\n", 1);
		free(line);
	}
	close(fdw);






    # define DB_PLY "player= "
    # define DB_ROW "map->row= "
    # define DB_COL "map->col= "
    # define DB_ROW_P "pie->row= "
    # define DB_COL_P "pie->col= "

    write(fdd, DB_PLY, ft_strlen(DB_PLY));
    line = ft_itoa(player);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);

    write(fdd, DB_ROW, ft_strlen(DB_ROW));
    line = ft_itoa(map.row);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);

    write(fdd, DB_COL, ft_strlen(DB_COL));
    line = ft_itoa(map.col);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);
    write(fdd, "\n", 1);

    int idx;

    idx = -1;
    while (++idx < map.row)
    {
        write(fdd, map.map[idx], ft_strlen(map.map[idx]));
        write(fdd, "\n", 1);
    }
    write(fdd, "\n", 1);

    write(fdd, DB_ROW_P, ft_strlen(DB_ROW_P));
    line = ft_itoa(pie.row);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);

    write(fdd, DB_COL_P, ft_strlen(DB_COL_P));
    line = ft_itoa(pie.col);
    write(fdd, line, ft_strlen(line));
    free(line);
    write(fdd, "\n", 1);

    idx = -1;
    while (++idx < pie.row)
    {
        write(fdd, pie.map[idx], ft_strlen(pie.map[idx]));
        write(fdd, "\n", 1);
    }

    close(fdd);
}