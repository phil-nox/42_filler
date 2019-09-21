/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/19 16:20:02 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	make_c(t_task *input, va_list *ap)
{
	char c;

	if (input->type == '%')
		c = '%';
	else
		c = va_arg(*ap, int);
	if (input->width < 2)
	{
		ft_putchar_simple(c);
		return (1);
	}
	if (input->minus)
	{
		ft_putchar_simple(c);
		fill(' ', input->width - 1);
	}
	else
	{
		fill(input->zero, input->width - 1);
		ft_putchar_simple(c);
	}
	return (input->width) ? input->width : 1;
}
