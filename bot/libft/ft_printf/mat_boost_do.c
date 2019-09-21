/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_boost_do.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/27 02:06:10 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	boost_do(t_str_f *input, char *(*boost_fun[7])(void), char type)
{
	int		idx;
	int		idb;
	char	*boost;

	if (type == '+')
		input->idx_ent = 0;
	else
		input->idf = 0;
	idb = -1;
	while (boost_fun[++idb])
	{
		boost = boost_fun[idb]();
		idx = -1;
		while (boost[++idx])
		{
			if (type == '+')
				input->ent[input->idx_ent++] = boost[idx] - 48;
			else
				input->frc[input->idf++] = boost[idx] - 48;
		}
	}
}

void		boost_neg_do(t_str_f *input, char *(*boost_fun[7])(void))
{
	boost_do(input, boost_fun, '-');
}

void		boost_pos_do(t_str_f *input, char *(*boost_fun[7])(void))
{
	boost_do(input, boost_fun, '+');
}
