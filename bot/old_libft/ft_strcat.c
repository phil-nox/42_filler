/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 03:23:02 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 03:23:04 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict s1, const char *restrict s2)
{
	size_t	idx;
	size_t	idx_src;

	idx = 0;
	idx_src = 0;
	while (s1[idx])
	{
		idx++;
	}
	while (s2[idx_src])
	{
		s1[idx] = s2[idx_src];
		idx++;
		idx_src++;
	}
	s1[idx] = '\0';
	return (s1);
}
