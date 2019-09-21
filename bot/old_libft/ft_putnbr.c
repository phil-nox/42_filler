/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 04:29:27 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/07 05:09:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec(int n, char is_neg)
{
	if (n == 0)
		return (is_neg) ? ft_putchar('-') : 0;
	ft_putnbr_rec(n / 10, is_neg);
	return (is_neg) ? ft_putchar(-(n % 10) + 48) : ft_putchar(n % 10 + 48);
}

void		ft_putnbr(int n)
{
	if (n < 0)
		ft_putnbr_rec(n, 't');
	else if (n > 0)
		ft_putnbr_rec(n, '\0');
	else
		ft_putchar('0');
}
