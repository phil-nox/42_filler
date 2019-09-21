/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_7_get_run.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/07/17 18:18:37 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	mat_for_precision(t_str_f *output, short power_tab[FRAC_FLOAT],
	unsigned int sign)
{
	init_t_str_f(output);
	get_fractionnaire(output, power_tab);
	get_entiere(output, power_tab);
	set_sign(output, sign);
}

void	get_precision_longd(t_str_f *output, long double input)
{
	t_longd tmp;
	short	power_tab[FRAC_FLOAT];

	tmp.ld = input;
	if ((short)tmp.t_parts_ld.exp == 32767)
	{
		init_t_str_f_sign(output, tmp.t_parts_ld.sign);
		if (tmp.t_parts_ld.frac == 0)
			output->ent[output->idx_ent++] = 105;
		else
			output->ent[output->idx_ent++] = 110;
		return ;
	}
	if ((short)tmp.t_parts_ld.exp == 0 && tmp.t_parts_ld.frac == 0)
	{
		init_t_str_f_sign(output, tmp.t_parts_ld.sign);
		output->ent[output->idx_ent++] = 0;
		return ;
	}
	power_tab[0] = tmp.t_parts_ld.exp ? (short)tmp.t_parts_ld.exp - 16383
		: STOP_SHORT;
	set_power_tab(power_tab, tmp.t_parts_ld.frac,
		(short)tmp.t_parts_ld.exp - 16383, 0x4000000000000000);
	mat_for_precision(output, power_tab, tmp.t_parts_ld.sign);
}

void	get_precision_d(t_str_f *output, double input)
{
	t_d		tmp;
	short	power_tab[FRAC_FLOAT];

	tmp.d = input;
	if ((short)tmp.t_parts_d.exp == 2047)
	{
		init_t_str_f_sign(output, tmp.t_parts_d.sign);
		if (tmp.t_parts_d.frac == 0)
			output->ent[output->idx_ent++] = 105;
		else
			output->ent[output->idx_ent++] = 110;
		return ;
	}
	if ((short)tmp.t_parts_d.exp == 0 && tmp.t_parts_d.frac == 0)
	{
		init_t_str_f_sign(output, tmp.t_parts_d.sign);
		output->ent[output->idx_ent++] = 0;
		return ;
	}
	power_tab[0] = tmp.t_parts_d.exp ? (short)tmp.t_parts_d.exp - 1023
		: STOP_SHORT;
	set_power_tab(power_tab, tmp.t_parts_d.frac,
		(short)tmp.t_parts_d.exp - 1023, 0x0008000000000000);
	mat_for_precision(output, power_tab, tmp.t_parts_d.sign);
}

void	get_precision_f(t_str_f *output, float input)
{
	t_f		tmp;
	short	power_tab[FRAC_FLOAT];

	tmp.f = input;
	if ((short)tmp.t_parts_f.exp == 255)
	{
		init_t_str_f_sign(output, tmp.t_parts_f.sign);
		if (tmp.t_parts_f.frac == 0)
			output->ent[output->idx_ent++] = 105;
		else
			output->ent[output->idx_ent++] = 110;
		return ;
	}
	if ((short)tmp.t_parts_f.exp == 0 && tmp.t_parts_f.frac == 0)
	{
		init_t_str_f_sign(output, tmp.t_parts_f.sign);
		output->ent[output->idx_ent++] = 0;
		return ;
	}
	power_tab[0] = tmp.t_parts_f.exp ? (short)tmp.t_parts_f.exp - 127
		: STOP_SHORT;
	set_power_tab(power_tab, tmp.t_parts_f.frac,
		(short)tmp.t_parts_f.exp - 127, 0x0000000000400000);
	mat_for_precision(output, power_tab, tmp.t_parts_f.sign);
}
