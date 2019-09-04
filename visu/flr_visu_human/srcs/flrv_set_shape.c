/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_set_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:44:23 by laleta            #+#    #+#             */
/*   Updated: 2019/08/31 23:37:00 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static inline void	ft_draw_elem_hm(t_sfml *sfml, char c, int32_t x, int32_t y)
{
	sfVector2f		pos;

	pos.x = x * CELL_SZ;
	pos.y = y * CELL_SZ;
	sfSprite_setPosition(sfml->p1->sprite_m, pos);
	sfRenderTexture_drawSprite(sfml->render, sfml->p1->sprite_m, NULL);
	if (c == 'o' || c == 'O')
		sfml->p1->score++;
	else if (c == 't' || c == 'T')
	{
		sfRectangleShape_setPosition(sfml->p1->shape_ok, pos);
		sfRenderTexture_drawRectangleShape(sfml->render, sfml->p1->shape_ok,
																		NULL);
	}
	else if (c == 'f' || c == 'F')
	{
		sfRectangleShape_setPosition(sfml->p1->shape_er, pos);
		sfRenderTexture_drawRectangleShape(sfml->render, sfml->p1->shape_er,
																		NULL);
	}
}

static void			ft_draw_elem(t_sfml *sfml, char c, int32_t x, int32_t y)
{
	sfVector2f		pos;

	pos.x = x * CELL_SZ;
	pos.y = y * CELL_SZ;
	if (c == '.')
	{
		sfRectangleShape_setPosition(sfml->p1->shape_bl, pos);
		sfRenderTexture_drawRectangleShape(sfml->render, sfml->p1->shape_bl,
																		NULL);
	}
	else if (c == 'x' || c == 'X')
	{
		sfml->p2->score++;
		sfSprite_setPosition(sfml->p2->sprite_m, pos);
		sfRenderTexture_drawSprite(sfml->render, sfml->p2->sprite_m, NULL);
	}
	else
		ft_draw_elem_hm(sfml, c, x, y);
}

void				ft_set_shape(t_sfml *sfml, char **shape)
{
	int32_t			x;
	int32_t			y;

	x = 0;
	y = 0;
	sfml->p1->score = 0;
	sfml->p2->score = 0;
	while (*shape)
	{
		if (shape[0][x] == '\0')
		{
			++shape;
			++y;
			x = 0;
		}
		else
		{
			ft_draw_elem(sfml, shape[0][x], x, y);
			++x;
		}
	}
}
