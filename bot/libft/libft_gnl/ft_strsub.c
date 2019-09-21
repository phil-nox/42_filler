/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:11:38 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/11 17:16:56 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	idx;

	if (!s || len == (size_t)-1)
		return (NULL);
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	out[len] = '\0';
	idx = -1;
	while (++idx < len)
		out[idx] = s[start + idx];
	return (out);
}
