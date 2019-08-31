#include "filler.h"

/*
    game_p->game.show_read_debug = 0;
    game_p->game.show_place = 0;
    game_p->game.show_set_wave_debug = 0;
    game_p->game.show_set_debug = 0;
    game_p->game.show_send = 0;
    game_p->game.show_diff_debug = 0;
    game_p->game.show_score_debug = 0;
    game_p->game.decision_debug = 0;
    game_p->game.show_reset_wave_debug = 0;
*/
int main(void)
{
    t_game_pack game_p;

    game_pack_init_bot(&game_p);
    game_p.game.show_att_debug = 1;
    game_p.game.show_diff_debug = 0;
    game_p.game.show_score_debug = 0;
    game_p.game.decision_debug = 0;

    while (get_next_line(0, &game_p.gnl) == 1 && add_mstack(game_p.gnl) == 0)
	{
        if (map_incoming_bot(game_p.gnl, &game_p.game))
            return (1);
    }
    debug_print(NULL, 0, -1);
}