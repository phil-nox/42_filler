# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/04/20 01:33:07 by wgorold          ###   ########.fr        #
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

SRC= 	00_debug_wfile.o 01_debug_utf8.o \
		03_debug_color.o 04_debug_param.o 10_read_map.o \
		20_map_copy.o 21_place_for_pie.o \
		22_score.o 23_find.o 30_send_pie.o \
		41_map_set.o  42_map_reset.o  50_game.o \
		43_map_force_set.o 44_map_zone.o \
		__mstack.o 73_human_send.o \
		
		
OTHER=  90_old.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

$(NAME): $(PATH_SRC)
	$(CC) $(FLAGS) 60_run.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)$(NAME)
	$(CC) $(FLAGS) 61_run_debug.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)$(ST_NAME)_debug$(END_NAME)
	$(CC) $(FLAGS) 70_human_model.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)70_human_model$(END_NAME)
	$(CC) $(FLAGS) 71_human_view.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)71_human_view$(END_NAME)
	$(CC) $(FLAGS) 72_human_controller.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)72_human_controller$(END_NAME)
	$(CC) $(FLAGS) 74_human_adapter.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)74_human_adapter$(END_NAME)

all: $(NAME)

play: re
	rm -rf test_debug
	touch test_debug
	./resources/filler_vm -p2 ./resources/players/carli.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map00 -s 3207

play_h: re
	./resources/filler_vm -p2 ./resources/players//abanlin.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map02


human: re
	gcc -Wall -Wextra -Werror 70_human_model.c obj/*.o -L./libft/build -lft -I./ -I./libft -o 70_human_model.filler
	gcc -Wall -Wextra -Werror 71_human_view.c -o 71_human_view.filler obj/*.o -L./libft/build -lft -I./ -I./libft
	gcc -Wall -Wextra -Werror 72_human_controller.c -o 72_human_controller.filler
	gcc -Wall -Wextra -Werror 74_human_adapter.c -o 74_human_adapter.filler obj/*.o -L./libft/build -lft -I./ -I./libft
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

$(PATH_S)00_debug_wfile.o: 00_debug_wfile.c
	$(CC) $(CFLAGS) 00_debug_wfile.c $(FLAG_PATH_OBJ)
$(PATH_S)01_debug_utf8.o: 01_debug_utf8.c
	$(CC) $(CFLAGS) 01_debug_utf8.c $(FLAG_PATH_OBJ)
$(PATH_S)03_debug_color.o: 03_debug_color.c
	$(CC) $(CFLAGS) 03_debug_color.c $(FLAG_PATH_OBJ)
$(PATH_S)04_debug_param.o: 04_debug_param.c
	$(CC) $(CFLAGS) 04_debug_param.c $(FLAG_PATH_OBJ)
$(PATH_S)10_read_map.o: 10_read_map.c
	$(CC) $(CFLAGS) 10_read_map.c $(FLAG_PATH_OBJ)
$(PATH_S)20_map_copy.o: 20_map_copy.c
	$(CC) $(CFLAGS) 20_map_copy.c $(FLAG_PATH_OBJ)
$(PATH_S)21_place_for_pie.o: 21_place_for_pie.c
	$(CC) $(CFLAGS) 21_place_for_pie.c $(FLAG_PATH_OBJ)
$(PATH_S)22_score.o: 22_score.c
	$(CC) $(CFLAGS) 22_score.c $(FLAG_PATH_OBJ)
$(PATH_S)23_find.o: 23_find.c
	$(CC) $(CFLAGS) 23_find.c $(FLAG_PATH_OBJ)
$(PATH_S)30_send_pie.o: 30_send_pie.c
	$(CC) $(CFLAGS) 30_send_pie.c $(FLAG_PATH_OBJ)
$(PATH_S)41_map_set.o: 41_map_set.c
	$(CC) $(CFLAGS) 41_map_set.c $(FLAG_PATH_OBJ)
$(PATH_S)42_map_reset.o: 42_map_reset.c
	$(CC) $(CFLAGS) 42_map_reset.c $(FLAG_PATH_OBJ)
$(PATH_S)43_map_force_set.o: 43_map_force_set.c
	$(CC) $(CFLAGS) 43_map_force_set.c $(FLAG_PATH_OBJ)
$(PATH_S)44_map_zone.o: 44_map_zone.c
	$(CC) $(CFLAGS) 44_map_zone.c $(FLAG_PATH_OBJ)
$(PATH_S)50_game.o: 50_game.c
	$(CC) $(CFLAGS) 50_game.c $(FLAG_PATH_OBJ)
$(PATH_S)73_human_send.o: 73_human_send.c
	$(CC) $(CFLAGS) 73_human_send.c $(FLAG_PATH_OBJ)
$(PATH_S)__mstack.o: __mstack.c
	$(CC) $(CFLAGS) __mstack.c $(FLAG_PATH_OBJ)


clean:
	rm -f $(PATH_SRC)

fclean: clean
	rm -f $(PATH_B)$(NAME)
	rm -f $(PATH_B)70_human_model$(END_NAME)
	rm -f $(PATH_B)71_human_view$(END_NAME)
	rm -f $(PATH_B)72_human_controller$(END_NAME)
	rm -f $(PATH_B)74_human_adapter$(END_NAME)
re: fclean all