/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n45_map_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:58:54 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 19:10:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	get(map, row, col + 1) > to_set)) //"."
*/

void	diff_for_field(t_map *fld, t_map *att)
{
	int row;
	int col;
	int tmp_fld;
	int tmp_att;

	row = -1;
	while (++row < fld->row)
	{
		col = -1;
		while (++col < fld->col)
		{
			tmp_fld = get(fld, row, col);
			if (tmp_fld < 1)
				continue;
			tmp_att = get(att, row, col);
			if (tmp_att != tmp_fld)
				set_val(fld, row, col, tmp_att - tmp_fld);
			else
				set_val(fld, row, col, -8);
		}
	}
}

void	field_and_shadow(t_map *fld, t_map *adv)
{
	int row;
	int col;
	int tmp_fld;
	int tmp_adv;

	row = -1;
	while (++row < fld->row)
	{
		col = -1;
		while (++col < fld->col)
		{
			tmp_fld = get(fld, row, col);
			tmp_adv = get(adv, row, col);
			if (tmp_adv < 1 && tmp_fld < 1)
				continue;
			if (tmp_adv > 0)
			{
				set_val(fld, row, col, tmp_adv);
				continue;
			}
			if (tmp_fld > 0)
				set_val(fld, row, col, -4);
		}
	}
}
