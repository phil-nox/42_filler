/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strajoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 08:21:18 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/07 08:21:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strajoin_rec(char **arr, size_t len, size_t idx)
{
	char *out;

	if (*arr == NULL)
		return (NULL);
	if (!*(*arr + idx))
	{
		out = ft_strajoin_rec(arr + 1, len, 0);
		if (out)
			return (out);
		out = (char *)malloc(len + 1);
		if (!out)
			return (NULL);
		out[len] = '\0';
		return (out);
	}
	out = ft_strajoin_rec(arr, len + 1, idx + 1);
	if (!out)
		return (NULL);
	out[len] = *(*arr + idx);
	return (out);
}

char		*ft_strajoin(char **arr)
{
	return (ft_strajoin_rec(arr, 0, 0));
}
