#include "get_next_line.h"

t_lists	*ft_clist_find_prev(t_lists *wall)
{
	t_lists	*list;

	if (!wall || !wall->next)
		return (NULL);
	list = wall->next;
	while (list->next != wall)
		list = list->next;
	return (list);
}
