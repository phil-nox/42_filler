# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laleta <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/07 19:28:58 by laleta            #+#    #+#              #
#    Updated: 2019/09/01 04:28:52 by laleta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = $(BIN_PATH)filler_visu_human
BIN_PATH = ../
BIN = filler_visu_human
FLAGS = -Wall -Wextra -Werror -g
SOURCE = main.c flrv_init.c flrv_init_player.c flrv_destroy.c flrv_util.c\
			flrv_draw_shape.c flrv_draw_header.c flrv_event.c flrv_set_shape.c
HEADER = flr_visual.h flr_loadfile.h flr_human_player.h

INCLUDES = -Iincludes -I$(LIBFT_DIR)includes $(CSFML_INCLUDE)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = $(BIN_PATH)libft/
CSFML_DIR = $(BIN_PATH)CSFML/
CSFML_DIRl = CSFML/
CSFML_INCLUDE = -I$(CSFML_DIR)include/SFML -I$(CSFML_DIR)include

LIB = -lft -lcsfml-graphics -lcsfml-window -lcsfml-audio -lcsfml-system
LIB_DIR = -L$(LIBFT_DIR) -L$(CSFML_DIR)lib
RPATH = -rpath,$(CSFML_DIRl)lib/,-rpath,$(CSFML_DIRl)Frameworks/

VPATH = srcs includes $(BIN_PATH)CSFML/lib $(BIN_PATH)CSFML/include/SFML

OBJECT = $(SOURCE:.c=.o)

.PHONY : clean fclean re

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECT)
	@echo "\033[1;3;34m"
	gcc $(FLAGS) $(OBJECT) -o $@ $(INCLUDES) $(LIB_DIR) -Wl,$(RPATH) $(LIB)
	@echo "\033[23;32m--[ "$(BIN) ]-- successfully compiled"\033[0m"

$(LIBFT) :
	@echo "\033[33;3m"
	@make -C $(LIBFT_DIR)
	@echo "\033[0m"

%.o : %.c $(HEADER)
	@echo "\033[36;3m"
	gcc $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "\033[0m"

clean :
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECT)

fclean : clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re : fclean all
