/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_boost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/26 23:54:49 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_pos(int num[5], void (*boost_pos_fun[5])(t_str_f *input))
{
	num[0] = 15360;
	num[1] = 14336;
	num[2] = 12288;
	num[3] = 8192;
	num[4] = 4096;
	boost_pos_fun[0] = &boost15360;
	boost_pos_fun[1] = &boost14336;
	boost_pos_fun[2] = &boost12288;
	boost_pos_fun[3] = &boost8192;
	boost_pos_fun[4] = &boost4096;
}

void		boost_pos(t_str_f *input, int pwr, int *curr)
{
	int		idx_boost;
	int		num[5];
	void	(*boost_pos_fun[5])(t_str_f *input);

	init_t_str_f(input);
	init_pos(num, boost_pos_fun);
	idx_boost = -1;
	while (BOOST_ON && ++idx_boost < 5)
	{
		if (pwr >= num[idx_boost] && *curr < num[idx_boost])
		{
			boost_pos_fun[idx_boost](input);
			*curr = num[idx_boost];
			return ;
		}
	}
	if (pwr == 0 || (pwr > 0 && *curr == 0))
	{
		input->ent[0] = 1;
		input->idx_ent = 1;
		input->exp_ent = 0;
		return ;
	}
}

static void	init_neg(int num[5], void (*boost_fun[5])(t_str_f *input))
{
	num[0] = -15360;
	num[1] = -14336;
	num[2] = -12288;
	num[3] = -8192;
	num[4] = -4096;
	boost_fun[0] = &boost_neg_15360;
	boost_fun[1] = &boost_neg_14336;
	boost_fun[2] = &boost_neg_12288;
	boost_fun[3] = &boost_neg_8192;
	boost_fun[4] = &boost_neg_4096;
}

void		boost_neg(t_str_f *input, int pwr, int *curr)
{
	int		idx_boost;
	int		num[5];
	void	(*boost_fun[5])(t_str_f *input);

	init_t_str_f(input);
	init_neg(num, boost_fun);
	idx_boost = -1;
	while (BOOST_ON && ++idx_boost < 5)
	{
		if (pwr <= num[idx_boost] && *curr > num[idx_boost])
		{
			boost_fun[idx_boost](input);
			input->exp_frc = -num[idx_boost];
			*curr = num[idx_boost];
			return ;
		}
	}
	if (pwr == -1 || (pwr < 0 && *curr == 0))
	{
		input->frc[0] = 5;
		input->idf = 1;
		input->exp_frc = 1;
		return ;
	}
}
