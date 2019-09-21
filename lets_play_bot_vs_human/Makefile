# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/21 15:54:21 by wgorold           #+#    #+#              #
#    Updated: 2019/09/21 15:54:49 by wgorold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET= 70_human_model.filler 74_human_adapter.filler \
		71_human_view.filler 72_human_controller.filler \
		filler_visu_human resources CSFML

PIPES= mypipe.map mypipe.cmd mypipe.adp mypipe.vm

CMD= r_adapter.command r_controller.command r_view.command

all: visu bot move
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm" 
	@echo "./filler_vm -p2 ./players/carli.filler -p1 ./70_human_model.filler  -f ./maps/map01 -t 99 | ./74_human_adapter.filler | ./filler_visu_human" 
	@echo "---- OR ----"
	@echo "./run.sh" 

bot:
	make -C ../bot

visu:
	make -C ../visu

move:
	echo "ok"
	cp ../bot/build/70_human_model.filler ./
	cp ../bot/build/71_human_view.filler ./
	cp ../bot/build/72_human_controller.filler ./
	cp ../bot/build/74_human_adapter.filler ./
	cp ../visu/filler_visu_human ./
	cp -r ../visu/resources ./
	cp -r ../visu/CSFML ./

del:
	rm -rf $(TARGET) $(PIPES) $(CMD) filler.trace test_debug

clean:
	make clean -C ../bot
	make clean -C ../visu

fclean:
	make fclean -C ../bot
	make fclean -C ../visu
	rm -rf $(TARGET) $(PIPES) $(CMD) filler.trace test_debug

re: fclean all

q: del visu bot move
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm" 
	@echo "./filler_vm -p2 ./players/carli.filler -p1 ./70_human_model.filler  -f ./maps/map01 -t 99 | ./74_human_adapter.filler | ./filler_visu_human" 
	@echo "---- OR ----"
	@echo "./run.sh" 

t: del visu bot move
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm" 
	@echo "./filler_vm -p2 ./players/carli.filler -p1 ./players/carli.filler  -f ./maps/map01 -t 99 | ./74_human_adapter.filler" 
	@echo "---- OR ----"
	@echo "./run.sh" 