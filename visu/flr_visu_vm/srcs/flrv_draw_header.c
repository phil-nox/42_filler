/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_draw_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:12:38 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 01:15:55 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static inline void	ft_draw_header_text(t_sfml *sfml, sfText *txt,
															float x, float y)
{
	sfVector2f	pos;
	sfFloatRect	rect;

	if (x)
		pos.x = x;
	else
	{
		rect = sfText_getLocalBounds(txt);
		pos.x = sfml->width_sc - rect.width + MARGIN;
	}
	pos.y = y;
	sfText_setPosition(txt, pos);
	sfRenderWindow_drawText(sfml->window, txt, NULL);
}

static inline void	ft_draw_header_sprite(t_sfml *sfml, sfSprite *sprite,
															float x, float y)
{
	sfVector2f	pos;

	pos.x = x;
	pos.y = y;
	sfSprite_setPosition(sprite, pos);
	sfRenderWindow_drawSprite(sfml->window, sprite, NULL);
}

void				ft_draw_header(t_sfml *sfml)
{
	sfIntRect	irect;
	char		*s;

	ft_draw_header_text(sfml, sfml->p1->txt_name, MARGIN, 220);
	ft_draw_header_text(sfml, sfml->p2->txt_name, MARGIN, 340);
	sfText_setString(sfml->p1->txt_score, s = ft_itoa(sfml->p1->score));
	ft_draw_header_text(sfml, sfml->p1->txt_score, 0, 220);
	free(s);
	sfText_setString(sfml->p2->txt_score, s = ft_itoa(sfml->p2->score));
	ft_draw_header_text(sfml, sfml->p2->txt_score, 0, 340);
	free(s);
	irect.left = 0;
	irect.top = 0;
	irect.height = CELL_SZ;
	irect.width = (double)sfml->p1->score / sfml->cell_cnt * sfml->width_sc;
	sfSprite_setTextureRect(sfml->p1->sprite, irect);
	ft_draw_header_sprite(sfml, sfml->p1->sprite, MARGIN, 280);
	irect.left = 0;
	irect.top = 0;
	irect.height = CELL_SZ;
	irect.width = (double)sfml->p2->score / sfml->cell_cnt * sfml->width_sc;
	sfSprite_setTextureRect(sfml->p2->sprite, irect);
	ft_draw_header_sprite(sfml, sfml->p2->sprite, MARGIN, 400);
}
