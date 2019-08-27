/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:25:29 by laleta            #+#    #+#             */
/*   Updated: 2019/08/21 22:25:30 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static void		ft_event_handle_cmd(sfEvent *event)
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

int8_t			ft_event_handle(t_sfml *sfml, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyP)
		g_state = g_state & FLR_PAUS ? g_state & ~FLR_PAUS : g_state | FLR_PAUS;
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyS)
		g_state = g_state & FLR_SOUN ? g_state & ~FLR_SOUN : g_state | FLR_SOUN;
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyM)
	{
		g_state = g_state & FLR_MUSI ? g_state & ~FLR_MUSI : g_state | FLR_MUSI;
		g_state & FLR_MUSI ? sfMusic_play(sfml->music) :
													sfMusic_stop(sfml->music);
	}
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyComma)
		sfml->speed += 100;
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyPeriod)
		sfml->speed -= 100;
	if (event->type == sfEvtClosed ||
		(event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape))
		sfRenderWindow_close(sfml->window);
	if (!(g_state & FLR_LOSE))
		ft_event_handle_cmd(event);
	if (event->type == sfEvtKeyPressed && (event->key.code == sfKeyEscape ||
		event->key.code == sfKeyLeft || event->key.code == sfKeyRight ||
		event->key.code == sfKeyUp || event->key.code == sfKeyDown ||
		event->key.code == sfKeyEnter))
		return (1);
	return (0);
}
