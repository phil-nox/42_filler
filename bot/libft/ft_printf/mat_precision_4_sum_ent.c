/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_4_sum_ent.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:45:12 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/24 18:14:30 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sum_t_str_f_ent_job(t_str_f *result, t_str_f *start, t_str_f *add)
{
	int idx;
	int add_val;
	int val;

	idx = 0;
	add_val = 0;
	while (start->ent[idx] != -1 || add->ent[idx] != -1)
	{
		if (add->ent[idx] == -1)
			val = start->ent[idx] + add_val;
		else if (start->ent[idx] == -1)
			val = add->ent[idx] + add_val;
		else
			val = start->ent[idx] + add->ent[idx] + add_val;
		result->ent[result->idx_ent++] = (val % 10);
		add_val = val / 10;
		++idx;
	}
	if (add_val)
	{
		result->ent[result->idx_ent++] = add_val;
		result->exp_ent++;
	}
}

void		sum_t_str_f_ent(t_str_f *result, t_str_f *a, t_str_f *b)
{
	t_str_f *start;
	t_str_f *add;

	init_t_str_f_ent(result);
	start = a;
	add = b;
	result->exp_ent = a->exp_ent;
	if (a->exp_ent < b->exp_ent)
	{
		start = b;
		add = a;
		result->exp_ent = b->exp_ent;
	}
	sum_t_str_f_ent_job(result, start, add);
}
