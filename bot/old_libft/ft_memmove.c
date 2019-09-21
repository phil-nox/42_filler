/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 20:16:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/14 01:42:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_backward(void *dst, const void *src, size_t len)
{
	while (--len > 0)
	{
		*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;

	if (dst == src)
		return (dst);
	idx = 0;
	while (idx < len)
	{
		if (src + idx == dst)
		{
			return (ft_memmove_backward(dst, src, len));
		}
		idx++;
	}
	idx = 0;
	while (idx < len)
	{
		*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
		idx++;
	}
	return (dst);
}
