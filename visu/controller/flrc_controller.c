/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:41:31 by laleta            #+#    #+#             */
/*   Updated: 2019/08/27 20:26:11 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graphics.h"
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

# define FIFO_CMD		"../fifo_2"
# define CMD_UP			"u"
# define CMD_DOWN		"d"
# define CMD_LEFT		"l"
# define CMD_RIGHT		"r"
# define CMD_SET		"s"
# define CMD_LEN		1


int32_t		g_fdcmd = -1;

static inline int8_t	ft_data_valid(void)
{
	if ((g_fdcmd = open(FIFO_CMD, O_WRONLY)) == -1)
	{
		printf("fifo error: %s\n", strerror(errno));
		return (0);
	}
	return (1);
}

void		ft_event_handle(sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyLeft)
		write(g_fdcmd, CMD_LEFT, CMD_LEN);   //"9 3\n", 4);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyRight)
		write(g_fdcmd, CMD_RIGHT, CMD_LEN);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp)
		write(g_fdcmd, CMD_UP, CMD_LEN);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown)
		write(g_fdcmd, CMD_DOWN, CMD_LEN);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace)
		write(g_fdcmd, CMD_SET, CMD_LEN);   //"8 2\n", 4);
}

int32_t					main(void)
{
    sfEvent			event;
	sfRenderWindow	*window;
	sfVideoMode		mode;

	if (!ft_data_valid())
		return (1);
	mode.width = 100;
	mode.height = 100;
	mode.bitsPerPixel = 32;	
	window = sfRenderWindow_create (mode, "title", sfClose,	NULL);
	while (sfRenderWindow_waitEvent(window, &event))
		ft_event_handle(&event);
	close(g_fdcmd);
    return (0);
}
