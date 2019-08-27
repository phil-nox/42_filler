/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 02:08:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 02:08:21 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	idx;
	size_t	len_src;

	if (len == 0)
	{
		return (dst);
	}
	len_src = ft_strlen(src);
	idx = 0;
	while (idx < len)
	{
		if (idx < len_src)
		{
			dst[idx] = src[idx];
		}
		else
		{
			dst[idx] = '\0';
		}
		idx++;
	}
	return (dst);
}
