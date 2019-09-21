/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_precision_1_print_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 13:45:06 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:49:06 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	debug_print(t_str_f *add, int power, int curr)
{
	ft_putstr_p("power_tab[idx]: ");
	ft_putnbr(power);
	ft_putstr_p("\t curr: ");
	ft_putnbr(curr);
	ft_putstr_p("\t val: ");
	print_t_str_f_human(add);
	ft_putstr_p("\n");
}

void	debug_print_final(t_str_f *final)
{
	ft_putstr_p("\t\t\t\t       final: ");
	print_t_str_f_human(final);
	ft_putstr_p("\n");
}

void	t_str_f_print_ent(t_str_f *input)
{
	int		idx;

	idx = input->idx_ent;
	if (idx == 0)
		ft_putchar_p('0');
	while (--idx > -1)
		ft_putchar_p(input->ent[idx] + 48);
}

void	t_str_f_print_frc(t_str_f *input, int pos)
{
	int		idx;

	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - idx - 1 >= input->idf)
			ft_putchar_p('0');
		else if (input->exp_frc - idx - 1 >= 0)
			ft_putchar_p(input->frc[input->exp_frc - idx - 1] + 48);
		else
			ft_putchar_p('0');
	}
}

void	t_str_f_print_full_simple(t_str_f *input, int pos)
{
	int		idx;

	idx = input->idx_ent;
	while (--idx > -1)
		ft_putchar_p(input->ent[idx] + 48);
	ft_putchar_p('.');
	idx = -1;
	while (++idx < pos)
	{
		if (input->exp_frc - idx - 1 >= input->idf)
			ft_putchar_p('0');
		else if (input->exp_frc - idx - 1 >= 0)
			ft_putchar_p(input->frc[input->exp_frc - idx - 1] + 48);
		else
			ft_putchar_p('0');
	}
}
