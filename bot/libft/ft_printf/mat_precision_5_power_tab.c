/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_5_power_tab.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_power_tab(short power_tab[FRAC_FLOAT])
{
	int idx;

	idx = 0;
	while (++idx < FRAC_FLOAT)
		power_tab[idx] = STOP_SHORT;
}

void	set_power_tab(short power_tab[FRAC_FLOAT], unsigned long vals,
	short exp, unsigned long mask)
{
	int idx;

	idx = 0;
	if (power_tab[idx] == STOP_SHORT)
		exp++;
	while (++idx < FRAC_FLOAT)
		power_tab[idx] =
			(vals & (mask >> (idx - 1))) ? (exp - idx) : STOP_SHORT;
	if (DEBUG_EXP_TAB)
	{
		print_arr(power_tab, FRAC_FLOAT);
		ft_putstr_p("\n");
	}
}
