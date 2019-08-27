/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:41:31 by laleta            #+#    #+#             */
/*   Updated: 2019/08/27 23:54:55 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

uint8_t		g_state = 0;
int32_t		g_fdmap = -1;
int32_t		g_fdcmd = -1;

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
//	sfRenderTexture_display(sfml->render_cur);
	sfRenderTexture_display(sfml->render);
	sfSprite_setTexture(sprite_rndr,
							sfRenderTexture_getTexture(sfml->render), 0);
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
	if (((g_fdcmd = open(FIFO_CMD, O_WRONLY)) == -1) ||
		((g_fdmap = open(FIFO_MAP, O_RDONLY)) == -1))
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
	*i = 0;
	return (1);
}

int32_t					main(int32_t argc, char **argv)
{
	t_sfml		sfml;
    sfEvent		event;
	sfEvent		event_cmd;
	sfThreads	*thread_cmd;
	sfwindow	*window_cmd;
	sfVideoMode	mode;
	int32_t		i;

	if (!ft_data_valid(argc, argv, &sfml, &i))
		return (1);

mode.width = 100;
mode.height = 100;
mode.bitsPerPixel = 32;
window_cmd = sfRenderWindow_create(mode, "title", sfClose, NULL);
thread_cmd = sfThread_creat();
sfThread_launch(&ft_handle_cmd(), &window_cmd);

    while (sfRenderWindow_isOpen(sfml.window))
    {
//		if ((g_state & FLR_FIN) && !sfml.stop)
//			ft_fin(&sfml);
//		while (!i && sfRenderWindow_waitEvent(sfml.window, &event))	//&& !i
//		{
//			if (ft_event_handle(&sfml, &event))
//				break;
//		}
//		while (sfRenderWindow_pollEvent(sfml.window, &event, &window_cmd))
//			ft_event_handle(&sfml, &event);
		
		if(!sfRenderwindow_isOpen(window_cmd))
			sfRenderWindow_close(sfml.window);

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
//	close(g_fdcmd);
sfThread_terminate(thread_cmd);
sfThread_destroy(thread_cmd);
	ft_destroy_sfml(&sfml);
    return (0);
}
