/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:12:21 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 01:14:55 by laleta           ###   ########.fr       */
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
		if ((*p)->sound)
			sfSoundBuffer_destroy((*p)->sound);
		if ((*p)->texture)
			sfTexture_destroy((*p)->texture);
		if ((*p)->txt_name)
			sfText_destroy((*p)->txt_name);
		if ((*p)->txt_score)
			sfText_destroy((*p)->txt_score);
		if ((*p)->sprite)
			sfSprite_destroy((*p)->sprite);
		free(*p);
		*p = NULL;
	}
}

static inline void	ft_destroy_sfml_aux(t_sfml *sfml)
{
	if (sfml->render)
		sfRenderTexture_destroy(sfml->render);
	if (sfml->render_cur)
		sfRenderTexture_destroy(sfml->render_cur);
	if (sfml->window)
		sfRenderWindow_destroy(sfml->window);
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
	if (sfml->p_font)
		sfFont_destroy(sfml->p_font);
	if (sfml->sprite)
		sfSprite_destroy(sfml->sprite);
	if (sfml->sprite_rndr)
		sfSprite_destroy(sfml->sprite_rndr);
	ft_destroy_sfml_aux(sfml);
}
