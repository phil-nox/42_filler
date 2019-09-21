/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:16:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/07 06:31:13 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	size_t			idx;

	idx = 0;
	uc = (unsigned char)c;
	while (idx < len)
	{
		*(unsigned char *)(b + idx++) = uc;
	}
	return (b);
}
