#!/bin/bash
rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp
PATH_BOT=./players/
BOT=carli.filler
while true; do
    clear
    echo -e "For run game select bot 👇\n"
    select bot in $(ls ./players)
    do
        BOT=$bot
        break
    done
    echo $BOT
	./filler_visu_human &
    PID_VISU=$!
    echo $PID_VISU
    ./filler_vm -p1 ./70_human_model.filler -p2 $PATH_BOT$BOT -f ./maps/map00 -t 99 | ./74_human_adapter.filler
    wait $PID_VISU
    echo "next"
done