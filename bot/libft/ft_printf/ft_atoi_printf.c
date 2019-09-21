/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:01:05 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:43:55 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	ten_pow(int n)
{
	if (n < 1)
		return (1);
	return (ten_pow(n - 1) * 10);
}

static char	*skip_spaces(char *str)
{
	if (*str != '\t' && *str != '\n' && *str != '\v' &&
			*str != '\f' && *str != '\r' && *str != ' ')
		return (str);
	return (skip_spaces(str + 1));
}

static long	ft_atoi_rec(const char *str, int count, long *order, char *red_flag)
{
	long	out;

	if (*str < 48 || *str > 57)
	{
		*order = count - 1;
		return (0);
	}
	out = ft_atoi_rec((char *)str + 1, count + 1, order, red_flag);
	if (2147483648 - out - ((*str - 48) * ten_pow(*order - count)) < 0)
		*red_flag = 't';
	out += (*str - 48) * ten_pow(*order - count);
	return (out);
}

int			ft_atoi_printf(const char *str, int *add_total)
{
	long tmp;
	long out;
	char red_flag;
	char *work;

	work = skip_spaces((char *)str);
	red_flag = 'f';
	tmp = 0;
	if (*work == '-' || *work == '+')
		out = ft_atoi_rec(work + 1, 0, &tmp, &red_flag);
	else if (*work > 47 && *work < 58)
		out = ft_atoi_rec(work, 0, &tmp, &red_flag);
	else
		return (0);
	*add_total = (*work == '-') ? tmp + 2 : tmp + 1;
	if (red_flag == 't')
		return (-1);
	return (*work == '-') ? (-(int)out) : ((int)out);
}
