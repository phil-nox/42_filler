/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n20_map_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:53:27 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 16:53:39 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	as_map(t_map *src, t_map *trg)
{
	int idx;
	int idxc;

	trg->row = src->row;
	trg->col = src->col;
	idx = -1;
	while (++idx < src->row)
	{
		idxc = -1;
		while (++idxc < src->col)
			trg->map[idx][idxc] = src->map[idx][idxc];
	}
}
