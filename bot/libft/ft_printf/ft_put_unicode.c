/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unicode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			unicodestep(wchar_t tmp)
{
	int out;

	if (tmp < 128)
		out = 1;
	else if (tmp < 2048)
		out = 2;
	else if (tmp < 65536)
		out = 3;
	else
		out = 4;
	return (out);
}

static void	set_unicode2utf8(wchar_t tmp, char to_print[5])
{
	if (tmp < 128)
		to_print[0] = tmp & 0x7F;
	else if (tmp < 2048)
	{
		to_print[1] = 0x80 | (tmp & 0x3F);
		to_print[0] = 0xC0 | ((tmp >> 6) & 0x1F);
	}
	else if (tmp < 65536)
	{
		to_print[2] = 0x80 | (tmp & 0x3F);
		to_print[1] = 0x80 | ((tmp >> 6) & 0x3F);
		to_print[0] = 0xE0 | ((tmp >> 12) & 0xF);
	}
	else
	{
		to_print[3] = 0x80 | (tmp & 0x3F);
		to_print[2] = 0x80 | ((tmp >> 6) & 0x3F);
		to_print[1] = 0x80 | ((tmp >> 12) & 0x3F);
		to_print[0] = 0xF0 | ((tmp >> 18) & 0x7);
	}
}

int			unicode2utf8(wchar_t tmp)
{
	int		idx;
	char	to_print[5];

	if (tmp == 0)
		return (ft_putchar_p(0));
	idx = -1;
	while (++idx < 5)
		to_print[idx] = 0;
	set_unicode2utf8(tmp, to_print);
	return (ft_putstr_p(to_print));
}

int			ft_putunicode(wchar_t *s, int len)
{
	int idx;
	int printed;

	if (!s)
		return (0);
	printed = 0;
	idx = 0;
	while (*(s + idx) && printed < len)
	{
		printed += unicode2utf8(*(s + idx));
		++idx;
	}
	return (!UTF8COUNT) ? (printed) : idx;
}
