/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boost_write.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:15:17 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 17:04:43 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_boost(char const *s, int end)
{
	static char	to_write[BUFF];
	static int	idx;
	int			val;

	if (end)
	{
		val = write(1, to_write, idx);
		idx = 0;
		return (val);
	}
	to_write[idx++] = *s;
	if (idx >= BUFF)
	{
		val = write(1, to_write, idx);
		idx = 0;
		return (val);
	}
	return (-2);
}
