#include "filler.h"

int main(void)
{
    t_game_pack game_p;

    game_pack_init_bot(&game_p);
    while (get_next_line(0, &game_p.gnl) == 1 && add_mstack(game_p.gnl) == 0)
	{
        if (map_incoming_bot(game_p.gnl, &game_p.game))
            return (1);
    }
    debug_print(NULL, 0, -1);
}