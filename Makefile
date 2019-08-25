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

NAME=boa.filler

PATH_H =./

CC=gcc

FLAGS= -Wall -Wextra -Werror

CFLAGS= -c $(FLAGS)

FLAG_PATH_OBJ= -o $@ -I./libft -I$(PATH_H)

PATH_B=./build/

PATH_S=./obj/

SRC= 	00_debug_wfile.o 01_debug_utf8.o \
		03_debug_color.o 10_read_map.o \
		30_send_pie.o 22_place_for_pie_map.o \
		41_val_for_map_set.o 21_place_for_pie_find.o \
		__mstack.o 42_val_for_map_reset.o 73_human_send.o
		
OTHER=	20_place_for_pie_base.o 21_place_for_pie_find.o \
		23_place_for_pie_score.o 02_debug_base.o\
		24_place_for_pie_find_adv.o 04_debug_score.o \
		40_val_for_map_base.o \
		42_val_for_map_reset.o 90_old.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

$(NAME): $(PATH_SRC)
	$(CC) $(FLAGS) 50_creating_player.c obj/*.o -L./libft/build -lft -I$(PATH_H) -I./libft -o $(PATH_B)$(NAME)

all: $(NAME)

play: re
	rm -rf test_debug
	touch test_debug
	./resources/filler_vm -p2 ./resources/players/carli.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map00 -t 1

play_h: re
	./resources/filler_vm -p2 ./resources/players//abanlin.filler -p1 $(PATH_B)$(NAME) -f ./resources/maps/map02


human: re
	gcc -Wall -Wextra -Werror 70_human_model.c obj/*.o -L./libft/build -lft -I./ -I./libft  -o 70_human_model.filler
	gcc -Wall -Wextra -Werror 71_human_view.c -o 71_human_view.filler
	gcc -Wall -Wextra -Werror 72_human_controller.c -o 72_human_controller.filler
	@echo " "
	@echo "RUN >>>>"
	@echo "./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./70_human_model.filler  -f ./resources/maps/map00 -t 99"
	@echo "./71_human_view.filler"
	@echo "./72_human_controller.filler"
	@echo "<<<<"

$(PATH_S)73_human_send.o: 73_human_send.c
	$(CC) $(CFLAGS) 73_human_send.c $(FLAG_PATH_OBJ)
$(PATH_S)__mstack.o: __mstack.c
	$(CC) $(CFLAGS) __mstack.c $(FLAG_PATH_OBJ)
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
$(PATH_S)41_val_for_map_set.o: 41_val_for_map_set.c
	$(CC) $(CFLAGS) 41_val_for_map_set.c $(FLAG_PATH_OBJ)
$(PATH_S)42_val_for_map_reset.o: 42_val_for_map_reset.c
	$(CC) $(CFLAGS) 42_val_for_map_reset.c $(FLAG_PATH_OBJ)
$(PATH_S)90_old.o: 90_old.c
	$(CC) $(CFLAGS) 90_old.c $(FLAG_PATH_OBJ)

clean:
	rm -f $(PATH_SRC)

fclean: clean
	rm -f $(PATH_B)$(NAME)
re: fclean all