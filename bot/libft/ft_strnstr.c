/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:09:24 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 22:09:26 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	idx_trg;

	idx = 0;
	if (!*needle)
		return (char *)(haystack + idx);
	while (haystack[idx] && idx < len)
	{
		idx_trg = 0;
		if (haystack[idx] == needle[idx_trg])
		{
			while (needle[idx_trg] && idx + idx_trg < len)
			{
				if (haystack[idx + idx_trg] != needle[idx_trg])
					break ;
				idx_trg++;
			}
			if (!needle[idx_trg])
				return (char *)(haystack + idx);
		}
		idx++;
	}
	return (NULL);
}
