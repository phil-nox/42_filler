/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 04:05:04 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/17 02:33:19 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	calc_len(char *dst, const char *src,
	size_t size)
{
	size_t	idx;
	size_t	idx_src;

	idx = 0;
	idx_src = 0;
	while (dst && idx < size && dst[idx])
	{
		idx++;
	}
	while (src && src[idx_src])
	{
		idx++;
		idx_src++;
	}
	return (idx);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	idx;
	size_t	idx_src;
	size_t	out;

	out = calc_len(dst, src, size);
	idx = 0;
	idx_src = 0;
	if (size == 0)
	{
		return (out);
	}
	while (dst[idx])
	{
		idx++;
	}
	while (src[idx_src] && idx < size - 1)
	{
		dst[idx] = src[idx_src];
		idx++;
		idx_src++;
	}
	dst[idx] = '\0';
	return (out);
}
