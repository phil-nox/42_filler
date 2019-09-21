/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_task.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:42:31 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/16 15:44:12 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_end_task(t_task *input, char *s)
{
	if (*s == '\0' || !is_one_of(*s,
		"cCsSpdDioOuUxXgfF%-+ #.0123456789*hlLzj"))
	{
		input->type = *s;
		return (*s == '\0') ? (0) : (1);
	}
	if (is_one_of(*s, "cCsSpdDioOuUxXgfF%"))
	{
		input->type = *s;
		if (input->precision == -1)
		{
			if (input->type == 'f' || input->type == 'F')
				input->precision = 6;
		}
		return (1);
	}
	return (-1);
}

static void	set_precision(t_task *input, char *s, va_list *ap,
	int *add_total)
{
	int val;

	if (*(s + 1) == '*')
		val = va_arg(*ap, int);
	else if ((*(s + 1) == '+')
			|| (*(s + 1) > 47 && *(s + 1) < 58))
		val = ft_atoi_printf(s + 1, add_total);
	else
	{
		val = 0;
		(*add_total)--;
	}
	(*add_total)++;
	input->precision = (val < 0) ? -1 : val;
}

static void	set_width_star(t_task *input, va_list *ap)
{
	int val;

	val = va_arg(*ap, unsigned long);
	if (val < 0)
	{
		input->width = -val;
		input->minus = 1;
	}
	else
		input->width = val;
}

static void	set_length(t_task *input, char *s, int *add_total)
{
	int val;

	if (*s == 'l' && *(s + 1) == 'l')
		val = 'l' + (*add_total)++;
	else if (*s == 'h' && *(s + 1) == 'h')
		val = 'h' + (*add_total)++;
	else
		val = *s;
	input->length = (input->length < val) ? val : input->length;
}

int			set_task(t_task *input, char *s, va_list *ap)
{
	int add_total;
	int val;

	add_total = 1;
	if ((val = check_end_task(input, s)) != -1)
		return (val);
	if (*s == '-')
		input->minus = 1;
	else if (*s == '+')
		input->plus = 1;
	else if (*s == ' ')
		input->space = 1;
	else if (*s == '#')
		input->hash = 1;
	else if (*s == '0')
		input->zero = '0';
	else if (*s == '.')
		set_precision(input, s, ap, &add_total);
	else if (*s == '*')
		set_width_star(input, ap);
	else if (*s > 48 && *s < 58)
		input->width = ft_atoi_printf(s, &add_total);
	else if (*s == 'h' || *s == 'l' || *s == 'L' || *s == 'z' || *s == 'j')
		set_length(input, s, &add_total);
	return (set_task(input, s + add_total, ap) + add_total);
}
