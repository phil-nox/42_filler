#include "human.h"
#include "filler.h"

int load_adapter(int *fd_adp, int *fd_vm)
{
    *fd_vm = 0;
    *fd_adp = open(FIFO_ADP, O_WRONLY);
    if (*fd_adp < 1)
    {
        write(1, "Failed with open() FIFO_ADP\n", 29);
        return (1);
    }
    return (0);
}

int main(void)
{
    t_game_pack game_pack;
    int fd_adp;
    int fd_vm;

    game_pack_init(&game_pack);
    if (load_adapter(&fd_adp, &fd_vm))
        return (1);

    while (get_next_line(fd_vm, &game_pack.gnl) == 1 && add_mstack(game_pack.gnl) == 0)
    {
        game_pack.game.player = 1; //TODO. first step commit this line
        game_pack.decision = map_incoming(&game_pack.game, game_pack.gnl, fd_vm);
        if (game_pack.decision == -1)
        {
            free_all_mstack();
            return (1);
        }
        if (game_pack.decision == 1)
        {
            send_map_to_view(&game_pack.game, game_pack.game.org, 1, 0);
            send_map_to_view(&game_pack.game, game_pack.game.org, fd_adp, 0);
        }
    }
    close(fd_adp);
    close(fd_vm);
    return (0);
}