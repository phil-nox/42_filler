/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n60_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:14:57 by wgorold           #+#    #+#             */
/*   Updated: 2019/09/12 20:16:02 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_game_pack game_p;

	game_pack_init_bot(&game_p);
	while (get_next_line(0, &game_p.gnl) == 1 && add_mstack(game_p.gnl) == 0)
		if (map_incoming_bot(game_p.gnl, &game_p.game))
			return (1);
	debug_print(NULL, 0, -1);
}
