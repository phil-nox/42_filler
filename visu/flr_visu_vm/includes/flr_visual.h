/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_visual.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:10:13 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 02:38:28 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLR_VISUAL_H
# define FLR_VISUAL_H

# include "libft.h"
# include "Audio.h"
# include "Graphics.h"
# include <errno.h>
# include <sys/stat.h>
# include "flr_loadfile.h"

# define HEIGHT_MAX		2000
# define WIDTH_MAX		2500
# define MARGIN			40
# define CELL_SZ		30
# define NAME_MAX		16
# define P_FONT_SZ		80

# define FLR_FIN		1
# define FLR_MUSI		2
# define FLR_SOUN		4
# define FLR_PAUS		8

extern	uint8_t		g_state;

typedef struct		s_player
{
	char			name[NAME_MAX + 1];
	uint32_t		score;
	sfTexture		*texture;
	sfSoundBuffer	*sound;
	sfText			*txt_name;
	sfText			*txt_score;
	sfSprite		*sprite;
}					t_player;

typedef	struct		s_text
{
	sfFont			*font;
	sfText			*text;
	sfText			*text_aux;
}					t_text;

typedef struct		s_sfml
{
	int32_t			height;
	int32_t			width;
	int32_t			height_sc;
	int32_t			width_sc;
	int32_t			stop;
	uint32_t		speed;
	uint32_t		cell_cnt;
	char			*line;
	t_player		*p1;
	t_player		*p2;
	t_text			*footer;
	t_text			*title;
	sfRenderWindow	*window;
	sfRenderTexture	*render;
	sfRenderTexture	*render_cur;
	sfSprite		*sprite;
	sfSprite		*sprite_cur;
	sfSprite		*sprite_rndr;
	sfMusic			*music;
	sfSound			*sound;
	sfFont			*p_font;
	sfVector2f		pos_norm;
	sfVector2f		pos_sc;
	sfVector2f		scale_norm;
	sfVector2f		scale_sc;
	double			scale;
}					t_sfml;

typedef struct		s_point
{
	int32_t			x;
	int32_t			y;
}					t_point;

int8_t				ft_init(int32_t argc, char **argv, t_sfml *sfml);
t_player			*ft_init_player(char *img, char *sound, t_sfml *sfml);
void				ft_draw_shape(t_sfml *sfml);
void				ft_set_shape(t_sfml *sfml, t_point *p, char **sh, char plr);
void				ft_draw_header(t_sfml *sfml);
void				ft_destroy_sfml(t_sfml *sfml);
int32_t				ft_get_nbr(char **s);
int8_t				ft_check_loadfile(int32_t argc, char **argv);
void				ft_event_handle(t_sfml *sfml, sfEvent *event);
void				ft_get_size(int32_t *width, int32_t *height);
void				ft_sfml_null(t_sfml *sfml);

#endif
