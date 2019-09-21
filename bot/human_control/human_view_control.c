/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human_view_control.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 22:16:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:16:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

int		load_view(int *fd_cmd, int *fd_map)
{
	*fd_cmd = open(FIFO_CMD, O_WRONLY);
	ft_printf("fd_cmd=%d\n", *fd_cmd);
	if (*fd_cmd < 1)
	{
		write(1, "Failed with open() FIFO_CMD\n", 29);
		return (1);
	}
	write(1, "open_cmd:\tdone\n", 16);
	*fd_map = open(FIFO_MAP, O_RDONLY);
	ft_printf("fd_map=%d\n", *fd_map);
	if (*fd_map < 1)
	{
		write(1, "Failed with open() FIFO_MAP\n", 29);
		return (1);
	}
	write(1, "open_map:\tdone\n", 16);
	write(1, "open:\tdone\n", 12);
	write(1, "start! wait fd_cmd\n", 20);
	return (0);
}

int		main(void)
{
	int		fd_cmd;
	int		fd_map;
	int		pos;
	char	line[BUF_SIZE];

	line[0] = '\0';
	if (load_view(&fd_cmd, &fd_map))
		return (1);
	while ((pos = read(fd_map, line, BUF_SIZE)))
	{
		line[pos] = '\0';
		write(1, line, ft_strlen(line));
		if (line[0] == 'x')
		{
			write(fd_cmd, ">x\n", 4);
			break ;
		}
		write(fd_cmd, ">cmd\n", 7);
	}
	close(fd_cmd);
	close(fd_map);
	return (0);
}
