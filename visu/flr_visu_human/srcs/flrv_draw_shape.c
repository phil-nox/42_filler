/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_draw_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:43:07 by laleta            #+#    #+#             */
/*   Updated: 2019/09/18 16:03:30 by laleta           ###   ########.fr       */
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
//int32_t	flags;

	ft_draw_header(sfml);
	if (g_state & FLR_FIN)
		return ;
	if (sfml->map_vm != -1 || !read(g_fdmap, &c, 1))
	{
		++sfml->map_vm;
		sfml->fd = g_fdadp;
		g_state |= FLR_LOSE;
	}
/*if (!(g_state & FLR_NAME) && sfml->fd != g_fdadp && (ret = read(g_fdadp, &c, 1)) == 1)
{
	ft_init_player_name(sfml->p1, g_fdadp, 1);
	ft_init_player_name(sfml->p2, g_fdadp, 0);
	flags = fcntl(g_fdadp, F_GETFL, 0);
	flags &= ~O_NONBLOCK;
	fcntl(g_fdadp, F_SETFL, flags);
	g_state |= FLR_NAME;
}*/
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
