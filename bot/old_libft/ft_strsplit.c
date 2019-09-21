/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 01:32:51 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/10 02:23:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_start_end(char const *s, char c, size_t from,
		char find_start)
{
	if (find_start)
		return (s[from] != c) ?
		from : word_start_end(s, c, from + 1, find_start);
	else
		return (s[from] == c || s[from] == '\0') ?
			from : word_start_end(s, c, from + 1, find_start);
}

static void		cpy_job(char *out, char const *s, size_t start, size_t end)
{
	if (start == end)
	{
		*out = '\0';
		return ;
	}
	*out = s[start];
	cpy_job(out + 1, s, start + 1, end);
}

static char		*word_cpy(char const *s, size_t start, size_t end)
{
	char *out;

	out = (char *)malloc(end - start + 1);
	if (!out)
		return (NULL);
	cpy_job(out, s, start, end);
	return (out);
}

static char		**ft_strsplit_rec(char const *s, char c, size_t from,
		size_t idx)
{
	char	**out;
	size_t	start;
	size_t	end;

	start = (s) ? word_start_end(s, c, from, 't') : 0;
	end = (s) ? word_start_end(s, c, start, '\0') : 0;
	if (start == end)
	{
		if (!(out = (char **)malloc(sizeof(char *) * (idx + 1))))
			return (NULL);
		out[idx] = NULL;
		return (out);
	}
	out = ft_strsplit_rec(s, c, end, idx + 1);
	if (!out)
		return (NULL);
	out[idx] = word_cpy(s, start, end);
	if (!out[idx])
	{
		while (out[++idx])
			free(out[idx]);
		free(out);
		return (NULL);
	}
	return (out);
}

char			**ft_strsplit(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_strsplit_rec(s, c, 0, 0));
}
