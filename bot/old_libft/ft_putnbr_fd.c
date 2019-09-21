/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 04:42:04 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/07 05:08:23 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_rec_fd(int n, char is_neg, int fd)
{
	if (n == 0)
		return (is_neg) ? ft_putchar_fd('-', fd) : 0;
	ft_putnbr_rec_fd(n / 10, is_neg, fd);
	return (is_neg) ? ft_putchar_fd(-(n % 10) + 48, fd)
	: ft_putchar_fd(n % 10 + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putnbr_rec_fd(n, 't', fd);
	else if (n > 0)
		ft_putnbr_rec_fd(n, '\0', fd);
	else
		ft_putchar_fd('0', fd);
}
