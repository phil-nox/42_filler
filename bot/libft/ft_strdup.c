/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:30:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/14 03:43:40 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	len;

	len = ft_strlen(s1);
	if (len == (size_t)-1)
		return (NULL);
	out = (char *)malloc(len + 1);
	if (!out)
	{
		return (NULL);
	}
	out[len] = '\0';
	if (!len)
	{
		return (out);
	}
	while (--len > 0)
	{
		out[len] = s1[len];
	}
	out[len] = s1[len];
	return (out);
}
