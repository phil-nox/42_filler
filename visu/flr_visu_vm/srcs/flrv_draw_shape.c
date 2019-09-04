/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_draw_shape.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 01:12:49 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 01:12:50 by laleta           ###   ########.fr       */
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
	unsigned	i;
	char		player;
	t_point		pos;
	char		*tmp;

	if (!(shape = (char **)malloc(sizeof(*shape) * (cnt + 2))))
		return (1);
	shape[cnt + 1] = NULL;
	i = 0;
	while (get_next_line(0, &shape[i]) && shape[i][0] != '<')
		++i;
	tmp = shape[i];
	player = shape[i][6];
	shape[i] += 11;
	pos.y = ft_get_nbr(&shape[i]);
	shape[i] += 2;
	pos.x = ft_get_nbr(&shape[i]);
	shape[i] = tmp;
	ft_set_shape(sfml, &pos, shape, player);
	ft_free_shape(&shape);
	return (0);
}

void			ft_draw_shape(t_sfml *sfml)
{
	char	*s;
	int8_t	ret;

	ft_draw_header(sfml);
	if (g_state & (FLR_FIN | FLR_PAUS))
		return ;
	sfSleep(sfMilliseconds(sfml->speed));
	if (!sfml->line)
		while ((ret = get_next_line(0, &s)) && (*s != 'P' || *(s + 1) != 'i'))
			free(s);
	if (sfml->line || ret > 0)
	{
		if (sfml->line)
		{
			s = sfml->line;
			sfml->line = NULL;
		}
		if ((ft_get_shape(sfml, ft_atoi(s + 5))) == 1)
		{
			free(s);
			exit(1);
		}
		free(s);
	}
	return ;
}
