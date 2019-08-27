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

int load_model(int *fd_adp, int *fd_vm)
{
    *fd_vm = open(FIFO_VM, O_RDONLY);
    printf("fd_vm=%d\n", *fd_vm);
    if (*fd_vm < 1)
    {
        write(1, "Failed with open() FIFO_VM\n", 28);
        return (1);
    }
    write(1, "fd_vm:\tdone\n", 13);

    *fd_adp = open(FIFO_ADP, O_WRONLY);
    if (*fd_adp < 1)
    {
        write(1, "Failed with open() FIFO_ADP\n", 29);
        return (1);
    }
    write(1, "open_map:\tdone\n", 16);
    write(1, "open:\tdone\n", 12);
    write(1, "start! wait stdin\n", 19);
    return (0);
}

int map_incoming (t_game *game, char *line, int fd_vm)
{
    int error;

    error = 0;

    if ((error = init_map(line, game, PIE_KW, fd_vm))) // -1 bad malloc
    {
        make_map(game, game->org, game->map);
        return (1);
    }
    if (error == -1)
    {
        free_all_mstack();
        return (-1);
    }

    if ((error = init_map(line, game, MAP_KW, fd_vm))) // -1 bad malloc
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
    // make re && gcc -Wall -Wextra -Werror 70_human_model.c obj/*.o -L./libft/build -lft -I./ -I./libft  -o 70_human_model.filler
    // gcc -Wall -Wextra -Werror 71_human_view.c -o 71_human_view.filler
    // gcc -Wall -Wextra -Werror 72_human_controller.c -o 72_human_controller.filler
    // ./70_human_model.filler 
    // ./71_human_view.filler #(new terminal, some folder)
    // ./72_human_controller.filler #(new terminal, some folder)

    // ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./70_human_model.filler  -f ./resources/maps/map00 -t 99 -s 7219

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

    int fd_adp;
    int fd_vm;
    int pos;
    int line_incomeing;
    char line[BUF_SIZE];
    line[0] = '\0';
    (void)pos;

    int decision;
    (void) decision;

    if (load_model(&fd_adp, &fd_vm))
        return (1);

    while (((line_incomeing = get_next_line(fd_vm, &line_gnl)) == 1 && add_mstack(line_gnl) == 0))
    {
        game.player = 1;
        write(1, line_gnl, ftt_strlen(line_gnl));
        write(1, "\n", 1);
        if (line_incomeing == 1)
            decision = map_incoming(&game, line_gnl, fd_vm);
        if (decision == -1)
        {
            free_all_mstack();
            return (1);
        }
        if (decision == 1)
        {
            send_map_to_view(&game, game.org, 1, 0);
            send_map_to_view(&game, game.org, fd_adp, 0);
        }
    }
    close(fd_adp);
    close(fd_vm);
    unlink(FIFO_ADP);
    unlink(FIFO_VM);
    return (0);
}