/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:50:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/19 23:46:41 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lstlen_rec(t_list *lst, size_t count)
{
	if (!lst)
		return (count);
	return (ft_lstlen_rec(lst->next, count + 1));
}

size_t			ft_lstlen(t_list *lst)
{
	if (!lst)
		return (0);
	return (ft_lstlen_rec(lst->next, 1));
}
