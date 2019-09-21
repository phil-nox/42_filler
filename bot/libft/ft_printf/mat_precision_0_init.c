/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_0_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/07/17 16:43:39 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_t_str_f(t_str_f *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_ENT)
		input->ent[idx] = -1;
	idx = -1;
	while (++idx < LEN_STR_FRC)
		input->frc[idx] = -1;
	input->idx_ent = 0;
	input->idf = 0;
	input->exp_ent = 0;
	input->exp_frc = 0;
	input->sign = '+';
}

void	init_t_str_f_sign(t_str_f *input, unsigned int sign)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_ENT)
		input->ent[idx] = -1;
	idx = -1;
	while (++idx < LEN_STR_FRC)
		input->frc[idx] = -1;
	input->idx_ent = 0;
	input->idf = 0;
	input->exp_ent = 0;
	input->exp_frc = 0;
	input->sign = sign ? '-' : '+';
}

void	init_t_str_f_frc(t_str_f *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_FRC)
		input->frc[idx] = -1;
	input->idf = 0;
	input->exp_frc = 0;
}

void	init_t_str_f_ent(t_str_f *input)
{
	int idx;

	idx = -1;
	while (++idx < LEN_STR_ENT)
		input->ent[idx] = -1;
	input->idx_ent = 0;
	input->exp_ent = 0;
}
