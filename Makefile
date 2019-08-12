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

NAME=wgorold.filler

CC=gcc

FLAGS= -Wall -Wextra -Werror

CFLAGS= -c $(FLAGS)

FLAG_PATH_OBJ= -o $@ -I./libft

PATH_B=./build/

PATH_S=./obj/

SRC= 	00_debug_wfile.o 01_debug_utf8.o 02_debug_base.o \
		03_debug_color.o 04_debug_score.o 10_read_map.o \
		20_place_for_pie_base.o 21_place_for_pie_find.o \
		22_place_for_pie_map.o 23_place_for_pie_score.o \
		24_place_for_pie_find_adv.o 30_send_pie.o \
		40_val_for_map_base.o 41_val_for_map_adv.o 90_old.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

$(NAME): $(PATH_SRC)
	$(CC) $(FLAGS) 50_creating_player.c obj/*.o -L./libft/build -lft -I./libft -o $(PATH_B)$(NAME)

all: $(NAME)

play: re
	./resources/filler_vm -p2 ./resources/players/carli.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map00

play_h: re
	./resources/filler_vm -p2 ./resources/players//abanlin.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map02

$(PATH_S)00_debug_wfile.o: 00_debug_wfile.c
	$(CC) $(CFLAGS) 00_debug_wfile.c $(FLAG_PATH_OBJ)
$(PATH_S)01_debug_utf8.o: 01_debug_utf8.c
	$(CC) $(CFLAGS) 01_debug_utf8.c $(FLAG_PATH_OBJ)
$(PATH_S)02_debug_base.o: 02_debug_base.c
	$(CC) $(CFLAGS) 02_debug_base.c $(FLAG_PATH_OBJ)
$(PATH_S)03_debug_color.o: 03_debug_color.c
	$(CC) $(CFLAGS) 03_debug_color.c $(FLAG_PATH_OBJ)
$(PATH_S)04_debug_score.o: 04_debug_score.c
	$(CC) $(CFLAGS) 04_debug_score.c $(FLAG_PATH_OBJ)
$(PATH_S)10_read_map.o: 10_read_map.c
	$(CC) $(CFLAGS) 10_read_map.c $(FLAG_PATH_OBJ)
$(PATH_S)20_place_for_pie_base.o: 20_place_for_pie_base.c
	$(CC) $(CFLAGS) 20_place_for_pie_base.c $(FLAG_PATH_OBJ)
$(PATH_S)21_place_for_pie_find.o: 21_place_for_pie_find.c
	$(CC) $(CFLAGS) 21_place_for_pie_find.c $(FLAG_PATH_OBJ)
$(PATH_S)22_place_for_pie_map.o: 22_place_for_pie_map.c
	$(CC) $(CFLAGS) 22_place_for_pie_map.c $(FLAG_PATH_OBJ)
$(PATH_S)23_place_for_pie_score.o: 23_place_for_pie_score.c
	$(CC) $(CFLAGS) 23_place_for_pie_score.c $(FLAG_PATH_OBJ)
$(PATH_S)24_place_for_pie_find_adv.o: 24_place_for_pie_find_adv.c
	$(CC) $(CFLAGS) 24_place_for_pie_find_adv.c $(FLAG_PATH_OBJ)
$(PATH_S)30_send_pie.o: 30_send_pie.c
	$(CC) $(CFLAGS) 30_send_pie.c $(FLAG_PATH_OBJ)
$(PATH_S)40_val_for_map_base.o: 40_val_for_map_base.c
	$(CC) $(CFLAGS) 40_val_for_map_base.c $(FLAG_PATH_OBJ)
$(PATH_S)41_val_for_map_adv.o: 41_val_for_map_adv.c
	$(CC) $(CFLAGS) 41_val_for_map_adv.c $(FLAG_PATH_OBJ)
$(PATH_S)90_old.o: 90_old.c
	$(CC) $(CFLAGS) 90_old.c $(FLAG_PATH_OBJ)

clean:
	rm -f $(PATH_SRC)

fclean: clean
	rm -f $(PATH_B)$(NAME)
re: fclean all