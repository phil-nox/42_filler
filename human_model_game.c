#include "human.h"
#include "filler.h"

size_t	ftt_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int load_model(int *fd_cmd, int *fd_map, int debug)
{
    unlink(FIFO_MAP);
    unlink(FIFO_CMD);
    if (debug)
        write(1, "unlink:\tdone\n", 14);

    if (mkfifo(FIFO_MAP, 0777) != 0 || mkfifo(FIFO_CMD, 0777) != 0)
    {
        //perror("mkfifo() error"); //#include <stdio.h>
        if (debug)
            if (debug)write(1, "Failed with mkfifo()", 21);
        return (1);
    }
    if (debug)
        write(1, "mkfifo:\tdone\n", 14);

    *fd_cmd = open(FIFO_CMD, O_RDONLY);
    if (*fd_cmd < 1 )
    {
        if (debug)
            write(1, "Failed with open() FIFO_CMD\n", 29);
        return (1);
    }
    if (debug)
        write(1, "open_cmd:\tdone\n", 16);

    *fd_map = open(FIFO_MAP, O_WRONLY);
    if (*fd_map < 1)
    {
        if (debug)
            write(1, "Failed with open() FIFO_MAP\n", 29);
        return (1);
    }
    if (debug)
    {
        write(1, "open_map:\tdone\n", 16);
        write(1, "open:\tdone\n", 12);
        write(1, "start! wait fd_cmd\n", 20);
    }
    return (0);
}

int map_incoming (t_game *game, char *line)
{
    int error;

    error = 0;

    if ((error = init_map(line, game, PIE_KW))) // -1 bad malloc
    {
        make_map(game, game->org, game->map);
        return (1);
    }
    if (error == -1)
    {
        free_all_mstack();
        return (-1);
    }

    if ((error = init_map(line, game, MAP_KW))) // -1 bad malloc
        return (0);
    if (error == -1)
    {
        free_all_mstack();
        return (-1);
    }

    set_player_adv(line, game);
	free_mstack(line);
    return (0);
}

int main(void)
{
    // gcc -Wall -Wextra -Werror human_model_game.c obj/*.o -L./libft/build -lft -I./ -I./libft  -o human_model_game.filler
    // gcc -Wall -Wextra -Werror human_view_control_game.c -o human_view_control_game.filler
    // ./human_model_game.filler 
    // ./human_view_control_game.filler #(new terminal, some folder)
    // echo '1 2' > mypipe.cmd #FIFO_CMD #(new terminal, some folder)

    // ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./human_model_game.filler -f ./resources/maps/map00 -t 99

    // START --- GAME
    char *line_gnl;

    t_game game;
    t_map org;
    t_map map;
    t_map adv;
    t_map pie;
    game.pnt[0] = 0;
    game.pnt[1] = 0;
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
    game.show_set_debug = 0;
    game.show_place = 0;
    game.show_find_debug = 0;
    game.show_value_map = 0;
    game.show_send = 0;
    game.show_value_map_adv = 0;
    game.show_reset_wave_debug = 0;

    // END --- GAME

    int fd_cmd;
    int fd_map;
    int pos;
    int line_incomeing;
    char line[BUF_SIZE];
    line[0] = '\0';
    (void)pos;

    int decision;

    if (load_model(&fd_cmd, &fd_map, 0))
        return (1);

    //while ((pos = read(fd_cmd, line, BUF_SIZE)) || ((line_incomeing = get_next_line(0, &line_gnl)) == 1 && add_mstack(line_gnl) == 0))
    while (((line_incomeing = get_next_line(0, &line_gnl)) == 1 && add_mstack(line_gnl) == 0))
    {
        if (line_incomeing == 1)
            decision = map_incoming(&game, line_gnl);
        if (decision == -1)
        {
            free_all_mstack();
            return (1);
        }
        if (decision == 1)
            send_map_to_view(&game, fd_map);
        pos = 0;
        line[pos] = '\0';
        /*
        //write(1, line, ftt_strlen(line));
        if (line[0] != '>')
            write(fd_map, line, ftt_strlen(line));
        if (line[0] == 'x')
        {
            write(fd_map, line, ftt_strlen(line));
            break;
        }
        */
    }
    close(fd_cmd);
    close(fd_map);
    unlink(FIFO_MAP);
    unlink(FIFO_CMD);
    return (0);
}