/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:33:32 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/03 23:33:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	idx;

	idx = -1;
	while (++idx < n)
	{
		if (*(unsigned char *)(s + idx) == (unsigned char)c)
		{
			return (void *)(s + idx);
		}
	}
	return (NULL);
}
