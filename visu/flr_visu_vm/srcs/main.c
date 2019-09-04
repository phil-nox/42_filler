/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:13:58 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 01:25:32 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

uint8_t		g_state = 0;

void					ft_fin(t_sfml *sfml)
{
	char		*s;
	sfVector2f	pos;
	sfFloatRect	rect;

	s = sfml->p1->score > sfml->p2->score ? sfml->p1->name : sfml->p2->name;
	sfText_setString(sfml->title->text, s);
	rect = sfText_getLocalBounds(sfml->title->text);
	if (rect.width > sfml->width_sc)
	{
		pos.x = (double)sfml->width_sc / rect.width;
		pos.y = pos.x;
		sfText_setScale(sfml->title->text, pos);
	}
	rect = sfText_getGlobalBounds(sfml->title->text);
	pos.x = (sfml->width_sc + 60) / 2 - rect.width / 2;
	pos.y = 24;
	sfText_setPosition(sfml->title->text, pos);
	sfMusic_stop(sfml->music);
	sfMusic_destroy(sfml->music);
	sfml->music = sfMusic_createFromFile(F_FIN_MUS);
	if (g_state & FLR_MUSI)
		sfMusic_play(sfml->music);
	sfml->stop = 1;
}

static inline void		ft_set_rndr_cur(sfSprite *sprite_rndr, t_sfml *sfml)
{
	if (sfml->stop)
		return ;
	sfRenderTexture_display(sfml->render_cur);
	sfRenderTexture_display(sfml->render);
	sfSprite_setTexture(sprite_rndr,
							sfRenderTexture_getTexture(sfml->render_cur), 0);
	sfSprite_setScale(sprite_rndr, sfml->scale_sc);
	sfSprite_setPosition(sprite_rndr, sfml->pos_sc);
}

static inline void		ft_update_rndr_cur(sfSprite *sprite_rndr, t_sfml *sfml)
{
	if (g_state & FLR_FIN)
		return ;
	sfRenderTexture_destroy(sfml->render_cur);
	sfml->render_cur = sfRenderTexture_create(sfml->width * CELL_SZ,
													sfml->height * CELL_SZ, 0);
	sfSprite_setTexture(sprite_rndr,
								sfRenderTexture_getTexture(sfml->render), 0);
	sfSprite_setScale(sprite_rndr, sfml->scale_norm);
	sfSprite_setPosition(sprite_rndr, sfml->pos_norm);
	sfRenderTexture_drawSprite(sfml->render_cur, sprite_rndr, NULL);
}

static inline int8_t	ft_data_valid(int32_t argc, char **argv, t_sfml *sfml,
																	int32_t *i)
{
	if (!(ft_check_loadfile(argc, argv)))
		return (0);
	ft_sfml_null(sfml);
	if (!(ft_init(argc, argv, sfml)))
	{
		ft_printf(F_RED "%s: input error\n" NONE, argv[0]);
		ft_destroy_sfml(sfml);
		return (0);
	}
	*i = 0;
	return (1);
}

int32_t					main(int32_t argc, char **argv)
{
	t_sfml	sfml;
	sfEvent	event;
	int32_t i;

	if (!ft_data_valid(argc, argv, &sfml, &i))
		return (1);
	while (sfRenderWindow_isOpen(sfml.window))
	{
		if ((g_state & FLR_FIN) && !sfml.stop)
			ft_fin(&sfml);
		while (sfRenderWindow_pollEvent(sfml.window, &event))
			ft_event_handle(&sfml, &event);
		sfRenderWindow_clear(sfml.window, sfBlack);
		ft_draw_shape(&sfml);
		ft_set_rndr_cur(sfml.sprite_rndr, &sfml);
		if ((g_state & (FLR_PAUS | FLR_FIN)) == FLR_PAUS && (++i & 8))
			sfRenderWindow_drawText(sfml.window, sfml.footer->text_aux, NULL);
		sfRenderWindow_drawText(sfml.window, sfml.title->text, NULL);
		sfRenderWindow_drawText(sfml.window, sfml.footer->text, NULL);
		sfRenderWindow_drawSprite(sfml.window, sfml.sprite_rndr, NULL);
		sfRenderWindow_display(sfml.window);
		ft_update_rndr_cur(sfml.sprite_rndr, &sfml);
	}
	ft_destroy_sfml(&sfml);
	return (0);
}
