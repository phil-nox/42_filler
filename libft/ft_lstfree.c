/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 01:28:55 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/20 01:32:09 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	if (!lst || !*lst)
		return ;
	ft_lstfree(&((*lst)->next));
	if ((*lst)->content)
		free((*lst)->content);
	free((*lst));
	*lst = NULL;
}
