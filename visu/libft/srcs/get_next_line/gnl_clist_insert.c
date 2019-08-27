#include "get_next_line.h"

t_lists	*ft_clist_insert(t_clist *clist, t_lists *current, void *data)
{
	t_lists	*new;
	t_lists	*tmp;

	if (!clist || !current)
		return (NULL);
	if (!(new = ft_clist_new(clist, data)))
		return (NULL);
	if (current->next)
		tmp = current->next;
	else
		tmp = current;
	current->next = new;
	new->next = tmp;
	return (new);
}
