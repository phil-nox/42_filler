/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 22:53:52 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/10 01:02:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*bad_way(char const *s, size_t idx)
{
	char	*out;

	if (!s[idx])
		return (ft_strnew(1));
	out = ft_strnew(2);
	if (!out)
		return (NULL);
	out[0] = s[idx];
	return (out);
}

static char	*good_way(char const *s, size_t start, size_t end)
{
	size_t	idx;
	char	*out;

	out = (char *)malloc(end - start + 1);
	if (!out)
		return (NULL);
	idx = -1;
	while (start + ++idx < end)
		out[idx] = s[start + idx];
	out[idx] = '\0';
	return (out);
}

char		*ft_strtrim(char const *s)
{
	size_t	idx;
	size_t	start;

	if (!s)
		return (NULL);
	idx = 0;
	while (s[idx] && (s[idx] == ' ' || s[idx] == '\n' || s[idx] == '\t')
		&& idx < (size_t)-1)
		idx++;
	if (!s[idx] || idx == (size_t)-1)
		return (bad_way(s, idx));
	start = idx;
	while (s[idx] && idx < (size_t)-1)
		idx++;
	while ((s[idx] == ' ' || s[idx] == '\n' || s[idx] == '\t'
		|| s[idx] == '\0') && idx > start)
		idx--;
	idx++;
	return (good_way(s, start, idx));
}
