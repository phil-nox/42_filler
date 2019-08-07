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
# define MAX_INT 2147483647

# define SHOW_FIND_DEBUG 0 // 0(don't show), 1(show all), 2(show only good)
# define SHOW_VALUE_MAP 1 // 0, 1

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
void find_debug(t_map *map, int pos, int res, int tmp_score);
void debug_value_map(t_map *map);

int set_player(char *line, int *player);
int set_map(t_map *trg, char *keyword);
int init_map(char *line, t_map *trg, char *keyword);

int row_p(t_map *map, int pos);
int col_p(t_map *map, int pos);
int col_pg(t_map *map, int pos);
int not_in_borders(t_map *map, int pos, int t_r, int t_c);
int is_a_place(int player, t_map *map, t_map *pie, int pos);
int find_place(int player, t_map *map, t_map *pie);

void send_position(t_map *map, int pos);

char get_val(t_map *map, int pos);
void set_val(t_map *map, int pos, char val);
void pre_set_val(t_map *map);
int is_around(t_map *map, int pos, char to_find);
void set_val_map(t_map *map, int trg_ply);

#endif