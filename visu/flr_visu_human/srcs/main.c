/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:41:31 by laleta            #+#    #+#             */
/*   Updated: 2019/09/05 00:47:45 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

uint8_t		g_state = 0;
int32_t		g_fdmap = -1;
int32_t		g_fdcmd = -1;
int32_t		g_fdadp = -1;

void					ft_fin(t_sfml *sfml)
{
	char				*s;
	sfVector2f			pos;
	sfFloatRect			rect;

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

static inline int8_t	ft_data_valid(int32_t argc, char **argv, t_sfml *sfml)
{
	if (!(ft_check_loadfile(argc, argv)))
		return (0);
	if (((g_fdadp = open(FIFO_ADP, O_RDONLY)) == -1) ||
		((g_fdmap = open(FIFO_MAP, O_RDONLY)) == -1) ||
		((g_fdcmd = open(FIFO_CMD, O_WRONLY)) == -1))
	{
		ft_printf(F_RED "fifo error: %s\n" NONE, strerror(errno));
		return (0);
	}
	ft_sfml_null(sfml);
	if (!(ft_init(argc, argv, sfml)))
	{
		ft_printf(F_RED "%s: input error\n" NONE, argv[0]);
		ft_destroy_sfml(sfml);
		return (0);
	}
	return (1);
}

void					ft_render(void *ssfml)
{
	t_sfml				*sfml;
	int32_t				i;

	i = 0;
	sfml = ssfml;
	sfRenderWindow_setActive(sfml->window, 1);
	while (!sfml->stop)
	{
		if ((g_state & FLR_FIN) && !sfml->stop)
			ft_fin(sfml);
		sfRenderWindow_clear(sfml->window, sfBlack);
		ft_draw_shape(sfml);
		sfRenderTexture_display(sfml->render);
		sfSprite_setTexture(sfml->sprite,
								sfRenderTexture_getTexture(sfml->render), 0);
		sfSprite_setScale(sfml->sprite, sfml->scale_sc);
		sfSprite_setPosition(sfml->sprite, sfml->pos_sc);
		sfRenderWindow_drawText(sfml->window, sfml->title->text, NULL);
		sfRenderWindow_drawText(sfml->window, sfml->footer->text, NULL);
		sfRenderWindow_drawText(sfml->window, sfml->footer->text_aux, NULL);
		sfRenderWindow_drawSprite(sfml->window, sfml->sprite, NULL);
		sfRenderWindow_display(sfml->window);
	}
}

int32_t					main(int32_t argc, char **argv)
{
	sfEvent				event;
	t_sfml				sfml;
	sfThread			*thread_rndr;

	if (!ft_data_valid(argc, argv, &sfml))
		return (1);
	sfRenderWindow_setActive(sfml.window, 0);
	thread_rndr = sfThread_create(&ft_render, &sfml);
	sfThread_launch(thread_rndr);
	while (sfRenderWindow_isOpen(sfml.window))
	{
		while (sfRenderWindow_waitEvent(sfml.window, &event))
			ft_event_handle(&sfml, &event);
	}
	ft_destroy_sfml(&sfml);
	sfThread_wait(thread_rndr);
	sfThread_destroy(thread_rndr);
	close(g_fdcmd);
	close(g_fdmap);
	close(g_fdadp);
	return (0);
}
