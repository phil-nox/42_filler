/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_d1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 19:42:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_length(t_task *input, va_list *ap, long long *target)
{
	if (input->type == 'D')
		*target = (long)va_arg(*ap, long);
	else if (input->length == 'i')
		*target = (char)va_arg(*ap, int);
	else if (input->length == 'h')
		*target = (short)va_arg(*ap, int);
	else if (input->length == 'l')
		*target = (long)va_arg(*ap, long);
	else if (input->length == 'm')
		*target = (long long)va_arg(*ap, long long);
	else if (input->length == 'z')
		*target = (size_t)va_arg(*ap, long long);
	else if (input->length == 'j')
		*target = (intmax_t)va_arg(*ap, long long);
	else
		*target = va_arg(*ap, int);
}

int			make_d(t_task *input, va_list *ap)
{
	char		str[65];
	long long	target;
	int			len;
	int			len_num;

	set_length(input, ap, &target);
	ft_baseitoasign(str, target, 10);
	input->tmp = str;
	len_num = length_utf8(str);
	len = (input->precision > len_num) ? input->precision : len_num;
	if (input->precision == 0 && target == 0)
		len = 0;
	make_d_job(input, len, len_num, target);
	if (input->plus || input->space || target < 0)
		len++;
	return (input->width > len) ? input->width : len;
}
