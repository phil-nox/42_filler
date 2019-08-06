/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:17:04 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/04 22:17:05 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while (*(unsigned char *)(s1 + idx))
	{
		if (*(unsigned char *)(s1 + idx) != *(unsigned char *)(s2 + idx))
		{
			return (*(unsigned char *)(s1 + idx)
							- *(unsigned char *)(s2 + idx));
		}
		idx++;
	}
	if (*(unsigned char *)(s2 + idx))
	{
		return (*(unsigned char *)(s1 + idx)
						- *(unsigned char *)(s2 + idx));
	}
	return (0);
}
