/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:48:14 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_utf8step(char const *s)
{
	int idx;

	idx = 1;
	if ((*s & 0xC0) == 0xC0)
		idx = 2;
	if ((*s & 0xE0) == 0xE0)
		idx = 3;
	if ((*s & 0xF0) == 0xF0)
		idx = 4;
	return (idx);
}

int	ft_pututf8(char const *s)
{
	int idx;
	int tmp;

	if (UTF8COUNT == 0)
	{
		write_boost(s, 0);
		return (1);
	}
	idx = 1;
	if ((*s & 0xC0) == 0xC0)
		idx = 2;
	if ((*s & 0xE0) == 0xE0)
		idx = 3;
	if ((*s & 0xF0) == 0xF0)
		idx = 4;
	tmp = 0;
	while (tmp < idx)
		write_boost(s + tmp++, 0);
	return (idx);
}

int	ft_putchar_simple(char c)
{
	return (write_boost(&c, 0));
}

int	ft_putchar_p(int c)
{
	return (ft_pututf8((char *)&c));
}
