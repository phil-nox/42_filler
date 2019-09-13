# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/13 19:29:08 by wgorold          ###   ########.fr        #
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

PATH_H =./

CC=gcc

FLAGS= -Wall -Wextra -Werror

CFLAGS= -c $(FLAGS)

FLAG_PATH_OBJ= -o $@ -I./libft -I$(PATH_H)

PATH_B=./build/

PATH_S=./obj/

SRC= 	n00_debug_wfile.o n01_debug_utf8.o \
		n03_debug_color.o n04_debug_param.o \
		n05_debug_metric.o n10_malloc_player.o \
		n11_read_map.o \
		n20_map_copy.o n21_place_for_pie.o \
		n22_score.o n23_find_maps.o n24_find.o n30_send_pie.o \
		n40_map_set_basic.o \
		n41_map_set.o  n42_map_reset.o  n43_map_diff.o \
		n44_map_force_set.o n46_map_zone.o n45_map_field.o \
		n50_game_pack.o n51_game_find_send.o\
		n74_human_send_basic.o n75_human_send.o \
		n_mstack_0.o n_mstack_1.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

$(NAME): mlibft $(PATH_SRC)
	$(CC) $(FLAGS) -o $(PATH_B)$(NAME)							n60_run.c 				$(PATH_S)*.o -L./libft/build -lft -I$(PATH_H) -I./libft
	$(CC) $(FLAGS) -o $(PATH_B)$(ST_NAME)_debug$(END_NAME)		n61_run_debug.c			$(PATH_S)*.o -L./libft/build -lft -I$(PATH_H) -I./libft
	$(CC) $(FLAGS) -o $(PATH_B)70_human_model$(END_NAME)		n70_human_model.c		$(PATH_S)*.o -L./libft/build -lft -I$(PATH_H) -I./libft
	$(CC) $(FLAGS) -o $(PATH_B)71_human_view$(END_NAME)			n71_human_view.c		$(PATH_S)*.o -L./libft/build -lft -I$(PATH_H) -I./libft
	$(CC) $(FLAGS) -o $(PATH_B)72_human_controller$(END_NAME)	n72_human_controller.c	$(PATH_S)*.o -L./libft/build -lft -I$(PATH_H) -I./libft
	$(CC) $(FLAGS) -o $(PATH_B)74_human_adapter$(END_NAME)		n73_human_adapter.c		$(PATH_S)*.o -L./libft/build -lft -I$(PATH_H) -I./libft

all: $(NAME)

play: all
	rm -rf test_debug
	touch test_debug
	./resources/filler_vm -p2 ./resources/players/carli.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map00 -s 3207
	@echo "./resources/filler_vm -p2 ./resources/players/carli.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map00 -s 3207"

play_h: re
	./resources/filler_vm -p2 ./resources/players//abanlin.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map02

human: re
	gcc -Wall -Wextra -Werror n70_human_model.c obj/*.o -L./libft/build -lft -I./ -I./libft -o 70_human_model.filler
	gcc -Wall -Wextra -Werror n71_human_view.c -o 71_human_view.filler obj/*.o -L./libft/build -lft -I./ -I./libft
	gcc -Wall -Wextra -Werror n72_human_controller.c -o 72_human_controller.filler
	gcc -Wall -Wextra -Werror n73_human_adapter.c -o 74_human_adapter.filler obj/*.o -L./libft/build -lft -I./ -I./libft
	@echo " "
	@echo "RUN >>>>"
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp"
	@echo "./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./70_human_model.filler  -f ./resources/maps/map00 -t 99 | ./74_human_adapter.filler"
	@echo "./71_human_view.filler"
	@echo "./72_human_controller.filler"
	@echo "<<<<"
	cp 70_human_model.filler ../visu/
	cp 74_human_adapter.filler ../visu/
	@echo "RUN >>>>"
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp"
	@echo "./filler_vm -p2 ./players/carli.filler -p1 ./70_human_model.filler  -f ./maps/map01 -t 99 | ./74_human_adapter.filler | ./filler_visu_human"
	@echo "<<<<"

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
$(PATH_S)n_mstack_0.o: n_mstack_0.c
	$(CC) $(CFLAGS) n_mstack_0.c $(FLAG_PATH_OBJ)
$(PATH_S)n_mstack_1.o: n_mstack_1.c
	$(CC) $(CFLAGS) n_mstack_1.c $(FLAG_PATH_OBJ)

mlibft:
	make all -C ./libft

clean:
	find $(PATH_S) -type f -not -name '.gitkeep' -delete
	make clean -C ./libft

fclean: clean
	find $(PATH_B) -type f -not -name '.gitkeep' -delete
	make fclean -C ./libft

re: fclean all