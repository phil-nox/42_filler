/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:38:03 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 22:38:04 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (*(unsigned char *)(s1 + idx) && idx < n)
	{
		if (*(unsigned char *)(s1 + idx) != *(unsigned char *)(s2 + idx))
		{
			return (*(unsigned char *)(s1 + idx)
							- *(unsigned char *)(s2 + idx));
		}
		idx++;
	}
	if (*(unsigned char *)(s2 + idx) && idx < n)
	{
		return (*(unsigned char *)(s1 + idx)
						- *(unsigned char *)(s2 + idx));
	}
	return (0);
}
