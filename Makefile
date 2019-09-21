# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 16:06:58 by wgorold           #+#    #+#              #
#    Updated: 2019/09/21 19:54:48 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOT=bot/build/squid.filler
NAME=wgorold.filler

all: $(NAME)

$(NAME): $(BOT)
	cp ./bot/build/squid.filler ./$(NAME)

$(BOT):
	make -C ./bot

clean:
	make clean -C ./bot

fclean:
	make fclean -C ./bot
	rm -f $(NAME)

re: fclean all