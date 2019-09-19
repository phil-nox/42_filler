/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n70_human_model.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:24:07 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/19 14:06:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

int		load_model(int *fd_cmd, int *fd_map, int *set_view_done)
{
	*set_view_done = 0;
	*fd_map = open(FIFO_MAP, O_WRONLY);
	if (*fd_map < 1)
	{
		write(1, "Failed with open() FIFO_MAP\n", 29);
		return (1);
	}
	*fd_cmd = open(FIFO_CMD, O_RDONLY);
	if (*fd_cmd < 1)
	{
		write(1, "Failed with open() FIFO_CMD\n", 29);
		return (1);
	}
	return (0);
}

int		automove(t_game *game, int fd_map)
{
	if (game->autoplay)
	{
		game->pnt[0] = 0;
		game->pnt[1] = 0;
		if (find_last_place(game, game->org) == 0)
		{
			send_map_to_view(game, game->adv, fd_map, 0);
			free_all_mstack();
			exit(0);
		}
		send_map_to_view(game, game->adv, fd_map, 1);
		send_position(game->pnt[0], game->pnt[1], 0);
		return (1);
	}
	if (game->autoplace)
	{
		game->pnt[0] = 0;
		game->pnt[1] = 0;
		find_last_place(game, game->org);
	}
	return (0);
}

void	wait_player(t_game_pack *game_p, t_game *game, int fd_map, int fd_cmd)
{
	static int	enemy_scr;
	int			tmp;

	if ((tmp = enemy_score(game->org)) == enemy_scr)
		game->autoplay = 1;
	enemy_scr = tmp;
	if (automove(game, fd_map))
		return ;
	else if (is_a_place(game, game->org, game->pnt[0], game->pnt[1]) == -1)
	{
		game->pnt[0] = 0;
		game->pnt[1] = 0;
	}
	send_map_to_view(game, game->adv, fd_map, 1);
	while (read(fd_cmd, game_p->cmd_l, BUF_SIZE))
	{
		if (cmd_apply(game, fd_map, game_p->cmd_l[0]))
			break ;
		if (automove(game, fd_map))
			return ;
	}
}

int		for_view_old(t_game_pack *game_pack, int fd_map)
{
	if (ft_strstr(game_pack->gnl, "$$$"))
	{
		send_to_fd_ln(game_pack->gnl, fd_map);
	}
	if (ft_strstr(game_pack->gnl, "Plateau"))
	{
		send_to_fd_ln(game_pack->gnl, fd_map);
		return (1);
	}
	return (0);
}

int		main(void)
{
	t_game_pack	game_p;
	int			fd_cmd;
	int			fd_map;
	int			set_view_done;

	game_pack_init_bot(&game_p);
	if (load_model(&fd_cmd, &fd_map, &set_view_done))
		return (1);
	while (get_next_line(0, &game_p.gnl) == 1 && add_mstack(game_p.gnl) == 0)
	{
		if (set_view_done == 0)
			set_view_done = for_view_old(&game_p, fd_map);
		game_p.decision = map_incoming(&game_p.game, game_p.gnl, 0, 1);
		if (game_p.decision == -1)
			return (free_all_mstack());
		if (game_p.decision == 0)
		{
			free_mstack(game_p.gnl);
			continue;
		}
		wait_player(&game_p, &(game_p.game), fd_map, fd_cmd);
	}
	close(fd_cmd);
	close(fd_map);
	return (0);
}
