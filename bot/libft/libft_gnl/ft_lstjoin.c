/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 06:49:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/14 00:08:15 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ljr(t_list *lst, char *joint, size_t len, char is_f)
{
	char	*out;
	size_t	idx;
	size_t	j_l;

	out = NULL;
	j_l = ft_strlen(joint);
	if (!lst)
	{
		if (len == (size_t)-1 && !(out = (char *)malloc(len + 1)))
			return (NULL);
		out[len] = '\0';
		return (out);
	}
	if (!(out = (is_f) ? ft_ljr(lst->next, joint, len + lst->content_size - 1,
	'\0') : ft_ljr(lst->next, joint, len + lst->content_size + j_l - 1, '\0')))
		return (NULL);
	idx = -1;
	while (!is_f && ++idx < j_l)
		out[len + idx] = joint[idx];
	idx = (is_f) ? -1 : idx - 1;
	while (!is_f && ++idx < lst->content_size + j_l - 1)
		out[len + idx] = ((char *)lst->content)[idx - j_l];
	while (is_f && ++idx < lst->content_size - 1)
		out[len + idx] = ((char *)lst->content)[idx];
	return (out);
}

char		*ft_lstjoin(t_list *lst, char *joint)
{
	if (!lst || !joint)
		return (NULL);
	return (ft_ljr(lst, joint, 0, 't'));
}
