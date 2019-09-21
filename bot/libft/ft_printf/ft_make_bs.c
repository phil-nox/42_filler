/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:36:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 17:11:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	no_precision_case(t_task *input, wchar_t *str, int *len)
{
	int idx;
	int tmp;
	int tmp_old;

	tmp_old = 0;
	*len = 0;
	idx = 0;
	while (tmp_old != (tmp = len_unicode_by_symbole(str, ++idx)))
	{
		if (tmp > input->precision)
			break ;
		*len = tmp;
		tmp_old = tmp;
	}
}

int			make_bs(t_task *input, va_list *ap)
{
	wchar_t	*str;
	int		len;

	str = va_arg(*ap, wchar_t *);
	if (!str)
		str = L"(null)";
	len = length_unicode(str);
	if (input->precision != -1 && input->precision < len)
		no_precision_case(input, str, &len);
	if (input->width > len)
	{
		if (input->minus)
		{
			ft_putunicode(str, len);
			fill(' ', input->width - len);
		}
		else
		{
			fill(input->zero, input->width - len);
			ft_putunicode(str, len);
		}
	}
	else
		ft_putunicode(str, len);
	return (input->width > len) ? input->width : len;
}
