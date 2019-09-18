/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n01_debug_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:36:04 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 15:36:46 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	ft_putstrfile(char const *s)
{
	int idx;
	int fdd;

	fdd = get_fdd();
	idx = 0;
	while (s[idx])
		++idx;
	return (write(fdd, s, idx));
}
