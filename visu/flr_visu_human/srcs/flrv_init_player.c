/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_init_player.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 01:19:14 by laleta            #+#    #+#             */
/*   Updated: 2019/09/16 20:56:20 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static inline void	ft_init_player_settext(t_player *p, t_sfml *sfml)
{
	sfText_setString(p->txt_name, p->name);
	sfText_setFont(p->txt_name, sfml->p_font);
	sfText_setCharacterSize(p->txt_name, P_FONT_SZ / 2);
	sfText_setFont(p->txt_score, sfml->p_font);
	sfText_setCharacterSize(p->txt_score, P_FONT_SZ / 2);
	sfTexture_setRepeated(p->texture, sfTrue);
	sfSprite_setTexture(p->sprite_s, p->texture, 0);
	sfSprite_setTexture(p->sprite_m, p->texture, 1);
	p->score = 0;
}

int8_t				ft_init_player_name(t_player *p, int32_t fd)
{
	char		*s;
	char		*fnd;
	char		*tmp;

	while (get_next_line(fd, &s) && *s != '$')
		free(s);
	if (*s != '$')
		return (0);
	tmp = s;
	s += 14;
	fnd = ft_strchr(s, '/');
	s = fnd ? ++fnd : ++s;
	fnd = s;
	while (*s && *s != '.')
		s++;
	ft_strlcpy(p->name, fnd, s - fnd + 1 >= NAME_MAX ? NAME_MAX : s - fnd + 1);
	free(tmp);
	return (1);
}

void				ft_init_player_shape(t_player *p)
{
	sfVector2f size;

	size.x = CELL_SZ;
	size.y = CELL_SZ;
	sfRectangleShape_setFillColor(p->shape_ok, sfTransparent);
	sfRectangleShape_setFillColor(p->shape_er, sfTransparent);
	sfRectangleShape_setFillColor(p->shape_bl, sfBlack);
	sfRectangleShape_setOutlineColor(p->shape_ok, sfGreen);
	sfRectangleShape_setOutlineColor(p->shape_er, sfRed);
	sfRectangleShape_setOutlineThickness(p->shape_ok, -2.0);
	sfRectangleShape_setOutlineThickness(p->shape_er, -2.0);
	sfRectangleShape_setSize(p->shape_ok, size);
	sfRectangleShape_setSize(p->shape_er, size);
	sfRectangleShape_setSize(p->shape_bl, size);
}

t_player			*ft_init_player(char *img_path, t_sfml *sfml, int8_t human)
{
	t_player	*p;

	if (!(p = (t_player *)malloc(sizeof(t_player))) ||
		!(p->texture = sfTexture_createFromFile(img_path, NULL)) ||
		!(p->txt_name = sfText_create()) ||
		!(p->txt_score = sfText_create()) ||
		!(p->sprite_s = sfSprite_create()) ||
		!(p->sprite_m = sfSprite_create()) ||
		!(p->shape_ok = sfRectangleShape_create()) ||
		!(p->shape_er = sfRectangleShape_create()) ||
		!(p->shape_bl = sfRectangleShape_create()))
		return (NULL);
	if (human)
	{
		if (!ft_init_player_name(p, g_fdmap))
			return (NULL);
		ft_init_player_shape(p);
	}
	if (!human)
		ft_strlcpy(p->name, "player 2", 9);
	ft_init_player_settext(p, sfml);
	return (p);
}

void				ft_sfml_null(t_sfml *sfml)
{
	sfml->p1 = NULL;
	sfml->p2 = NULL;
	sfml->footer = NULL;
	sfml->title = NULL;
	sfml->window = NULL;
	sfml->render = NULL;
	sfml->sprite = NULL;
	sfml->music = NULL;
	sfml->sound = NULL;
	sfml->sound_buf_pl = NULL;
	sfml->sound_buf_er = NULL;
	sfml->p_font = NULL;
}
