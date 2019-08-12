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
# define SHOW_SEND 1 // 0, 1
# define SHOW_VALUE_MAP_ADV 2 // 0, 1, 2(show diff)

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"

typedef	struct		s_map
{
	int			    row;
	int 			col;
	char**        	map;
	int 			player;
}					t_map;

typedef	struct		s_score
{
	int			    enemy_dist;
	int 			diff_map;
	int		       	isolated;
	int 			decision;
	int				pos;
}					t_score;

void debug_print(char *str, int next_line, int to_free);
void find_debug(t_map *map, int pos, int res, int tmp_score);
void debug_value_map(t_map *map);
void debug_value_map_color(t_map *map);
void debug_value_map_color_adv(t_map *map, char *str);
void send_debug(t_map *map, int pos, int tmp_score);
void score_debug(t_map *map, int pos, t_score *score);
void send_debug_adv(t_map *map, t_score *score);

int set_player(char *line, int *player);
void set_player_adv(char *line, int *player, t_map *org);
int set_map(t_map *trg, char *keyword);
int init_map(char *line, t_map *trg, char *keyword);

int row_p(t_map *map, int pos);
int col_p(t_map *map, int pos);
int col_pg(t_map *map, int pos);
int not_in_borders(t_map *map, int pos, int t_r, int t_c);
int is_a_place(int player, t_map *map, t_map *pie, int pos);
int find_place(int player, t_map *map, t_map *pie);
t_score find_place_adv(t_map *org, t_map *map, t_map *pie, t_map *adv);
int calc_score(t_map *map, t_map *pie, int pos);
t_score get_score(int pos, t_map *map, t_map *pie, t_map *adv);

void send_position(t_map *map, int pos);

char get_val(t_map *map, int pos);
int set_val(t_map *map, int pos, char val);
void pre_set_val(t_map *map);
int is_around(t_map *map, int pos, char to_find);
void set_val_map(t_map *map, int trg_ply);

void as_map(t_map *src, t_map *trg);
int cpy_map(t_map *src, t_map *trg);
int make_map(t_map *src, t_map *trg);

#endif