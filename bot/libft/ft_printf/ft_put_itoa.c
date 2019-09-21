/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/27 00:23:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	quick_end(char *out)
{
	out[0] = '0';
	out[1] = '\0';
}

void		ft_baseitoa(char *out, unsigned long long target,
	unsigned char base, char big)
{
	char				*code;
	char				rev_out[65];
	unsigned long long	rest;
	unsigned long long	idx;

	if (base < 2)
		return (quick_end(out));
	code = "0123456789abcdef";
	if (big)
		code = "0123456789ABCDEF";
	idx = 0;
	while ((rest = target / base) != 0)
	{
		rev_out[idx++] = code[target % base];
		target = rest;
	}
	rev_out[idx++] = code[target % base];
	rest = idx;
	while (idx > 0)
	{
		out[rest - idx] = rev_out[idx - 1];
		idx--;
	}
	out[rest] = '\0';
}

void		ft_baseitoasign(char *out, long long target, unsigned char base)
{
	char				*code;
	char				rev_out[65];
	long long			rest;
	unsigned long long	idx;

	if (base < 2)
		return (quick_end(out));
	code = "0123456789abcdef";
	idx = 0;
	while ((rest = target / base) != 0)
	{
		rev_out[idx++] = (target < 0) ? code[-(target % base)]
			: code[target % base];
		target = rest;
	}
	rev_out[idx++] = (target < 0) ? code[-(target % base)]
		: code[target % base];
	rest = idx;
	while (idx > 0)
	{
		out[rest - idx] = rev_out[idx - 1];
		idx--;
	}
	out[rest] = '\0';
}
