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
VISU=visu/filler_visu_human
THIS_PATH := $(shell pwd)

all: game

game: $(BOT) $(VISU)
	make create_sup_files
	@echo "For run game use next 👇  command:"
	@echo "./run.sh\n"

$(BOT):
	make -C ./bot

$(VISU):
	make -C ./visu

create_sup_files:
	@echo "#!/bin/bash\ncd" $(THIS_PATH) \
	"\n#lldb -o run ./bot/build/74_human_adapter.filler \
	\n./bot/build/74_human_adapter.filler" \
	> r_adapter.command
	@chmod +x r_adapter.command
	@echo "#!/bin/bash\ncd" $(THIS_PATH) \
	"\n./bot/build/72_human_controller.filler" \
	> r_controller.command
	@chmod +x r_controller.command
	@echo "#!/bin/bash\ncd" $(THIS_PATH) \
	"\n./bot/build/71_human_view.filler" \
	> r_view.command
	@chmod +x r_view.command

del_sup_files:
	rm -f r_adapter.command r_controller.command r_view.command
	rm -f filler.trace

clean:
	make clean -C ./bot
	make clean -C ./visu

fclean:
	make fclean -C ./bot
	make fclean -C ./visu
	make del_sup_files

re: fclean all
