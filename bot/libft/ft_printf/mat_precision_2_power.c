/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_2_power.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	power_pos(t_str_f *input)
{
	int idx;
	int val;
	int add_val;

	if (DEBUG_POWER)
		print_t_str_f_human(input);
	idx = -1;
	add_val = 0;
	while (++idx < input->idx_ent)
	{
		val = (input->ent[idx]) * 2 + add_val;
		input->ent[idx] = (val % 10);
		add_val = val / 10;
	}
	if (add_val)
	{
		input->ent[input->idx_ent++] = add_val;
		input->exp_ent++;
	}
	if (DEBUG_POWER)
	{
		ft_putstr_p(" -> ");
		print_t_str_f_human(input);
		ft_putstr_p("\n");
	}
}

void	power_neg(t_str_f *input)
{
	int idx;
	int val;
	int add_val;

	if (DEBUG_POWER)
		print_t_str_f_human(input);
	idx = -1;
	add_val = 0;
	input->exp_frc++;
	while (++idx < input->idf)
	{
		val = (input->frc[idx]) * 5 + add_val;
		input->frc[idx] = (val % 10);
		add_val = val / 10;
	}
	if (add_val)
		input->frc[input->idf++] = add_val;
	if (DEBUG_POWER)
	{
		ft_putstr_p(" -> ");
		print_t_str_f_human(input);
		ft_putstr_p("\n");
	}
}

void	power2form(t_str_f *input, int pwr, int curr)
{
	int idx;

	if (pwr == 0 || (pwr > 0 && curr == 0))
		boost_pos(input, pwr, &curr);
	if (pwr == -1 || (pwr < 0 && curr == 0))
		boost_neg(input, pwr, &curr);
	idx = -1;
	if (pwr > 0)
	{
		while (++idx + curr < pwr)
			power_pos(input);
	}
	else
	{
		if (curr == 0)
			idx = 0;
		while (++idx + pwr < curr)
			power_neg(input);
	}
}

void	set_sign(t_str_f *result, unsigned int sign)
{
	if (sign)
		result->sign = '-';
	else
		result->sign = '+';
}
