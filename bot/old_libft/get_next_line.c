/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:43:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:48:20 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/syslimits.h>

int		line_taken(t_list **cur, size_t idx)
{
	void	*cutted;

	if (idx >= (*cur)->content_size - 1)
	{
		free((*cur)->content);
		free(*cur);
		*cur = NULL;
		return (0);
	}
	(*cur)->content_size -= (idx + 1);
	if (!(cutted = ft_memalloc((*cur)->content_size)))
		return (-1);
	ft_memcpy(cutted, (*cur)->content + idx + 1, (*cur)->content_size);
	free((*cur)->content);
	(*cur)->content = cutted;
	return (0);
}

int		get_line_rec(char **out, t_list *cur, size_t count, size_t *total)
{
	if (!cur)
	{
		*total = count;
		if (!(*out = ft_strnew(count)))
			return (-1);
		return (1);
	}
	if (get_line_rec(out, cur->next, count + cur->content_size, total) == 1)
	{
		cur->next = NULL;
		ft_memcpy(*out + *total - count - cur->content_size,
			(char *)(cur->content), cur->content_size);
		free(cur->content);
		free(cur);
		return (1);
	}
	return (-1);
}

int		get_line_while(char **out, t_list *lst, size_t count, size_t *total)
{
	t_list *cur;
	t_list *tmp;

	cur = lst;
	while (cur)
	{
		*total = *total + cur->content_size;
		cur = cur->next;
	}
	if (!cur)
		if (!(*out = ft_strnew(*total)))
			return (-1);
	cur = lst;
	while (cur)
	{
		ft_memcpy(*out + *total - count - cur->content_size,
			(char *)(cur->content), cur->content_size);
		count += cur->content_size;
		tmp = cur->next;
		free(cur->content);
		free(cur);
		cur = tmp;
	}
	return (1);
}

int		get_line(char **out, t_list **lst, char last_call)
{
	size_t	total;
	size_t	idx;
	int		rls;

	if (!*lst)
		return (0);
	idx = 0;
	while (idx < (*lst)->content_size)
	{
		if (((char *)(*lst)->content)[idx] == '\n' || last_call)
		{
			if (last_call)
				idx = (*lst)->content_size;
			total = idx;
			rls = (get_line_while(out, (*lst)->next, idx, &total));
			if (rls == -1)
				return (-1);
			(*lst)->next = NULL;
			ft_memcpy(*out + total - idx, (char *)((*lst)->content), idx);
			return (line_taken(lst, idx)) ? -1 : rls;
		}
		idx++;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*tab_fd[OPEN_MAX];
	char			buf[BUFF_SIZE];
	int				rlt;

	if (fd < 0 || !line || fd >= OPEN_MAX)
		return (-1);
	rlt = 0;
	*line = NULL;
	if (tab_fd[fd])
		if ((rlt = get_line(line, tab_fd + fd, '\0') == 1))
			return (1);
	if ((rlt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_lstadd((tab_fd + fd), ft_lstnew(buf, rlt));
		while ((rlt = get_line(line, tab_fd + fd, '\0')) == 0
				&& (rlt = read(fd, buf, BUFF_SIZE)) > 0)
			ft_lstadd((tab_fd + fd), ft_lstnew(buf, rlt));
	}
	if (rlt == 0)
		rlt = get_line(line, tab_fd + fd, 't');
	if (rlt != 1)
		ft_lstfree((tab_fd + fd));
	return (rlt);
}
