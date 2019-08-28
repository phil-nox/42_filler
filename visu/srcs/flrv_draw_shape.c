/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_draw_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:43:07 by laleta            #+#    #+#             */
/*   Updated: 2019/08/28 05:22:29 by laleta           ###   ########.fr       */
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

static uint8_t	ft_get_shape(t_sfml *sfml, int cnt)
{
	char		**shape;
	int32_t		i;

	if (!(shape = (char **)malloc(sizeof(*shape) * (cnt + 1))))
		return (1);
	shape[cnt] = NULL;
	i = 0;
	while (i < cnt && get_next_line(g_fdmap, &shape[i]) && shape[i])
		++i;
	ft_set_shape(sfml, shape);
	ft_free_shape(&shape);
	return (0);
}

void			ft_draw_shape(t_sfml *sfml)
{
	char	*s;
	char	c;
	int32_t	ret;

	ft_draw_header(sfml);
	if ((g_state & (FLR_FIN | FLR_PAUS)) || (-1 == read(g_fdmap, &c, 0)))
		return ;
	if (-1 == read(g_fdmap, &c, 0))
		g_fdmap = g_fdadp;
	sfSleep(sfMilliseconds(sfml->speed));
	while ((ret = get_next_line(g_fdmap, &s)) && (*s != '+' || *(s + 1) != '+'))
	{
ft_printf("s=%s\n", s); 
		if (*s == '+' && *(s + 1) == '-')
		{
	//		g_fdmap = 0;							//??
	//		ft_init_player_name(sfml->p2, g_fdmap);	//STDIN => p2 name
			g_state |= (FLR_FIN | FLR_LOSE);
			close(g_fdmap);
			return ;
		}
		free(s);
	}
	if (ret > 0) //&& *s == '+')
	{
		if ((ft_get_shape(sfml, sfml->height)) == 1)
		{
			free(s);
			exit(1);
		}
		free(s);
	}
	return ;
}
