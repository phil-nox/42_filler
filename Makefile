# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 16:06:58 by wgorold           #+#    #+#              #
#    Updated: 2019/09/21 16:27:21 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wgorold.filler

all: mbot
	cp ./bot/build/squid.filler ./$(NAME)

mbot:
	make -C ./bot

clean:
	make clean -C ./bot

fclean:
	make fclean -C ./bot
	rm -f $(NAME)

re: fclean all