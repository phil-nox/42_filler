# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/21 20:39:31 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOT=../bot/build/squid.filler
VISU=../visu/filler_visu_vm

all: this

this: $(BOT) $(VISU)
	cp ../bot/build/70_human_model.filler ./resources_my/
	cp ../bot/build/71_human_view.filler ./resources_my/
	cp ../bot/build/72_human_controller.filler ./resources_my/
	cp ../bot/build/74_human_adapter.filler ./resources_my/

	cp ../visu/filler_visu_vm ./resources_my/
	cp ../visu/filler_visu_human ./resources_my/
	cp -r ../visu/resources ./resources_my/
	cp -r ../visu/CSFML ./resources_my/
	
	cp ../bot/build/squid.filler ./resources_my/
	cp ../bot/build/squid_debug.filler ./resources_my/

	@echo "👇 👇 👇 👇  Now you can run"
	@echo "./make_games.sh"

$(BOT):
	make -C ../bot

$(VISU):
	make -C ../visu

run: all
	./make_games.sh

clean:
	make clean -C ../bot
	make clean -C ../visu
	find ./result -type f -not -name '.gitkeep' -delete

fclean:
	make fclean -C ../bot
	make fclean -C ../visu
	find ./result -type f -not -name '.gitkeep' -delete
	rm -rf filler.trace test_debug
	find ./resources_my -depth 1 -not -name '.gitkeep' -exec rm -rf {} \;