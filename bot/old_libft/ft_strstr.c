/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:25:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 21:25:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	idx;
	size_t	idx_trg;

	idx = 0;
	if (!*needle)
		return (char *)(haystack + idx);
	while (haystack[idx])
	{
		idx_trg = 0;
		if (haystack[idx] == needle[idx_trg])
		{
			while (needle[idx_trg])
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
