/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_human_player.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 23:08:48 by laleta            #+#    #+#             */
/*   Updated: 2019/08/26 04:11:03 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLR_HUMAN_PLAYER_H
# define FLR_HUMAN_PLAYER_H

# define FIFO_MAP		"fifo_1"
# define FIFO_CMD		"fifo_2"
# define M_OFFSET		0
# define HUMAN			1
# define BOT			0

# define CMD_UP			"u"
# define CMD_DOWN		"d"
# define CMD_LEFT		"l"
# define CMD_RIGHT		"r"
# define CMD_SET		"s"
# define CMD_LEN		1

extern	int32_t			g_fdmap;
extern	int32_t			g_fdcmd;

#endif
