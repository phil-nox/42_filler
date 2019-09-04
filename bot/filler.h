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

#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "__mstack.h"
#include "human.h"

typedef	struct		s_pnt
{
	int 			row;
	int				col;
}					t_pnt;

typedef	struct		s_map
{
	int			    row;
	int 			col;
	int**        	map;
}					t_map;

typedef	struct		s_score
{
	int			    place_score;
	int		       	unreachable;
	int 			diff_average;
	int 			diff_num;
	int				diff_sum;
	int				un_score;
	int				df_score;
	int				fn_score;
}					t_score;

typedef	struct		s_game
{
	char			show_read_debug;
	char			show_set_wave_debug;
	char			show_set_debug;
	char			show_place;
	char			show_send;
	char			show_reset_wave_debug;
	char			show_diff_debug;
	char			show_score_debug;
	char			decision_debug;
	char			show_att_debug;
	t_map			*org;
	t_map			*map;
	t_map			*adv;
	t_map			*pie;
	t_map			*att;
	t_map			*fld;
	t_map			*zon;
	t_map			*fre;
	t_map			*fields[9];
	t_score			best_score;
	int				pnt[2];
	int 			player;
	int				enemy_score;
}					t_game;

typedef	struct		s_game_pack
{
	t_game			game;
	t_map			org;
	t_map			map;
	t_map			adv;
	t_map			pie;
	t_map			att;
	t_map			fld;
	t_map			zon;
	t_map			fre;
	char			*gnl;
	char			cmd_l[BUF_SIZE];
	int				decision;
}					t_game_pack;

int get_fdd();
int ft_putstrfile(char const *s);
void debug_print(char *str, int next_line, int to_free);
void debug_num(int num, int next_line);
//void debug_value_map(t_map *map);
void debug_value_map_color(t_map *map, char *tab);
//void debug_value_map_color_adv(t_map *map, char *str);
void debug_set(t_map *map);
void debug_place(t_map *map);
void debug_reset(t_map *map);
void debug_diff(t_map *map);
void debug_att(t_map *map);
void debug_metric (t_game *game, char *begin);
int map_print(int input);

int set_player_adv(char *line, t_game *game);
int set_map(t_game *game, char *keyword, int fd_in);
int init_map(char *line, t_game *game, char *keyword, int fd_in);

void send_position(int row, int col, int where);

void as_map(t_map *src, t_map *trg);
int make_map(t_game *game, t_map *src, t_map *trg);

int in_borders(t_game *game, int row, int col);
int set_val(t_map *map, int row, int col, int val);
int set_val_map(t_game *game, t_map *map, int to_find);

int find_place(t_game *game);

int get_val(t_map *map, int row, int col);
int get_val_pnt(t_map *map, int pnt[2]);
//void reset_pie(t_game *game, int row, int col);
void reset_val_map(t_game *game, int row, int col);
//int reset_around(t_game *game, int row, int col, int to_set);
int glob_min_val_around(t_game *game, t_map *map);
void diff_val_map(t_game *game, int min_border_val, t_score *score, char show);

void send_map_to_view(t_game *game, t_map *show, int fd_map, int with_pie);
int is_a_place(t_game *game, t_map *map, int row, int col);
int place_pie(t_game *game, t_map *map, int row, int col);

int send_to_fd(char *line, int fd_map);
int send_to_fd_ln(char *line, int fd_map);
int map_incoming (t_game *game, char *line, int fd);
int cmd_apply(t_game *game, int fd_map, char input);
void game_pack_init(t_game_pack *game_p);
void shadow_calc(t_game *game);


int map_incoming_bot(char *gnl, t_game *game);
void game_pack_init_bot(t_game_pack *game_p);
int find_first_place(t_game *game, t_map *map);

void calc_decision(t_game *game, t_score *score, char show);
int change_decision(t_score *curr_sc, t_score *aspi_sc);

int set_val_map_force(t_game *game, t_map *map, int to_find);
void diff_for_field(t_map *fld, t_map *att);
void field_and_shadow(t_map *fld, t_map *adv);
void zones(t_map *fre, t_map *att, t_map *map);
void zone_diff(t_map *fre, t_map *zon);


#endif