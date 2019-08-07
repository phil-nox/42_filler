/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 18:44:51 by wgorold           #+#    #+#             */
/*   Updated: 2019/08/06 17:54:38 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define PLY_KW "$$$ exec p"
# define MAP_KW "Plateau "
# define PIE_KW "Piece "
# define SHIFT_M 4

# define SHOW_FIND_DEBUG 2 // 0(don't show), 1(show all), 2(show only good)

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef	struct		s_map
{
	int			    row;
	int 			col;
	char**        	map;
}					t_map;

void debug_print(char *str, int next_line, int to_free);
void find_debug(t_map *map, int pos, int res);

int set_player(char *line, int *player);
int set_map(t_map *trg, char *keyword);
int init_map(char *line, t_map *trg, char *keyword);

int row_p(t_map *map, int pos);
int col_p(t_map *map, int pos);
int not_in_borders(t_map *map, int pos, int t_r, int t_c);
int is_a_place(int player, t_map *map, t_map *pie, int pos);
void find_place(int player, t_map *map, t_map *pie);

#endif