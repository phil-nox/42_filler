/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 17:05:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	make_bc(t_task *input, va_list *ap)
{
	wchar_t	c;
	int		len;

	c = va_arg(*ap, wchar_t);
	len = unicodestep(c);
	if (!len)
		len = 1;
	if (input->width < len)
	{
		unicode2utf8(c);
		return (len);
	}
	if (input->minus)
	{
		unicode2utf8(c);
		fill(' ', input->width - len);
	}
	else
	{
		fill(input->zero, input->width - len);
		unicode2utf8(c);
	}
	return (input->width > len) ? input->width : len;
}
