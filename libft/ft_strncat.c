/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 03:49:57 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/05 22:55:22 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	idx;
	size_t	idx_src;

	idx = 0;
	idx_src = 0;
	while (s1[idx])
	{
		idx++;
	}
	while (idx_src < n && s2[idx_src])
	{
		s1[idx] = s2[idx_src];
		idx++;
		idx_src++;
	}
	s1[idx] = '\0';
	return (s1);
}
