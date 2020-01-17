/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n73_human_adapter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:32:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/19 14:09:40 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** https://www.turnkeylinux.org/blog/unix-buffering
*/

#include "human.h"
#include "filler.h"

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
	if (write(fd, to_save, ft_strlen(to_save)) < 1)
	{
		write(1, "Failed write_tmp\n", 17);
		return (1);
	}
	close(fd);
	return (0);
}

int		set_pseudoterminal(void)
{
	int			masterfd;
	char		*slavedevice;

	masterfd = posix_openpt(O_RDWR | O_NOCTTY);
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

int		load_adapter(t_game_pack *gm_p, int *fd_adp, int *pty, int *view)
{
	game_pack_init_bot(gm_p);
	*view = 0;
	*fd_adp = open(FIFO_ADP, O_WRONLY);
	if (*fd_adp < 1)
	{
		write(1, "Failed with open() FIFO_ADP\n", 29);
		return (1);
	}
	if ((*pty = set_pseudoterminal()) < 0)
		return (1);
	write(1, "load_adapter() complete\n", 24);
	return (0);
}

void	end(int fd_adp, int pty)
{
	free_all_mstack();
	close(fd_adp);
	close(pty);
	remove(TMP_PTY);
}

int		main(void)
{
	t_game_pack	gm_p;
	int			fd_adp;
	int			pty;
	int			set_view_done;

	if (load_adapter(&gm_p, &fd_adp, &pty, &set_view_done))
		return (1);
	while (get_next_line(pty, &gm_p.gnl) == 1 && add_mstack(gm_p.gnl) == 0)
	{
		show_end(&gm_p, 1);
		gm_p.game.player = 1;
		if (set_view_done == 0)
			set_view_done = for_view_adp(&gm_p, fd_adp);
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
	end(fd_adp, pty);
	return (0);
}
