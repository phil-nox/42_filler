/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <laleta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 22:25:29 by laleta            #+#    #+#             */
/*   Updated: 2019/09/18 15:09:18 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

void		ft_event_handle_cmd(t_sfml *sfml, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyLeft)
		write(g_fdcmd, CMD_LEFT, CMD_LEN);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyRight)
		write(g_fdcmd, CMD_RIGHT, CMD_LEN);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyUp)
		write(g_fdcmd, CMD_UP, CMD_LEN);
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyDown)
		write(g_fdcmd, CMD_DOWN, CMD_LEN);
	if (event->type == sfEvtKeyPressed && (event->key.code == sfKeySpace ||
												event->key.code == sfKeyEnter))
	{
		write(g_fdcmd, CMD_SET, CMD_LEN);
		if (g_state & FLR_SOUN)
			sfSound_play(sfml->sound);
	}
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyX)
		write(g_fdcmd, CMD_AUTO, CMD_LEN);
}

void		ft_event_handle(t_sfml *sfml, sfEvent *event)
{
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyS)
		g_state = g_state & FLR_SOUN ? g_state & ~FLR_SOUN : g_state | FLR_SOUN;
	if (event->type == sfEvtKeyPressed && event->key.code == sfKeyM)
	{
		g_state = g_state & FLR_MUSI ? g_state & ~FLR_MUSI : g_state | FLR_MUSI;
		g_state & FLR_MUSI ? sfMusic_play(sfml->music) :
													sfMusic_stop(sfml->music);
	}
	if (event->type == sfEvtClosed ||
		(event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape) ||
		(event->type == sfEvtKeyPressed && g_state & FLR_FIN))
		sfRenderWindow_close(sfml->window);
	if (!(g_state & (FLR_LOSE | FLR_FIN)))
		ft_event_handle_cmd(sfml, event);
}
