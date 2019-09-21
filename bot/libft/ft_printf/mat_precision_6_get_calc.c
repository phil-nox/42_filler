/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_6_get_calc.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 16:47:23 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_fractionnaire(t_str_f *frc, short power_tab[FRAC_FLOAT])
{
	int		idx;
	int		curr;
	t_str_f	tmp;
	t_str_f	add;

	idx = -1;
	curr = 0;
	while (++idx < FRAC_FLOAT)
	{
		if (power_tab[idx] == STOP_SHORT || power_tab[idx] >= 0)
			continue;
		if (curr == 0)
		{
			power2form(&add, power_tab[idx], curr);
			*frc = add;
			curr = power_tab[idx];
			continue;
		}
		power2form(&add, power_tab[idx], curr);
		tmp = *frc;
		sum_t_str_f_frc(frc, &tmp, &add);
		if (DEBUG_FLOAT_CREATION)
			debug_print(&add, power_tab[idx], curr);
		curr = power_tab[idx];
	}
}

void	get_entiere(t_str_f *ent, short power_tab[FRAC_FLOAT])
{
	int		idx;
	int		curr;
	t_str_f	tmp;
	t_str_f	add;

	idx = FRAC_FLOAT;
	curr = 0;
	while (--idx > -1)
	{
		if (power_tab[idx] == STOP_SHORT || power_tab[idx] < 0)
			continue;
		power2form(&add, power_tab[idx], curr);
		tmp = *ent;
		sum_t_str_f_ent(ent, &tmp, &add);
		if (DEBUG_FLOAT_CREATION)
			debug_print(&add, power_tab[idx], curr);
		curr = power_tab[idx];
	}
}
