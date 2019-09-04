/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_set_shape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:13:30 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 01:13:31 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static int8_t	ft_error_shape(t_sfml *sfml)
{
	char	*s;

	s = NULL;
	if (get_next_line(0, &s) && *s && *s == 'P' && *(s + 1) == 'i')
	{
		sfml->line = ft_strdup(s);
		free(s);
		return (1);
	}
	else if (*s && *s == '=')
	{
		g_state |= FLR_FIN;
		free(s);
		return (1);
	}
	else if (*s)
		free(s);
	return (0);
}

static void		ft_player_settings(t_sfml *sfml, char player)
{
	if (player == 'O')
	{
		sfSprite_setTexture(sfml->sprite, sfml->p1->texture, sfTrue);
		if (sfml->p1->score != 0)
			--sfml->p1->score;
		if (g_state & FLR_SOUN)
			sfSound_setBuffer(sfml->sound, sfml->p1->sound);
	}
	else
	{
		sfSprite_setTexture(sfml->sprite, sfml->p2->texture, sfTrue);
		if (sfml->p2->score != 0)
			--sfml->p2->score;
		if (g_state & FLR_SOUN)
			sfSound_setBuffer(sfml->sound, sfml->p2->sound);
	}
	if (g_state & FLR_SOUN)
	{
		sfSound_setLoop(sfml->sound, sfFalse);
		sfSound_play(sfml->sound);
	}
	sfml->sprite_cur = sfSprite_copy(sfml->sprite);
	sfSprite_setColor(sfml->sprite_cur, sfRed);
}

static void		ft_draw_elem(t_sfml *sfml, t_point *pos, char player)
{
	sfVector2f	p;

	pos->x = pos->x < 0 ? sfml->width + pos->x : pos->x;
	pos->y = pos->y < 0 ? sfml->height + pos->y : pos->y;
	p.x = pos->x * CELL_SZ;
	p.y = pos->y * CELL_SZ;
	sfSprite_setPosition(sfml->sprite, p);
	sfSprite_setPosition(sfml->sprite_cur, p);
	sfRenderTexture_drawSprite(sfml->render_cur, sfml->sprite_cur, NULL);
	sfRenderTexture_drawSprite(sfml->render, sfml->sprite, NULL);
	player == 'O' ? ++sfml->p1->score : ++sfml->p2->score;
}

void			ft_set_shape(t_sfml *sfml, t_point *pos, char **shape,
																	char player)
{
	int			x_tmp;
	int			i;

	if (ft_error_shape(sfml))
		return ;
	x_tmp = pos->x;
	ft_player_settings(sfml, player);
	i = 0;
	while (*shape)
	{
		if (shape[0][i] == '\0')
		{
			i = 0;
			++shape;
			++pos->y;
			pos->x = x_tmp;
		}
		else
		{
			if (shape[0][i++] == '*')
				ft_draw_elem(sfml, pos, player);
			++pos->x;
		}
	}
	sfSprite_destroy(sfml->sprite_cur);
}
