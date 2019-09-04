bot:
	make human -C ../bot

visu:
	make -C ../visu

move:
	echo "ok"
	cp ../bot/70_human_model.filler ./
	cp ../bot/74_human_adapter.filler ./
	cp ../visu/filler_visu_human ./
	cp -r ../visu/resources ./
	cp ../visu/CSFML ./

all: visu bot move
	@echo "rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp" 
	@echo "./filler_vm -p2 ./players/carli.filler -p1 ./70_human_model.filler  -f ./maps/map01 -t 99 | ./74_human_adapter.filler | ./filler_visu_human" 