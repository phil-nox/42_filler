# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/21 19:49:58 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "\$(PATH_S)$x.o: $x.c\n\t\$(CC) \$(CFLAGS) $x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" | tr '\n' ' '
#

ST_NAME=squid
END_NAME=.filler
NAME=$(ST_NAME)$(END_NAME)

LIB=libft/build/libft.a

CC=gcc

FLAGS= -Wall -Wextra -Werror

CFLAGS= -c $(FLAGS)

FLAG_PATH_OBJ= -o $@ -I./libft

PATH_B=build/

PATH_S=obj/

SRC= 	n00_debug_wfile.o n01_debug_utf8.o \
		n03_debug_color.o n04_debug_param.o \
		n05_debug_metric.o n10_malloc_player.o \
		n11_read_map.o \
		n20_map_copy.o n21_place_for_pie.o \
		n22_score.o n23_find_maps.o n24_find.o \
		n25_find_score.o n26_find_decision.o \
		n30_send_pie.o \
		n40_map_set_basic.o \
		n41_map_set.o  n42_map_reset.o  n43_map_diff.o \
		n44_map_force_set.o n46_map_zone.o n45_map_field.o \
		n50_game_pack.o n51_game_find_send.o\
		n74_human_send_basic.o n75_human_send.o \
		n76_human_for_adapter.o n77_human_over_roll.o \
		n_mstack_0.o n_mstack_1.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

MAINS=	n60_run.o n61_run_debug.o n70_human_model.o n71_human_view.o n72_human_controller.o n73_human_adapter.o

MAINS_SRC= $(patsubst %.o, $(PATH_S)%.o, $(MAINS))

all: $(PATH_B)$(NAME) $(PATH_B)$(ST_NAME)_debug$(END_NAME) $(PATH_B)70_human_model$(END_NAME) \
$(PATH_B)71_human_view$(END_NAME) $(PATH_B)72_human_controller$(END_NAME) \
$(PATH_B)74_human_adapter$(END_NAME)

$(PATH_B)$(NAME): 							$(LIB) $(PATH_SRC) $(MAINS_SRC)
	$(CC) $(FLAGS) -o $@	$(PATH_S)n60_run.o 					$(PATH_SRC) -L./libft/build -lft -I./libft

$(PATH_B)$(ST_NAME)_debug$(END_NAME):  		$(LIB) $(PATH_SRC) $(MAINS_SRC)
	$(CC) $(FLAGS) -o $@	$(PATH_S)n61_run_debug.o			$(PATH_SRC) -L./libft/build -lft -I./libft

$(PATH_B)70_human_model$(END_NAME): 		$(LIB) $(PATH_SRC) $(MAINS_SRC)
	$(CC) $(FLAGS) -o $@	$(PATH_S)n70_human_model.o			$(PATH_SRC) -L./libft/build -lft -I./libft

$(PATH_B)71_human_view$(END_NAME): 			$(LIB) $(PATH_SRC) $(MAINS_SRC)
	$(CC) $(FLAGS) -o $@	$(PATH_S)n71_human_view.o			$(PATH_SRC) -L./libft/build -lft -I./libft

$(PATH_B)72_human_controller$(END_NAME): 	$(LIB) $(PATH_SRC) $(MAINS_SRC)
	$(CC) $(FLAGS) -o $@	$(PATH_S)n72_human_controller.o		$(PATH_SRC) -L./libft/build -lft -I./libft

$(PATH_B)74_human_adapter$(END_NAME): 		$(LIB) $(PATH_SRC) $(MAINS_SRC)
	$(CC) $(FLAGS) -o $@	$(PATH_S)n73_human_adapter.o		$(PATH_SRC) -L./libft/build -lft -I./libft

$(PATH_S)n60_run.o: n60_run.c
	$(CC) $(CFLAGS) n60_run.c $(FLAG_PATH_OBJ)
$(PATH_S)n61_run_debug.o: n61_run_debug.c
	$(CC) $(CFLAGS) n61_run_debug.c $(FLAG_PATH_OBJ)
$(PATH_S)n70_human_model.o: n70_human_model.c
	$(CC) $(CFLAGS) n70_human_model.c $(FLAG_PATH_OBJ)
$(PATH_S)n71_human_view.o: n71_human_view.c
	$(CC) $(CFLAGS) n71_human_view.c $(FLAG_PATH_OBJ)
$(PATH_S)n72_human_controller.o: n72_human_controller.c
	$(CC) $(CFLAGS) n72_human_controller.c $(FLAG_PATH_OBJ)
$(PATH_S)n73_human_adapter.o: n73_human_adapter.c
	$(CC) $(CFLAGS) n73_human_adapter.c $(FLAG_PATH_OBJ)

$(PATH_S)n00_debug_wfile.o: n00_debug_wfile.c
	$(CC) $(CFLAGS) n00_debug_wfile.c $(FLAG_PATH_OBJ)
$(PATH_S)n01_debug_utf8.o: n01_debug_utf8.c
	$(CC) $(CFLAGS) n01_debug_utf8.c $(FLAG_PATH_OBJ)
$(PATH_S)n03_debug_color.o: n03_debug_color.c
	$(CC) $(CFLAGS) n03_debug_color.c $(FLAG_PATH_OBJ)
$(PATH_S)n04_debug_param.o: n04_debug_param.c
	$(CC) $(CFLAGS) n04_debug_param.c $(FLAG_PATH_OBJ)
$(PATH_S)n05_debug_metric.o: n05_debug_metric.c
	$(CC) $(CFLAGS) n05_debug_metric.c $(FLAG_PATH_OBJ)
$(PATH_S)n10_malloc_player.o: n10_malloc_player.c
	$(CC) $(CFLAGS) n10_malloc_player.c $(FLAG_PATH_OBJ)
$(PATH_S)n11_read_map.o: n11_read_map.c
	$(CC) $(CFLAGS) n11_read_map.c $(FLAG_PATH_OBJ)
$(PATH_S)n20_map_copy.o: n20_map_copy.c
	$(CC) $(CFLAGS) n20_map_copy.c $(FLAG_PATH_OBJ)
$(PATH_S)n21_place_for_pie.o: n21_place_for_pie.c
	$(CC) $(CFLAGS) n21_place_for_pie.c $(FLAG_PATH_OBJ)
$(PATH_S)n22_score.o: n22_score.c
	$(CC) $(CFLAGS) n22_score.c $(FLAG_PATH_OBJ)
$(PATH_S)n23_find_maps.o: n23_find_maps.c
	$(CC) $(CFLAGS) n23_find_maps.c $(FLAG_PATH_OBJ)
$(PATH_S)n24_find.o: n24_find.c
	$(CC) $(CFLAGS) n24_find.c $(FLAG_PATH_OBJ)
$(PATH_S)n25_find_score.o: n25_find_score.c
	$(CC) $(CFLAGS) n25_find_score.c $(FLAG_PATH_OBJ)
$(PATH_S)n26_find_decision.o: n26_find_decision.c
	$(CC) $(CFLAGS) n26_find_decision.c $(FLAG_PATH_OBJ)
$(PATH_S)n30_send_pie.o: n30_send_pie.c
	$(CC) $(CFLAGS) n30_send_pie.c $(FLAG_PATH_OBJ)
$(PATH_S)n40_map_set_basic.o: n40_map_set_basic.c
	$(CC) $(CFLAGS) n40_map_set_basic.c $(FLAG_PATH_OBJ)
$(PATH_S)n41_map_set.o: n41_map_set.c
	$(CC) $(CFLAGS) n41_map_set.c $(FLAG_PATH_OBJ)
$(PATH_S)n42_map_reset.o: n42_map_reset.c
	$(CC) $(CFLAGS) n42_map_reset.c $(FLAG_PATH_OBJ)
$(PATH_S)n43_map_diff.o: n43_map_diff.c
	$(CC) $(CFLAGS) n43_map_diff.c $(FLAG_PATH_OBJ)
$(PATH_S)n44_map_force_set.o: n44_map_force_set.c
	$(CC) $(CFLAGS) n44_map_force_set.c $(FLAG_PATH_OBJ)
$(PATH_S)n45_map_field.o: n45_map_field.c
	$(CC) $(CFLAGS) n45_map_field.c $(FLAG_PATH_OBJ)
$(PATH_S)n46_map_zone.o: n46_map_zone.c
	$(CC) $(CFLAGS) n46_map_zone.c $(FLAG_PATH_OBJ)
$(PATH_S)n50_game_pack.o: n50_game_pack.c
	$(CC) $(CFLAGS) n50_game_pack.c $(FLAG_PATH_OBJ)
$(PATH_S)n51_game_find_send.o: n51_game_find_send.c
	$(CC) $(CFLAGS) n51_game_find_send.c $(FLAG_PATH_OBJ)
$(PATH_S)n74_human_send_basic.o: n74_human_send_basic.c
	$(CC) $(CFLAGS) n74_human_send_basic.c $(FLAG_PATH_OBJ)
$(PATH_S)n75_human_send.o: n75_human_send.c
	$(CC) $(CFLAGS) n75_human_send.c $(FLAG_PATH_OBJ)
$(PATH_S)n76_human_for_adapter.o: n76_human_for_adapter.c
	$(CC) $(CFLAGS) n76_human_for_adapter.c $(FLAG_PATH_OBJ)
$(PATH_S)n77_human_over_roll.o: n77_human_over_roll.c
	$(CC) $(CFLAGS) n77_human_over_roll.c $(FLAG_PATH_OBJ)
$(PATH_S)n_mstack_0.o: n_mstack_0.c
	$(CC) $(CFLAGS) n_mstack_0.c $(FLAG_PATH_OBJ)
$(PATH_S)n_mstack_1.o: n_mstack_1.c
	$(CC) $(CFLAGS) n_mstack_1.c $(FLAG_PATH_OBJ)

$(LIB):
	make all -C ./libft

clean:
	make clean -C ./libft
	find $(PATH_S) -type f -not -name '.gitkeep' -delete

fclean:
	make fclean -C ./libft
	find $(PATH_S) -type f -not -name '.gitkeep' -delete
	find ./build -depth 1 -not -name '.gitkeep' -exec rm -rf {} \;

re: fclean all