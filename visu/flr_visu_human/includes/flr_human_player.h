/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_human_player.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 23:08:48 by laleta            #+#    #+#             */
/*   Updated: 2019/09/18 19:22:39 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLR_HUMAN_PLAYER_H
# define FLR_HUMAN_PLAYER_H

# define FIFO_MAP		"mypipe.map"
# define FIFO_CMD		"mypipe.cmd"
# define FIFO_ADP		"mypipe.adp"

# define CMD_UP			"w"
# define CMD_DOWN		"s"
# define CMD_LEFT		"a"
# define CMD_RIGHT		"d"
# define CMD_SET		"e"
# define CMD_AUTO		"q"
# define CMD_WIN		"x"
# define CMD_LEN		1

extern	int32_t			g_fdmap;
extern	int32_t			g_fdcmd;
extern	int32_t			g_fdadp;

#endif
