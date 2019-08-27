/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:04:14 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/09 23:31:28 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t idx;

	if (!s1 || !s2)
		return (0);
	idx = 0;
	while ((*s1 || *s2) && idx < n)
	{
		if (*(s1++) != *(s2++))
			return (0);
		idx++;
	}
	return (1);
}
