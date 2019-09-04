/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 19:34:17 by laleta            #+#    #+#             */
/*   Updated: 2019/08/31 22:55:40 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static void			ft_destroy_text(t_text **t)
{
	if (*t)
	{
		if ((*t)->font)
			sfFont_destroy((*t)->font);
		if ((*t)->text)
			sfText_destroy((*t)->text);
		if ((*t)->text_aux)
			sfText_destroy((*t)->text_aux);
		free(*t);
		*t = NULL;
	}
}

static void			ft_destroy_player(t_player **p)
{
	if (*p)
	{
		if ((*p)->texture)
			sfTexture_destroy((*p)->texture);
		if ((*p)->txt_name)
			sfText_destroy((*p)->txt_name);
		if ((*p)->txt_score)
			sfText_destroy((*p)->txt_score);
		if ((*p)->sprite_s)
			sfSprite_destroy((*p)->sprite_s);
		if ((*p)->sprite_m)
			sfSprite_destroy((*p)->sprite_m);
		if ((*p)->shape_ok)
			sfRectangleShape_destroy((*p)->shape_ok);
		if ((*p)->shape_er)
			sfRectangleShape_destroy((*p)->shape_er);
		if ((*p)->shape_bl)
			sfRectangleShape_destroy((*p)->shape_bl);
		free(*p);
		*p = NULL;
	}
}

static inline void	ft_destroy_sfml_aux(t_sfml *sfml)
{
	if (sfml->render)
		sfRenderTexture_destroy(sfml->render);
	if (sfml->window)
		sfRenderWindow_destroy(sfml->window);
	if (sfml->sprite)
		sfSprite_destroy(sfml->sprite);
}

void				ft_destroy_sfml(t_sfml *sfml)
{
	if (sfml->p1)
		ft_destroy_player(&sfml->p1);
	if (sfml->p2)
		ft_destroy_player(&sfml->p2);
	if (sfml->footer)
		ft_destroy_text(&sfml->footer);
	if (sfml->title)
		ft_destroy_text(&sfml->title);
	if (sfml->music)
	{
		sfMusic_stop(sfml->music);
		sfMusic_destroy(sfml->music);
	}
	if (sfml->sound)
	{
		sfSound_stop(sfml->sound);
		sfSound_destroy(sfml->sound);
	}
	if (sfml->sound_buf_pl)
		sfSoundBuffer_destroy(sfml->sound_buf_pl);
	if (sfml->sound_buf_er)
		sfSoundBuffer_destroy(sfml->sound_buf_er);
	if (sfml->p_font)
		sfFont_destroy(sfml->p_font);
	ft_destroy_sfml_aux(sfml);
}
