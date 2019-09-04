#!/bin/bash
rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp
PATH_BOT=./players/
BOT=carli.filler
PLAYERS=( $(ls ./players) )
LIM=${#PLAYERS[@]}
CUR=0

show() {
    i=0
    echo -en "\t"
    while ((i < $LIM))
    do
        if [[ "$i" == "$CUR" ]]; then 
            echo -en "\033[0;35;1m"
        fi

        echo -en "${PLAYERS[$i]}  "
        
        if [[ "$i" == "$CUR" ]]; then 
            echo -en "\033[0m"
        fi
        ((i++))

    done
    echo -en "\r"
}

choice() {
    show
    while true
    do
        read -r -sn1 t
        if [[ "$t" == "" ]]; then break; fi
        case $t in
            A | D) ((CUR > 0)) && ((CUR--)) ; show;;
            B | C) ((CUR < $LIM - 1)) && ((CUR++)) ; show;;
        esac
    done
}


while true; do
    clear
    echo -e "Use  ⬆️\n"
    echo -e "  ⬅️  ⬇️  ➡️\n"
    echo -e "For select press 'space' or 'enter' \n\n"
    echo -e "For run game select bot 👇\n"
    CUR=0
    choice
    BOT=${PLAYERS[$CUR]}
    echo -en "\n$BOT\n"
	./filler_visu_human &
    PID_VISU=$!
    echo $PID_VISU
    ./filler_vm -p1 ./70_human_model.filler -p2 $PATH_BOT$BOT -f ./maps/map01 -t 99 | ./74_human_adapter.filler
    wait $PID_VISU
    echo "next"
done