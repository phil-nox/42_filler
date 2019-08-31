#include "filler.h"

void game_pack_init_bot(t_game_pack *game_p)
{
	game_p->game.pnt[0] = 0; //-1
    game_p->game.pnt[1] = 0; //-1
    game_p->org.map = NULL;
    game_p->map.map = NULL;
    game_p->adv.map = NULL;
    game_p->pie.map = NULL;
    game_p->att.map = NULL;
    game_p->fld.map = NULL;
    game_p->zon.map = NULL;
    game_p->fre.map = NULL;
    game_p->game.enemy_score = 0;
    game_p->game.org = &(game_p->org);
    game_p->game.map = &(game_p->map);
    game_p->game.adv = &(game_p->adv);
    game_p->game.pie = &(game_p->pie);
    game_p->game.att = &(game_p->att);
    game_p->game.fld = &(game_p->fld);
    game_p->game.zon = &(game_p->zon);
    game_p->game.fre = &(game_p->fre);
    game_p->game.show_read_debug = 0;
    game_p->game.show_place = 0;
    game_p->game.show_set_wave_debug = 0;
    game_p->game.show_set_debug = 0;
    game_p->game.show_send = 0;
    game_p->game.show_diff_debug = 0;
    game_p->game.show_score_debug = 0;
    game_p->game.decision_debug = 0;
    game_p->game.show_reset_wave_debug = 0;
    game_p->game.show_att_debug = 0;
	game_p->cmd_l[0] = '\0';
}

int enemy_score(t_map *org)
{
    int row;
    int col;
    int out;

    out = 0;
    row = -1;
    while (++row < org->row)
    {
        col = -1;
        while (++col < org->col)
        {
            if (get_val(org, row, col) == 0)
                out += 1;
        }
    }
    return (out);
}

int map_incoming_bot(char *gnl, t_game *game)
{
    int found_places;
    int error;
    int tmp_enemy_score;

    error = 0;
    if ((error = init_map(gnl, game, PIE_KW, 0))) // -1 bad malloc
        {
            tmp_enemy_score = enemy_score(game->org);
            if (game->enemy_score != tmp_enemy_score)
            {   
                game->enemy_score = tmp_enemy_score;
                found_places = find_place(game);
            }
            else
            {
                found_places = find_first_place(game, game->org);
            }
            

            if (found_places == 0)
            {
                game->pnt[0] = 0;
                game->pnt[1] = 0;
            }

            if (game->show_send || game->decision_debug)
            {
                ft_putstrfile("\t\t\t📩 SENDED: => ");
                send_position(game->pnt[0], game->pnt[1], 1);
                if (game->decision_debug)
                    shadow_calc(game);
            }
            send_position(game->pnt[0], game->pnt[1], 0);

            if (found_places == 0)
            {
                free_all_mstack();
                return (0);
            }
            return (0);
        }
        if (error == -1)
        {
            free_all_mstack();
            return (1);
        }

        if ((error = init_map(gnl, game, MAP_KW, 0))) // -1 bad malloc
            return (0);
        if (error == -1)
        {
            free_all_mstack();
            return (1);
        }

        set_player_adv(gnl, game);
		free_mstack(gnl);
        return (0);
}
