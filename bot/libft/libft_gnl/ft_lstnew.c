/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 07:26:57 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/09 22:25:30 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*out;

	out = (t_list *)malloc(sizeof(t_list));
	if (!out)
		return (NULL);
	if (!content)
	{
		out->content = NULL;
		out->content_size = 0;
		out->next = NULL;
		return (out);
	}
	out->content = malloc(content_size);
	if (!(out->content))
	{
		free(out);
		return (NULL);
	}
	ft_memcpy(out->content, content, content_size);
	out->content_size = content_size;
	out->next = NULL;
	return (out);
}
