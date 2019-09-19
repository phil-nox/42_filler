# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/19 14:42:22 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C ../
	make -C ../../visu
	

run: all
	./make_games.sh

clean: 
	find ./result -type f -not -name '.gitkeep' -delete