/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n51_game_find_send.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:23:50 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/13 19:36:45 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		enemy_score(t_map *org)
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
			if (get(org, row, col) == 0)
				out += 1;
		}
	}
	return (out);
}

void	send_position_debug(t_game *game)
{
	if (game->show_send || game->decision_debug)
	{
		ft_putstrfile("\t\t\t📩 SENDED: => ");
		send_position(game->pnt[0], game->pnt[1], 1);
	}
}

int		find_and_send(t_game *game) //HERE
{
	int found_places;
	int tmp_enemy_score;

	tmp_enemy_score = enemy_score(game->org);
	if (game->enemy_score != tmp_enemy_score)
	{
		game->enemy_score = tmp_enemy_score;
		found_places = find_place(game);
	}
	else
		found_places = find_first_place(game, game->org);
	if (found_places == 0)
	{
		game->pnt[0] = 0;
		game->pnt[1] = 0;
	}
	send_position_debug(game);
	send_position(game->pnt[0], game->pnt[1], 0);
	if (found_places == 0)
	{
		free_all_mstack();
		return (1);
	}
	return (0);
}

/*
** init_map return
**  0 - if not a PIE_KW
** -1 - if error
**  1 - if PIE_KW
*/

int		map_incoming_bot(char *gnl, t_game *game)
{
	int error;

	error = 0;
	if ((error = init_map(gnl, game, PIE_KW, 0)) == 1)
		return (find_and_send(game));
	if (error == -1)
	{
		free_all_mstack();
		return (1);
	}
	if ((error = init_map(gnl, game, MAP_KW, 0)) == 1)
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
