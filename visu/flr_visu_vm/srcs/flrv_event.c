/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:12:58 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 01:13:00 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

void	ft_event_handle(t_sfml *sfml, sfEvent *event)
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
}
