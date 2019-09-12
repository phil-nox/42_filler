/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n73_human_adapter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:32:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 21:39:15 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

int	load_adapter(int *fd_adp, int *fd_vm)
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

int	main(void)
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
		gm_p.decision = map_incoming(&gm_p.game, gm_p.gnl, fd_vm);
		if (gm_p.decision == -1)
			return (free_all_mstack());
		if (gm_p.decision == 0)
		{
			free_mstack(gm_p.gnl);
			continue;
		}
		send_map_to_view(&gm_p.game, gm_p.game.org, 1, 0);
		send_map_to_view(&gm_p.game, gm_p.game.org, fd_adp, 0);
	}
	free_all_mstack();
	close(fd_adp);
	close(fd_vm);
	return (0);
}
