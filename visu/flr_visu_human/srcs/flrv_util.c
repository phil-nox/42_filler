/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flrv_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:59:25 by laleta            #+#    #+#             */
/*   Updated: 2019/09/18 18:47:07 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flr_visual.h"

int8_t		ft_check_loadfile(int32_t argc, char **argv)
{
	int32_t		i;
	struct stat	st;

	i = -1;
	i += argc > 3 ? 2 : argc - 1;
	while (g_flr_loadfile[++i][0])
	{
		if (stat(g_flr_loadfile[i], &st) == -1)
		{
			ft_printf(F_RED "%s: %s: %s\n" NONE, argv[0], g_flr_loadfile[i],
															strerror(errno));
			return (0);
		}
	}
	i = -1;
	while (++i < argc - 1 && i < 2)
	{
		if (stat(argv[i + 1], &st) == -1)
		{
			ft_printf(F_RED "%s: %s: %s\n" NONE, argv[0], argv[i + 1],
															strerror(errno));
			return (0);
		}
	}
	return (1);
}

int32_t		ft_get_nbr(char **s)
{
	int32_t	n;
	int32_t	sign;

	while (**s == ' ')
		++*s;
	sign = (**s == '-');
	if (**s == '+' || **s == '-')
		++*s;
	n = (ft_isdigit(**s)) ? (*(*s)++ - 48) : 0;
	while (ft_isdigit(**s))
		n = (n * 10) + *(*s)++ - 48;
	return (sign ? -n : n);
}

void		ft_get_size(int32_t *width, int32_t *height)
{
	char	*s;
	char	*tmp;

	while (get_next_line(g_fdadp, &s) && *s != 'P')
		free(s);
	tmp = s;
	s += 7;
	*height = ft_get_nbr(&s);
	*width = ft_get_nbr(&s);
	free(tmp);
}

void		ft_name_norm(char *s)
{
	while (*s)
	{
		if (*s == '_')
			*s = ' ';
		s++;
	}
}
