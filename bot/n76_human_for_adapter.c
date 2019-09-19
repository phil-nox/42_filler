/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n76_human_for_adapter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:32:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/19 14:08:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

void	send_trigger(t_game_pack *gm_p, int fd_adp)
{
	static int	hum_score_mem0;
	static int	hum_score_mem1;
	int			row;
	int			col;
	int			cur_human_score;

	cur_human_score = 0;
	row = -1;
	while (++row < gm_p->game.org->row)
	{
		col = -1;
		while (++col < gm_p->game.org->col)
		{
			if (get(gm_p->game.org, row, col) == -2)
				cur_human_score += 1;
		}
	}
	if (hum_score_mem0 == cur_human_score)
	{
		write(1, "flop_SEND\n", 10);
		send_map_to_view(&(gm_p->game), gm_p->game.org, fd_adp, 0);
		send_map_to_view(&(gm_p->game), gm_p->game.org, 1, 0);
	}
	hum_score_mem0 = hum_score_mem1;
	hum_score_mem1 = cur_human_score;
}

int		for_view_adp(t_game_pack *game_pack, int fd_map)
{
	if (ft_strstr(game_pack->gnl, "$$$"))
	{
		send_to_fd_ln(game_pack->gnl, fd_map);
		send_to_fd_ln(game_pack->gnl, 1);
	}
	if (ft_strstr(game_pack->gnl, "Plateau"))
	{
		send_to_fd_ln(game_pack->gnl, fd_map);
		send_to_fd_ln(game_pack->gnl, 1);
		return (1);
	}
	return (0);
}

void	show_end(t_game_pack *gm_p, int fd)
{
	if (ft_strstr(gm_p->gnl, "== "))
		send_to_fd_ln(gm_p->gnl, fd);
}
