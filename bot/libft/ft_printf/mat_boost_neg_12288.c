/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_boost_neg_12288.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 16:43:44 by wgorold           #+#    #+#             */
/*   Updated: 2019/06/27 01:53:15 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	boost_neg_12288(t_str_f *input)
{
	char	*(*boost_fun[7])(void);

	boost_fun[0] = &boost_neg_12288_part1;
	boost_fun[1] = &boost_neg_12288_part2;
	boost_fun[2] = &boost_neg_12288_part3;
	boost_fun[3] = &boost_neg_12288_part4;
	boost_fun[4] = &boost_neg_12288_part5;
	boost_fun[5] = NULL;
	boost_fun[6] = NULL;
	boost_neg_do(input, boost_fun);
}
