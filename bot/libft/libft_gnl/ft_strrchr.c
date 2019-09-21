/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 21:07:16 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 21:07:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	idx;

	idx = 0;
	while (s[idx])
	{
		idx++;
	}
	while (idx > 0)
	{
		if (s[idx] == (char)c)
		{
			return (char *)(s + idx);
		}
		idx--;
	}
	if (s[idx] == (char)c)
	{
		return (char *)(s + idx);
	}
	return (NULL);
}
