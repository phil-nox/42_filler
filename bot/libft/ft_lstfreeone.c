/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfreeone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 20:20:55 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/20 01:56:10 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfreeone(t_list **lst, t_list *to_free)
{
	if (!lst || !*lst || !to_free || !to_free)
		return (0);
	if (*lst == to_free)
	{
		*lst = to_free->next;
		if (to_free->content)
			free(to_free->content);
		free(to_free);
		return (1);
	}
	if ((*lst)->next == to_free)
	{
		(*lst)->next = to_free->next;
		if (to_free->content)
			free(to_free->content);
		free(to_free);
		return (1);
	}
	return (ft_lstfreeone(&((*lst)->next), to_free));
}
