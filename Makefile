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

CC=gcc

CFLAGS= -c -Wall -Wextra -Werror -g

FLAG_PATH_OBJ= -o $@ -I./libft

PATH_S=./obj/

SRC= 	0_debug.o 1_read_map.o 2_place_for_pie.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

all: $(PATH_SRC)

$(PATH_S)0_debug.o: 0_debug.c
	$(CC) $(CFLAGS) 0_debug.c $(FLAG_PATH_OBJ)
$(PATH_S)1_read_map.o: 1_read_map.c
	$(CC) $(CFLAGS) 1_read_map.c $(FLAG_PATH_OBJ)
$(PATH_S)2_place_for_pie.o: 2_place_for_pie.c
	$(CC) $(CFLAGS) 2_place_for_pie.c $(FLAG_PATH_OBJ)

clean:
	rm -f $(PATH_SRC)

fclean: clean

re: fclean all