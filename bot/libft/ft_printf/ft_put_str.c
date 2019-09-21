/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_p(char const *s)
{
	int idx;
	int printed;

	if (!s)
		return (0);
	printed = 0;
	idx = 0;
	while (*(s + idx))
	{
		idx += ft_pututf8(s + idx);
		printed++;
	}
	return (UTF8COUNT) ? (printed) : idx;
}

int	ft_putstrn(char const *s, int len)
{
	int idx;
	int printed;

	if (!s)
		return (0);
	printed = 0;
	idx = 0;
	while (*(s + idx) && printed < len)
	{
		idx += ft_pututf8(s + idx);
		printed++;
		if (!UTF8COUNT)
			printed = idx;
	}
	return (printed);
}
