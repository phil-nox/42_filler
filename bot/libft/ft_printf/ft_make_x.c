/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	putpreci(t_task *input, int len, int len_num,
	unsigned long long target)
{
	fill('0', len - len_num);
	if (input->precision != 0 || target != 0)
		ft_putstr_p(input->tmp);
}

static void	set_length(t_task *input, va_list *ap, unsigned long long *target)
{
	if (input->length == 'i')
		*target = (unsigned char)va_arg(*ap, int);
	else if (input->length == 'h')
		*target = (unsigned short)va_arg(*ap, int);
	else if (input->length == 'l')
		*target = (unsigned long)va_arg(*ap, long);
	else if (input->length == 'm')
		*target = (unsigned long long)va_arg(*ap, long long);
	else if (input->length == 'z')
		*target = (size_t)va_arg(*ap, long long);
	else if (input->length == 'j')
		*target = (intmax_t)va_arg(*ap, long long);
	else
		*target = (unsigned int)va_arg(*ap, int);
}

static void	puthash(t_task *input, unsigned long long target)
{
	if (target != 0 && input->hash)
		(input->type == 'x') ? ft_putstr_p("0x") : ft_putstr_p("0X");
}

static void	make_x_job(t_task *input, int len, int len_num,
	unsigned long long target)
{
	if (input->minus)
	{
		puthash(input, target);
		putpreci(input, len, len_num, target);
		fill(' ', input->width - len);
	}
	else
	{
		if (input->zero != ' ' && input->precision == -1)
		{
			puthash(input, target);
			fill('0', input->width - len);
		}
		else
		{
			fill(' ', input->width - len);
			puthash(input, target);
		}
		putpreci(input, len, len_num, target);
	}
}

int			make_x(t_task *input, va_list *ap)
{
	char				str[65];
	unsigned long long	target;
	int					len;
	int					len_num;

	set_length(input, ap, &target);
	ft_baseitoa(str, target, 16, (input->type == 'x') ? 0 : 1);
	input->tmp = str;
	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;
	if (input->precision == 0 && target == 0)
		len = 0;
	if (target != 0 && input->hash)
	{
		len += 2;
		len_num += 2;
	}
	make_x_job(input, len, len_num, target);
	return (input->width > len) ? input->width : len;
}
