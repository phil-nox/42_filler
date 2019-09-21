# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/16 15:18:41 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# How 2 make this Makefile
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c//" | while read x ; do echo "\$(PATH_S)$x.o: $x.c\n\t\$(CC) \$(CFLAGS) $x.c \$(FLAG_PATH_OBJ)" ; done
#
# 	find . -maxdepth 1 -name '*.c' | sed "s/\.\///" | sed "s/\.c/\.o/" | tr '\n' ' '
#

NAME=libft.a

CC=gcc

CFLAGS= -c -Wall -Wextra -Werror -g

FLAG_PATH_OBJ= -o $@

PATH_S=./obj/

SRC= 	ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o \
		ft_isdigit.o ft_isprint.o ft_itoa.o ft_lstadd.o ft_lstdel.o \
		ft_lstdelone.o ft_lstfree.o ft_lstfreeone.o ft_lstiter.o \
		ft_lstjoin.o ft_lstlen.o ft_lstmap.o ft_lstnew.o \
		ft_lstprintstr.o ft_lstpush.o ft_lstsplit.o ft_memalloc.o \
		ft_memccpy.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memdel.o \
		ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
		ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o \
		ft_putstr.o ft_putstr_fd.o ft_strajoin.o ft_strcat.o \
		ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o \
		ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o \
		ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlen.o \
		ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o \
		ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o \
		ft_strrchr.o ft_strsplit.o ft_strstr.o ft_strsub.o \
		ft_strtrim.o ft_tolower.o ft_toupper.o get_next_line.o

PATH_SRC= $(patsubst %.o, $(PATH_S)%.o, $(SRC))

all: $(NAME)

$(NAME): $(PATH_SRC)

$(PATH_S)ft_atoi.o: ft_atoi.c
	$(CC) $(CFLAGS) ft_atoi.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_bzero.o: ft_bzero.c
	$(CC) $(CFLAGS) ft_bzero.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_isalnum.o: ft_isalnum.c
	$(CC) $(CFLAGS) ft_isalnum.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_isalpha.o: ft_isalpha.c
	$(CC) $(CFLAGS) ft_isalpha.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_isascii.o: ft_isascii.c
	$(CC) $(CFLAGS) ft_isascii.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_isdigit.o: ft_isdigit.c
	$(CC) $(CFLAGS) ft_isdigit.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_isprint.o: ft_isprint.c
	$(CC) $(CFLAGS) ft_isprint.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_itoa.o: ft_itoa.c
	$(CC) $(CFLAGS) ft_itoa.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstadd.o: ft_lstadd.c
	$(CC) $(CFLAGS) ft_lstadd.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstdel.o: ft_lstdel.c
	$(CC) $(CFLAGS) ft_lstdel.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstdelone.o: ft_lstdelone.c
	$(CC) $(CFLAGS) ft_lstdelone.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstfree.o: ft_lstfree.c
	$(CC) $(CFLAGS) ft_lstfree.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstfreeone.o: ft_lstfreeone.c
	$(CC) $(CFLAGS) ft_lstfreeone.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstiter.o: ft_lstiter.c
	$(CC) $(CFLAGS) ft_lstiter.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstjoin.o: ft_lstjoin.c
	$(CC) $(CFLAGS) ft_lstjoin.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstlen.o: ft_lstlen.c
	$(CC) $(CFLAGS) ft_lstlen.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstmap.o: ft_lstmap.c
	$(CC) $(CFLAGS) ft_lstmap.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstnew.o: ft_lstnew.c
	$(CC) $(CFLAGS) ft_lstnew.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstprintstr.o: ft_lstprintstr.c
	$(CC) $(CFLAGS) ft_lstprintstr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstpush.o: ft_lstpush.c
	$(CC) $(CFLAGS) ft_lstpush.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_lstsplit.o: ft_lstsplit.c
	$(CC) $(CFLAGS) ft_lstsplit.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memalloc.o: ft_memalloc.c
	$(CC) $(CFLAGS) ft_memalloc.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memccpy.o: ft_memccpy.c
	$(CC) $(CFLAGS) ft_memccpy.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memchr.o: ft_memchr.c
	$(CC) $(CFLAGS) ft_memchr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memcmp.o: ft_memcmp.c
	$(CC) $(CFLAGS) ft_memcmp.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memcpy.o: ft_memcpy.c
	$(CC) $(CFLAGS) ft_memcpy.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memdel.o: ft_memdel.c
	$(CC) $(CFLAGS) ft_memdel.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memmove.o: ft_memmove.c
	$(CC) $(CFLAGS) ft_memmove.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_memset.o: ft_memset.c
	$(CC) $(CFLAGS) ft_memset.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putchar.o: ft_putchar.c
	$(CC) $(CFLAGS) ft_putchar.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putchar_fd.o: ft_putchar_fd.c
	$(CC) $(CFLAGS) ft_putchar_fd.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putendl.o: ft_putendl.c
	$(CC) $(CFLAGS) ft_putendl.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putendl_fd.o: ft_putendl_fd.c
	$(CC) $(CFLAGS) ft_putendl_fd.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putnbr.o: ft_putnbr.c
	$(CC) $(CFLAGS) ft_putnbr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putnbr_fd.o: ft_putnbr_fd.c
	$(CC) $(CFLAGS) ft_putnbr_fd.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putstr.o: ft_putstr.c
	$(CC) $(CFLAGS) ft_putstr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_putstr_fd.o: ft_putstr_fd.c
	$(CC) $(CFLAGS) ft_putstr_fd.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strajoin.o: ft_strajoin.c
	$(CC) $(CFLAGS) ft_strajoin.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strcat.o: ft_strcat.c
	$(CC) $(CFLAGS) ft_strcat.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strchr.o: ft_strchr.c
	$(CC) $(CFLAGS) ft_strchr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strclr.o: ft_strclr.c
	$(CC) $(CFLAGS) ft_strclr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strcmp.o: ft_strcmp.c
	$(CC) $(CFLAGS) ft_strcmp.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strcpy.o: ft_strcpy.c
	$(CC) $(CFLAGS) ft_strcpy.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strdel.o: ft_strdel.c
	$(CC) $(CFLAGS) ft_strdel.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strdup.o: ft_strdup.c
	$(CC) $(CFLAGS) ft_strdup.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strequ.o: ft_strequ.c
	$(CC) $(CFLAGS) ft_strequ.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_striter.o: ft_striter.c
	$(CC) $(CFLAGS) ft_striter.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_striteri.o: ft_striteri.c
	$(CC) $(CFLAGS) ft_striteri.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strjoin.o: ft_strjoin.c
	$(CC) $(CFLAGS) ft_strjoin.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strlcat.o: ft_strlcat.c
	$(CC) $(CFLAGS) ft_strlcat.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strlen.o: ft_strlen.c
	$(CC) $(CFLAGS) ft_strlen.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strmap.o: ft_strmap.c
	$(CC) $(CFLAGS) ft_strmap.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strmapi.o: ft_strmapi.c
	$(CC) $(CFLAGS) ft_strmapi.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strncat.o: ft_strncat.c
	$(CC) $(CFLAGS) ft_strncat.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strncmp.o: ft_strncmp.c
	$(CC) $(CFLAGS) ft_strncmp.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strncpy.o: ft_strncpy.c
	$(CC) $(CFLAGS) ft_strncpy.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strnequ.o: ft_strnequ.c
	$(CC) $(CFLAGS) ft_strnequ.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strnew.o: ft_strnew.c
	$(CC) $(CFLAGS) ft_strnew.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strnstr.o: ft_strnstr.c
	$(CC) $(CFLAGS) ft_strnstr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strrchr.o: ft_strrchr.c
	$(CC) $(CFLAGS) ft_strrchr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strsplit.o: ft_strsplit.c
	$(CC) $(CFLAGS) ft_strsplit.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strstr.o: ft_strstr.c
	$(CC) $(CFLAGS) ft_strstr.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strsub.o: ft_strsub.c
	$(CC) $(CFLAGS) ft_strsub.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_strtrim.o: ft_strtrim.c
	$(CC) $(CFLAGS) ft_strtrim.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_tolower.o: ft_tolower.c
	$(CC) $(CFLAGS) ft_tolower.c $(FLAG_PATH_OBJ)
$(PATH_S)ft_toupper.o: ft_toupper.c
	$(CC) $(CFLAGS) ft_toupper.c $(FLAG_PATH_OBJ)
$(PATH_S)get_next_line.o: get_next_line.c
	$(CC) $(CFLAGS) get_next_line.c $(FLAG_PATH_OBJ)

clean:
	find $(PATH_S) -type f -not -name '.gitkeep' -delete

fclean: clean

re: fclean all