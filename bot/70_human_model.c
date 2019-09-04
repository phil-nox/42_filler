#include "human.h"
#include "filler.h"

int load_model(int *fd_cmd, int *fd_map)
{
    *fd_map = open(FIFO_MAP, O_WRONLY);
    if (*fd_map < 1)
    {
        write(1, "Failed with open() FIFO_MAP\n", 29);
        return (1);
    }

    *fd_cmd = open(FIFO_CMD, O_RDONLY);
    if (*fd_cmd < 1 )
    {
        write(1, "Failed with open() FIFO_CMD\n", 29);
        return (1);
    }
    return (0);
}

int main(void)
{
    t_game_pack game_pack;
    int fd_cmd;
    int fd_map;
    char set_view_done;

    set_view_done = 0;
    game_pack_init_bot(&game_pack);
    if (load_model(&fd_cmd, &fd_map))
        return (1);

    while (get_next_line(0, &game_pack.gnl) == 1 && add_mstack(game_pack.gnl) == 0)
    {
        if (ft_strstr(game_pack.gnl, "$$$"))
            send_to_fd_ln(game_pack.gnl, fd_map);

        if (set_view_done == 0 && ft_strstr(game_pack.gnl, "Plateau"))
        {
            send_to_fd_ln(game_pack.gnl, fd_map);
            set_view_done = 1;
        }
        
        game_pack.decision = map_incoming(&game_pack.game, game_pack.gnl, 0);
        if (game_pack.decision == -1)
        {
            free_all_mstack();
            return (1);
        }
        if (game_pack.decision == 1)
        {
            game_pack.game.pnt[0] = 0;
            game_pack.game.pnt[1] = 0;
            send_map_to_view(&game_pack.game, game_pack.game.adv, fd_map, 1);
            while (read(fd_cmd, game_pack.cmd_l, BUF_SIZE))
            {
                if (cmd_apply(&game_pack.game, fd_map, game_pack.cmd_l[0]))
                    break;
            }
        }
    }
    close(fd_cmd);
    close(fd_map);
    return (0);
}