/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n74_human_send_basic.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:10:36 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 21:32:27 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "human.h"
#include "filler.h"

int		send_to_fd(char *line, int fd_map)
{
	return (write(fd_map, line, ft_strlen(line)));
}

int		send_to_fd_ln(char *line, int fd_map)
{
	write(fd_map, line, ft_strlen(line));
	return (write(fd_map, "\n", 1));
}
