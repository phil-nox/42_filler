/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 20:07:20 by laleta            #+#    #+#             */
/*   Updated: 2019/08/27 20:25:25 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static t_text	*ft_init_footer(t_sfml *sfml)
{
	sfVector2f	pos;
	sfFloatRect	rect;
	t_text		*footer;

	if (!(footer = (t_text *)malloc(sizeof(t_text))) ||
		!(footer->font = sfFont_createFromFile(F_FONT)) ||
    	!(footer->text = sfText_create()) ||
		!(footer->text_aux = sfText_create()))
		return (NULL);
    sfText_setString(footer->text, "[<]left [>]right [^]up [v]down [space]set");
    sfText_setFont(footer->text, footer->font);
    sfText_setCharacterSize(footer->text, P_FONT_SZ / 2);
 	sfText_setString(footer->text_aux, "PAUSE");
    sfText_setFont(footer->text_aux, footer->font);
    sfText_setCharacterSize(footer->text_aux, P_FONT_SZ);
	pos.y = sfml->height_sc + 520;
	pos.x = MARGIN;
	sfText_setPosition(footer->text, pos);
	rect = sfText_getLocalBounds(footer->text_aux);
	pos.x = (sfml->width_sc + 60) / 2 - rect.width / 2;
	pos.y = 385;
	sfText_setPosition(footer->text_aux, pos);
	return (footer);
}

static t_text	*ft_init_title(t_sfml *sfml)
{
	sfVector2f	pos;
	sfFloatRect	rect;
	t_text		*title;

	if (!(title = (t_text *)malloc(sizeof(t_text))) ||
		!(title->font = sfFont_createFromFile(T_FONT)) ||
    	!(title->text = sfText_create()))
		return (NULL);
	title->text_aux = NULL;
    sfText_setString(title->text, "FILLER");
    sfText_setFont(title->text, title->font);
    sfText_setCharacterSize(title->text, P_FONT_SZ * 2);
	rect = sfText_getLocalBounds(title->text);
	pos.x = (sfml->width_sc + 60) / 2 - rect.width / 2;
	pos.y = 24;
	sfText_setPosition(title->text, pos);
	return (title);
}

static void		ft_init_sfml_pos(t_sfml *sfml)
{
	sfml->pos_sc.x = MARGIN;
	sfml->pos_sc.y = 480;
	sfml->scale_sc.x = sfml->scale;
	sfml->scale_sc.y = sfml->scale;
	sfml->pos_norm.x = 0;
	sfml->pos_norm.y = 0;
	sfml->scale_norm.x = 1;
	sfml->scale_norm.y = 1;
	sfRenderWindow_setVerticalSyncEnabled(sfml->window, 1);
	sfRenderTexture_clear(sfml->render, sfBlack);
	sfRenderTexture_clear(sfml->render_cur, sfBlack);
	sfRenderWindow_clear(sfml->window, sfBlack);
	sfRenderWindow_display(sfml->window);
	sfSound_setBuffer(sfml->sound, sfml->sound_buffer);
}

static int8_t	ft_init_sfml(t_sfml *sfml)
{
	sfVideoMode	mode;

	ft_get_size(&sfml->width, &sfml->height);
	sfml->cell_cnt = sfml->width * sfml->height;
	sfml->scale = sfml->height * CELL_SZ > HEIGHT_MAX ?
							(double)HEIGHT_MAX / (sfml->height * CELL_SZ) : 1;
	sfml->height_sc = sfml->height * CELL_SZ * sfml->scale;
	sfml->width_sc = sfml->width * CELL_SZ * sfml->scale;
	mode.width = sfml->width_sc + 2 * MARGIN;
	mode.height = sfml->height_sc + 580;
	mode.bitsPerPixel = 32;	
	if (!(sfml->render = sfRenderTexture_create(sfml->width * CELL_SZ,
		sfml->height * CELL_SZ, 0)) ||
		!(sfml->render_cur = sfRenderTexture_create(sfml->width * CELL_SZ,
		sfml->height * CELL_SZ, 0)) || !(sfml->window = sfRenderWindow_create
		(mode, "Will you be the best?", sfResize | sfClose,	NULL)) ||
		!(sfml->music = sfMusic_createFromFile(F_MUSIC)) ||
		!(sfml->sound_buffer = sfSoundBuffer_createFromFile(P1_SOUND)) ||
		!(sfml->sound = sfSound_create()) ||
		!(sfml->sprite_rndr = sfSprite_create()))
		return (0);
	sfml->stop = 0;
	sfml->speed = 300;		
	ft_init_sfml_pos(sfml);
	return (1);
}

int8_t			ft_init(int32_t argc, char **argv, t_sfml *sfml)
{
	char	*img[2];
	int8_t	i;

	img[0] = P2_IMG;
	img[1] = P1_IMG;
	i = -1;
	while (++i < argc - 1 && i < 2)
		img[i] = argv[i + 1];
	if (!(sfml->p_font = sfFont_createFromFile(P_FONT)) ||
		!(sfml->p1 = ft_init_player(img[0], sfml, HUMAN)) ||
		!(sfml->p2 = ft_init_player(img[1], sfml, BOT)) ||
		!(ft_init_sfml(sfml))  ||
		!(sfml->footer = ft_init_footer(sfml)) ||
		!(sfml->title = ft_init_title(sfml)))
		return (0);
	return (1);
}
