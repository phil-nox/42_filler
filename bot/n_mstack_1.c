/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_mstack_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:44:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 21:49:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "n_mstack.h"

int		free_mstack_job(t_list **lst, void *to_free)
{
	t_list	*to_del;

	if (!lst || !*lst || !to_free)
		return (0);
	if ((*lst)->content == to_free)
	{
		to_del = (*lst);
		*lst = (*lst)->next;
		if (to_del->content)
			free(to_del->content);
		free(to_del);
		return (1);
	}
	if ((*lst)->next->content == to_free)
	{
		to_del = (*lst)->next;
		(*lst)->next = (*lst)->next->next;
		if (to_del->content)
			free(to_del->content);
		free(to_del);
		return (1);
	}
	return (ft_lstfreeone(&((*lst)->next), to_free));
}

int		free_mstack(void *to_free)
{
	return (free_mstack_job(get_mstack(), to_free));
}

void	free_all_mstack_job(t_list *mstack)
{
	t_list *to_del;

	if (!mstack)
		return ;
	to_del = mstack;
	mstack = (mstack)->next;
	if (to_del->content)
		free(to_del->content);
	free(to_del);
	free_all_mstack_job(mstack);
}

int		free_all_mstack(void)
{
	t_list **mstack;

	mstack = get_mstack();
	if (!mstack || !*mstack)
		return (1);
	free_all_mstack_job(*mstack);
	*mstack = NULL;
	return (1);
}
