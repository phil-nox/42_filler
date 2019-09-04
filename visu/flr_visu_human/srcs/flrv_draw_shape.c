/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_draw_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:43:07 by laleta            #+#    #+#             */
/*   Updated: 2019/09/04 21:23:51 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

static void		ft_free_shape(char ***shape)
{
	char	**tmp;

	tmp = *shape;
	while (**shape)
	{
		free(**shape);
		++*shape;
	}
	free(tmp);
}

static void		ft_get_shape(t_sfml *sfml, int cnt)
{
	char		**shape;
	int32_t		i;

	if (!(shape = (char **)malloc(sizeof(*shape) * (cnt + 1))))
		return ;
	shape[cnt] = NULL;
	i = 0;
	while (i < cnt && get_next_line(sfml->fd, &shape[i]) && shape[i])
		++i;
	if (sfml->map_vm == -1 || sfml->map_vm >= sfml->map_pl)
		ft_set_shape(sfml, shape);
	if (sfml->map_vm == 0 && (g_state & FLR_SOUN))
	{
		sfSound_setBuffer(sfml->sound, sfml->sound_buf_er);
		sfSound_play(sfml->sound);
	}
	ft_free_shape(&shape);
}

void			ft_draw_shape(t_sfml *sfml)
{
	char	*s;
	char	c;
	int32_t	ret;

	ft_draw_header(sfml);
	if (g_state & FLR_FIN)
		return ;
	if (sfml->map_vm != -1 || !read(g_fdmap, &c, 1))
	{
		++sfml->map_vm;
		sfml->fd = g_fdadp;
		g_state |= FLR_LOSE;
	}
	else
		++sfml->map_pl;
	while ((ret = get_next_line(sfml->fd, &s)) && (*s != '+'))
		free(s);
	if (ret > 0)
	{
		ft_get_shape(sfml, sfml->height);
		free(s);
	}
	else
		g_state |= FLR_FIN;
	return ;
}
