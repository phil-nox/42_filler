/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 06:53:23 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/10 02:56:58 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strmapi_rec(char const *s, char (*f)(unsigned int, char),
			unsigned int count, unsigned int idx)
{
	char *out;
	char tmp;

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
	tmp = f(idx, *s);
	out = ft_strmapi_rec(s + 1, f, count + 1, idx + 1);
	if (out)
		out[count] = tmp;
	return (out);
}

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	if (!s || !f)
		return (NULL);
	return (ft_strmapi_rec(s, f, 0, 0));
}
