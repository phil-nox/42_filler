/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n73_human_adapter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:32:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 17:50:11 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

int		load_adapter(int *fd_adp, int *fd_vm)
{
	*fd_vm = open(FIFO_VM, O_RDONLY);
	*fd_adp = open(FIFO_ADP, O_WRONLY);
	if (*fd_adp < 1)
	{
		write(1, "Failed with open() FIFO_ADP\n", 29);
		return (1);
	}
	return (0);
}

void	math_cores(t_map *org, int *cores_1, int *cores_2)
{
	int row;
	int col;

	*cores_1 = 0;
	*cores_2 = 0;
	row = -1;
	while (++row < org->row)
	{
		col = -1;
		while (++col < org->col)
		{
			if (get(org, row, col) == 0)
				*cores_1 += 1;
			if (get(org, row, col) == -2)
				*cores_2 += 1;
		}
	}
}

void	for_view(t_game_pack *game_pack, int fd_map)
{
	if (ft_strstr(game_pack->gnl, "$$$"))
		send_to_fd_ln(game_pack->gnl, fd_map);
}

void	send_trigger(t_game_pack *gm_p, int fd_adp)
{
	static int	cores[2];
	static int	last[2];
	static int	flop;
	static int	flop_last;

	math_cores(gm_p->game.org, cores, cores + 1);
	if (cores[0] != last[0] && cores[1] != last[1])
		flop = 0;
	else if (cores[0] != last[0])
		flop = 1;
	else
		flop = -1;
	if (flop_last != 0 && flop == flop_last)
	{
		send_map_to_view(&(gm_p->game), gm_p->game.org, fd_adp, 0);
		send_map_to_view(&(gm_p->game), gm_p->game.org, 1, 0);
		write(1, "flop_SEND\n", 10);
	}
	last[0] = cores[0];
	last[1] = cores[1];
	flop_last = flop;
}

int		main(void)
{
	t_game_pack	gm_p;
	int			fd_adp;
	int			fd_vm;
	
	game_pack_init_bot(&gm_p);
	if (load_adapter(&fd_adp, &fd_vm))
		return (1);
	while (get_next_line(fd_vm, &gm_p.gnl) == 1 && add_mstack(gm_p.gnl) == 0)
	{
		gm_p.game.player = 1;
		for_view(&gm_p, fd_adp);
		gm_p.decision = map_incoming(&(gm_p.game), gm_p.gnl, fd_vm, 0);
		if (gm_p.decision == -1)
			return (free_all_mstack());
		if (gm_p.decision == 0)
		{
			free_mstack(gm_p.gnl);
			continue;
		}
		send_trigger(&gm_p, fd_adp);
	}
	free_all_mstack();
	close(fd_adp);
	close(fd_vm);
	return (0);
}
