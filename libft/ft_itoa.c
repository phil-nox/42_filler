/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:27:42 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/10 01:36:56 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_rec(int n, char is_neg, int count, int *total)
{
	char *out;

	if (n == 0)
	{
		out = (is_neg) ? (char *)malloc(count + 2) : (char *)malloc(count + 1);
		if (!out)
			return (NULL);
		*total = (is_neg) ? count : count - 1;
		count = (is_neg) ? count + 1 : count;
		out[count] = '\0';
		if (is_neg)
			out[0] = '-';
		return (out);
	}
	out = ft_itoa_rec(n / 10, is_neg, count + 1, total);
	if (!out)
		return (NULL);
	out[*total - count] = (is_neg) ? -(n % 10) + 48 : n % 10 + 48;
	return (out);
}

char		*ft_itoa(int n)
{
	int		total;
	char	*out;

	total = 0;
	if (n < 0)
		return (ft_itoa_rec(n, 't', 0, &total));
	else if (n > 0)
		return (ft_itoa_rec(n, '\0', 0, &total));
	else
	{
		out = (char *)malloc(2);
		if (!out)
			return (NULL);
		out[0] = '0';
		out[1] = '\0';
		return (out);
	}
}
