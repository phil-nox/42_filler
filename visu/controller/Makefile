# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laleta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 19:28:58 by laleta            #+#    #+#              #
#    Updated: 2019/08/27 20:13:37 by laleta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler_controller
FLAGS = -Wall -Wextra -Werror
SOURCE = flrc_controller.c

INCLUDES = $(CSFML_INCLUDE)

#LIBFT = $(LIBFT_DIR)libft.a
#LIBFT_DIR = libft/
CSFML_DIR = ../CSFML/
CSFML_INCLUDE = -I$(CSFML_DIR)include/SFML -I$(CSFML_DIR)include

LIB = -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
LIB_DIR = -L$(CSFML_DIR)lib
RPATH = -rpath,$(CSFML_DIR)lib/,-rpath,$(CSFML_DIR)Frameworks/

VPATH = ../CSFML/lib ../CSFML/include/SFML

OBJECT = $(SOURCE:.c=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJECT)
	@echo "\033[1;3;34m"
	gcc $(FLAGS) $(OBJECT) -o $@ $(INCLUDES) $(LIB_DIR) -Wl,$(RPATH) $(LIB)
	@echo "\033[23;32m--[ "$(NAME) ]-- successfully compiled"\033[0m"

#$(LIBFT) :
#	@echo "\033[33;3m"
#	@make -C $(LIBFT_DIR)
#	@echo "\033[0m"

%.o : %.c
	@echo "\033[36;3m"
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[0m"

clean :
#	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECT)

fclean : clean
#	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re : fclean all
