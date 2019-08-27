/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 23:52:37 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/03 23:52:39 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = -1;
	while (++idx < n)
	{
		if (*(unsigned char *)(s1 + idx) != *(unsigned char *)(s2 + idx))
		{
			return (*(unsigned char *)(s1 + idx)
							- *(unsigned char *)(s2 + idx));
		}
	}
	return (0);
}
