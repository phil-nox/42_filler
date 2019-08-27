/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 23:35:23 by laleta            #+#    #+#             */
/*   Updated: 2019/06/24 02:17:43 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_time.h"

static void		ft_sectotim(t_tim *t, uint32_t sec)
{
	int32_t			day;
	int32_t			mon;
	int32_t			year;
	int32_t			i;
	const int32_t	*pm;

	day = (70 * (uint32_t)365) + 17;
	day += sec / 86400;
	sec = sec % 86400;
	t->hour = sec / 3600;
	sec %= 3600;
	t->min = sec / 60;
	t->sec = sec % 60;
	year = day / 365;
	while (day < (i = DAYS(year, 0) + 365 * year))
		--year;
	day -= i;
	t->year = year + 1900;
	pm = MON_TAB(year);
	mon = 12;
	while (day < pm[--mon])
		;
	t->mon = mon + 1;
	t->day = day - pm[mon] + 1;
}

void			ft_ttoa(char **buf)
{
	int64_t		time_sec;
	t_tim		tim;

	time_sec = TIM(NULL) + 10800;
	ft_sectotim(&tim, time_sec);
	(*buf)[0] = tim.hour / 10 + '0';
	(*buf)[1] = tim.hour % 10 + '0';
	(*buf)[2] = ':';
	(*buf)[3] = tim.min / 10 + '0';
	(*buf)[4] = tim.min % 10 + '0';
	(*buf)[5] = ':';
	(*buf)[6] = tim.sec / 10 + '0';
	(*buf)[7] = tim.sec % 10 + '0';
	(*buf)[8] = ' ';
	(*buf)[9] = tim.day / 10 + '0';
	(*buf)[10] = tim.day % 10 + '0';
	(*buf)[11] = '.';
	(*buf)[12] = tim.mon / 10 + '0';
	(*buf)[13] = tim.mon % 10 + '0';
	(*buf)[14] = '.';
	(*buf)[15] = tim.year / 1000 + '0';
	(*buf)[16] = tim.year / 100 % 10 + '0';
	(*buf)[17] = tim.year / 10 % 10 + '0';
	(*buf)[18] = tim.year % 10 + '0';
	(*buf)[19] = '\0';
}
