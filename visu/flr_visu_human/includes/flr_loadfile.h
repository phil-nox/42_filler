/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flr_loadfile.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laleta <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:36:19 by laleta            #+#    #+#             */
/*   Updated: 2019/09/01 05:30:53 by laleta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLR_LOADFILE_H
# define FLR_LOADFILE_H

static char *g_flr_loadfile[] =
{
	"resources/img/pacman1.jpg",
	"resources/img/mario1.jpg",
	"resources/audio/game_over.ogg",
	"resources/audio/m2.ogg",
	"resources/audio/terminator.ogg",
	"resources/audio/fin.wav",
	"resources/font/subway-ticker.regular.ttf",
	"resources/font/blox-brk.regular.ttf",
	"resources/font/footer.ttf",
	""
};

# define P1_IMG			g_flr_loadfile[0]
# define P2_IMG			g_flr_loadfile[1]
# define F_SOUND		g_flr_loadfile[2]
# define P_SOUND		g_flr_loadfile[3]
# define F_MUSIC		g_flr_loadfile[4]
# define F_FIN_MUS		g_flr_loadfile[5]
# define P_FONT			g_flr_loadfile[6]
# define T_FONT			g_flr_loadfile[7]
# define F_FONT			g_flr_loadfile[8]

#endif
