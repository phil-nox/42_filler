bot:
	make -C ../bot

visu:
	make -C ../visu

TARGET= 70_human_model.filler 74_human_adapter.filler \
		71_human_view.filler 72_human_controller.filler \
		filler_visu_human resources CSFML

PIPES= mypipe.map mypipe.cmd mypipe.adp mypipe.vm

move:
	echo "ok"
	cp ../bot/build/70_human_model.filler ./
	cp ../bot/build/71_human_view.filler ./
	cp ../bot/build/72_human_controller.filler ./
	cp ../bot/build/74_human_adapter.filler ./
	cp ../visu/filler_visu_human ./
	cp -r ../visu/resources ./
	cp -r ../visu/CSFML ./

all: visu bot move
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm" 
	@echo "./filler_vm -p2 ./players/carli.filler -p1 ./70_human_model.filler  -f ./maps/map01 -t 99 | ./74_human_adapter.filler | ./filler_visu_human" 
	@echo "---- OR ----"
	@echo "./run.sh" 

del:
	rm -rf $(TARGET) $(PIPES)

fclean:
	make fclean -C ../bot
	make fclean -C ../visu
	rm -rf $(TARGET) $(PIPES)

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