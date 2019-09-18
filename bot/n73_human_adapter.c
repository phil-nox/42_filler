/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n73_human_adapter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:32:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/17 19:58:43 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.turnkeylinux.org/blog/unix-buffering
*/


#include "human.h"
#include "filler.h"

int		load_adapter(int *fd_adp)
{
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

int		for_view(t_game_pack *game_pack, int fd_map)
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
		write(1, "flop_SEND\n", 10);
		send_map_to_view(&(gm_p->game), gm_p->game.org, fd_adp, 0);
		send_map_to_view(&(gm_p->game), gm_p->game.org, 1, 0);
	}
	last[0] = cores[0];
	last[1] = cores[1];
	flop_last = flop;
}

int		write_tmp(char *to_save)
{
	int fd;

	if (!(fopen(TMP_PTY, "w+")))
	{
		write(1, "Failed fopen\n", 13);
		return (1);
	}
	fd = open(TMP_PTY, O_WRONLY);
	if (fd < 1)
	{
		write(1, "Failed write_tmp\n", 17);
		return (1);
	}
	if (write (fd, to_save, ft_strlen(to_save)) < 1)
	{
		write(1, "Failed write_tmp\n", 17);
		return (1);
	}
	close(fd);
	return (0);
}

int		set_pseudoterminal()
{
	int			masterfd;
	char		*slavedevice;

	masterfd = posix_openpt(O_RDWR|O_NOCTTY);
	if (masterfd < 0)
		return (-1);
	slavedevice = ptsname(masterfd);
	if (grantpt(masterfd) != 0)
		return (-1);
	if (unlockpt(masterfd) != 0)
		return (-1);
	if (write_tmp(slavedevice))
		return (-1);
	return (masterfd);
}

int		main(void)
{
	t_game_pack	gm_p;
	int			fd_adp;
	int			pty;
	int			set_view_done;
	
	set_view_done = 0;
	game_pack_init_bot(&gm_p);
	if (load_adapter(&fd_adp))
		return (1);
	if ((pty = set_pseudoterminal()) < 0)
		return (1);
	while (get_next_line(pty, &gm_p.gnl) == 1 && add_mstack(gm_p.gnl) == 0)
	{
		gm_p.game.player = 1;
		if (set_view_done == 0)
			set_view_done = for_view(&gm_p, fd_adp);
		gm_p.decision = map_incoming(&(gm_p.game), gm_p.gnl, pty, 0);
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
	close(pty);
	remove(TMP_PTY);
	return (0);
}
