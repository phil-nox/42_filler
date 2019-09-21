/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 02:41:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_rec(int n, char is_neg)
{
	if (n == 0)
	{
		if (is_neg)
			ft_putchar_p('-');
		return ;
	}
	ft_putnbr_rec(n / 10, is_neg);
	if (is_neg)
		ft_putchar_p(-(n % 10) + 48);
	else
		ft_putchar_p(n % 10 + 48);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putnbr_rec(n, 't');
	else if (n > 0)
		ft_putnbr_rec(n, '\0');
	else
		ft_putchar_p('0');
}

void		ft_putunbr(unsigned long n)
{
	if (n == 0)
		return ;
	ft_putunbr(n / 10);
	ft_putchar_p(n % 10 + 48);
}

void		print_arr(short *list, int size)
{
	int idx;

	idx = -1;
	ft_putstr_p("[ ");
	while (++idx < size)
	{
		ft_putnbr(list[idx]);
		ft_putstr_p(", ");
	}
	ft_putstr_p("]");
}
