#include "libft.h"
#include "__mstack.h"

t_list	**get_mstack(void)
{
	static t_list	*mstack;

	return (&mstack);
}

int	free_mstack_job(t_list **lst, void *to_free)
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

int	free_mstack(void *to_free)
{
	return (free_mstack_job(get_mstack(), to_free));
}

void	free_all_mstack(void)
{
	t_list **mstack;
	t_list *to_del;

	mstack = get_mstack();
	if (!mstack || !*mstack)
		return ;
	to_del = *mstack;
	*mstack = (*mstack)->next;
	if (to_del->content)
		free(to_del->content);
	free(to_del);
	free_all_mstack();
}

int	add_mstack(void *to_add)
{
	t_list	*add;

	if (!to_add)
	{
		free_all_mstack();
		return (1);
	}
	add = ft_lstnew(NULL, 0);
	if (!add)
	{
		free(to_add);
		free_all_mstack();
		return (1);
	}
	add->content = to_add;
	ft_lstadd(get_mstack(), add);
	return (0);
}
