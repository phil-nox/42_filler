/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprintstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 03:30:38 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/07 05:11:50 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putstrsize_rec(char const *s, size_t count, size_t lim)
{
	if (!s || count == lim)
		return ;
	if (*s)
	{
		ft_putchar(*s);
		ft_putstrsize_rec(s + 1, count + 1, lim);
	}
}

static void	ft_putstrsize(char const *s, size_t lim)
{
	ft_putstrsize_rec(s, 0, lim);
}

void		ft_lstprintstr(t_list *elem)
{
	if (!elem)
	{
		ft_putstr("NULL");
		return ;
	}
	ft_putstrsize(elem->content, elem->content_size);
	ft_putstr(" ->");
	ft_lstprintstr(elem->next);
}
