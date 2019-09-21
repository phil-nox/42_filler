# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/21 20:07:47 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=build/libft.a

PATH_LIB=libft_gnl
PATH_PRN=ft_printf

all: $(NAME)

$(NAME): mlibft mprintf
	ar rc $(NAME) $(PATH_PRN)/obj/*.o $(PATH_LIB)/obj/*.o

mlibft:
	make -C $(PATH_LIB)

mprintf:
	make -C $(PATH_PRN)

clean:
	make clean -C $(PATH_LIB)
	make clean -C $(PATH_PRN)

fclean: clean
	rm -f $(NAME);

re: fclean all