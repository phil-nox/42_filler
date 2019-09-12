/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n30_send_pie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:27:28 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 17:28:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	send_position(int row, int col, int where)
{
	char	*line;
	int		fd;

	if (where != 0)
		fd = get_fdd();
	else
		fd = 1;
	line = ft_itoa(row);
	write(fd, line, ft_strlen(line));
	free(line);
	line = " ";
	write(fd, line, ft_strlen(line));
	line = ft_itoa(col);
	write(fd, line, ft_strlen(line));
	free(line);
	line = "\n";
	write(fd, line, ft_strlen(line));
}
