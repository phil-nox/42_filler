/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_3_sum_frc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/24 18:07:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	go2ent(t_str_f *rst)
{
	t_str_f tmp;
	t_str_f one;

	init_t_str_f_ent(&one);
	power2form(&one, 0, 0);
	tmp = *rst;
	sum_t_str_f_ent(rst, &tmp, &one);
}

static void	sum_frc(t_str_f *rst, t_str_f *str, t_str_f *add, int *add_val)
{
	int idx;
	int val;
	int shift;

	shift = str->exp_frc - add->exp_frc;
	idx = 0;
	while (idx < str->idf || idx - shift < add->idf)
	{
		if (idx - shift < 0)
			rst->frc[rst->idf++] = (str->frc[idx] != -1) ? str->frc[idx] : 0;
		else if (idx >= str->idf)
		{
			val = add->frc[idx - shift] + *add_val;
			rst->frc[rst->idf++] = (val % 10);
			*add_val = val / 10;
		}
		else
		{
			val = str->frc[idx] + *add_val;
			val += (add->frc[idx - shift] != -1) ? add->frc[idx - shift] : 0;
			rst->frc[rst->idf++] = (val % 10);
			*add_val = val / 10;
		}
		++idx;
	}
}

static void	sum_t_str_f_frc_job(t_str_f *rst, t_str_f *str, t_str_f *add)
{
	int add_val;

	add_val = 0;
	sum_frc(rst, str, add, &add_val);
	if (add_val && rst->idf != rst->exp_frc)
		rst->frc[rst->idf++] = add_val;
	else if (add_val)
		go2ent(rst);
}

void		sum_t_str_f_frc(t_str_f *rst, t_str_f *a, t_str_f *b)
{
	t_str_f *str;
	t_str_f *add;

	init_t_str_f_frc(rst);
	str = a;
	add = b;
	rst->exp_frc = a->exp_frc;
	if (a->exp_frc < b->exp_frc)
	{
		str = b;
		add = a;
		rst->exp_frc = b->exp_frc;
	}
	sum_t_str_f_frc_job(rst, str, add);
}
