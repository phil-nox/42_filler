/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 23:52:28 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/08 10:59:53 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *out;

	out = NULL;
	if (!lst || !f)
		return (NULL);
	out = ft_lstmap(lst->next, f);
	ft_lstadd(&out, f(lst));
	return (out);
}
