/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n04_debug_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 15:51:15 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/21 20:14:17 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	debug_set(t_map *map)
{
	ft_putstrfile("\n");
	debug_value_map_color(map, "");
	ft_putstrfile("|||||||| END SET ||||||||\n");
}

void	debug_place(t_map *map)
{
	ft_putstrfile("\n");
	debug_value_map_color(map, "");
	ft_putstrfile("........ END PLACE ........\n");
}

void	debug_reset(t_map *map)
{
	ft_putstrfile("\n");
	debug_value_map_color(map, "");
	ft_putstrfile("|||||||| END SET after reSET ||||||||\n");
}

void	debug_diff(t_map *map)
{
	debug_value_map_color(map, "");
	debug_print_fd("@@@@@@@@ END DIFF @@@@@@@@", 1, 0);
}

void	debug_att(t_map *map)
{
	debug_value_map_color(map, "");
	debug_print_fd("^^^^^^^^ END ATT ^^^^^^^^", 1, 0);
}
