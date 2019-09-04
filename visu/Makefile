# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laleta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 19:28:58 by laleta            #+#    #+#              #
#    Updated: 2019/09/04 21:20:39 by laleta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_visual

DIR_VISU_VM = flr_visu_vm/
DIR_VISU_HUMAN = flr_visu_human/

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) :
	make -C $(DIR_VISU_VM)
	make -C $(DIR_VISU_HUMAN)

clean :
	@make -C $(DIR_VISU_VM) clean
	@make -C $(DIR_VISU_HUMAN) clean

fclean : clean
	@make -C $(DIR_VISU_VM) fclean
	@make -C $(DIR_VISU_HUMAN) fclean

re : fclean all
