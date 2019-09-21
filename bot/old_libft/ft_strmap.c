/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 06:29:09 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/11 14:03:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strmap_rec(char const *s, char (*f)(char), unsigned int count)
{
	char *out;

	if (!f)
		return (NULL);
	if (!*s)
	{
		out = malloc(count + 1);
		if (!out)
			return (NULL);
		out[count] = '\0';
		return (out);
	}
	out = ft_strmap_rec(s + 1, f, count + 1);
	if (out)
		out[count] = f(*s);
	return (out);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	if (!s || !f)
		return (NULL);
	return (ft_strmap_rec(s, f, 0));
}
