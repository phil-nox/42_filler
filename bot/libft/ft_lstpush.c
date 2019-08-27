/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:55:56 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/07 00:02:48 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpush(t_list **alst, void const *content, size_t content_size)
{
	t_list *tmp;

	tmp = ft_lstnew(content, content_size);
	if (tmp)
		ft_lstadd(alst, ft_lstnew(content, content_size));
}
