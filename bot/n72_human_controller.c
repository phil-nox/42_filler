/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n72_human_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:08:49 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:20:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "human.h"

int	load_controller(int *fd_cmd)
{
	*fd_cmd = open(FIFO_CMD, O_WRONLY);
	ft_printf("fd_cmd=%d\n", *fd_cmd);
	if (*fd_cmd < 1)
	{
		write(1, "Failed with open() FIFO_CMD\n", 29);
		return (1);
	}
	write(1, "open_cmd:\tdone\n", 16);
	write(1, "open:\tdone\n", 12);
	return (0);
}

int	main(void)
{
	int		fd_cmd;
	char	to_send;

	if (load_controller(&fd_cmd))
		return (1);
	while (scanf("%c", &to_send))
		write(fd_cmd, &to_send, 1);
	close(fd_cmd);
	return (0);
}
