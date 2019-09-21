/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:48:43 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/14 02:58:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
			size_t n)
{
	size_t	idx;

	if (dst == src)
		return (dst);
	idx = 0;
	while (idx < n)
	{
		*(unsigned char *)(dst + idx) = *(unsigned char *)(src + idx);
		if (*(unsigned char *)(src + idx) == (unsigned char)c)
		{
			return (dst + idx + 1);
		}
		idx++;
	}
	return (NULL);
}
