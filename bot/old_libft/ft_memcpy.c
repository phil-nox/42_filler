/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:23:01 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/14 02:54:52 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t idx;

	if (dst == src)
		return (dst);
	idx = -1;
	while (++idx < n)
	{
		*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
	}
	return (dst);
}
