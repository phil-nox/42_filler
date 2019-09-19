# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/03 20:55:37 by wgorold           #+#    #+#              #
#    Updated: 2019/09/19 16:11:05 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make -C ../bot
	make -C ../visu
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
	
run: all
	./make_games.sh

clean: 
	find ./result -type f -not -name '.gitkeep' -delete

fclean:
	make fclean -C ../bot
	make fclean -C ../visu
	find ./resources_my -type f -not -name '.gitkeep' -delete
	find ./result -type f -not -name '.gitkeep' -delete
	find ./resources_my -type d -delete
	rm -rf filler.trace