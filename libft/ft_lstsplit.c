/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 02:11:55 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/10 02:08:44 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_start_end_lst(char const *s, char c, size_t from,
	char find_start)
{
	if (find_start)
		return (s[from] != c) ?
		from : word_start_end_lst(s, c, from + 1, find_start);
	else
		return (s[from] == c || s[from] == '\0') ?
			from : word_start_end_lst(s, c, from + 1, find_start);
}

static t_list	*word_cpy_list(char const *s, size_t start, size_t end)
{
	t_list	*out;

	out = ft_lstnew(s + start, end - start + 1);
	((char *)out->content)[end - start] = '\0';
	return (out);
}

static t_list	*ft_lstsplit_rec(char const *s, char c, size_t from, size_t idx)
{
	t_list	*out;
	size_t	start;
	size_t	end;

	start = (s) ? word_start_end_lst(s, c, from, 't') : 0;
	end = (s) ? word_start_end_lst(s, c, start, '\0') : 0;
	if (start == end)
		return (NULL);
	out = ft_lstsplit_rec(s, c, end, idx + 1);
	ft_lstadd(&out, word_cpy_list(s, start, end));
	return (out);
}

t_list			*ft_lstsplit(char const *s, char c)
{
	return (ft_lstsplit_rec(s, c, 0, 0));
}
