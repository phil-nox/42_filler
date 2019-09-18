#!/bin/bash
rm mypipe.*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm
PATH_BOT=./players/
BOT=carli.filler
MAP=map01
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

while getopts "bs" OPTION
do
	case $OPTION in
        s)
            MAP=map00
            ;;
		b)
            MAP=map02
			;;
	esac
done


if [ "$1" == "-t" ]; then
    choice
	BOT=${PLAYERS[$CUR]}
    echo -en "\n$BOT\n"
    open ./r_adapter.command
    open ./r_view.command
    open ./r_controller.command
    #tail r_here > mypipe.vm
    sleep 1
    TMP_PTY=$(cat tmp_pty)
    echo $TMP_PTY
    echo "./filler_vm -p1 ./70_human_model.filler -p2 $PATH_BOT$BOT -f ./maps/$MAP -t 99 > $TMP_PTY"
    ./filler_vm -p1 ./70_human_model.filler -p2 $PATH_BOT$BOT -f ./maps/$MAP -t 99 > $TMP_PTY
else
    while true; do
        clear
        echo -e "Use  ⬆️\n"
        echo -e "  ⬅️  ⬇️  ➡️\n"
        echo -e "For select press 'space' or 'enter' \n\n"
        echo -e "For run game select bot 👇\n"
        choice
        BOT=${PLAYERS[$CUR]}
        echo -en "\n$BOT\n"
        ./filler_visu_human &
        PID_VISU=$!
        echo $PID_VISU
        #./74_human_adapter.filler &
        open ./r_adapter.command
        sleep 1
        TMP_PTY=$(cat tmp_pty)
        echo $TMP_PTY
        ./filler_vm -p1 ./70_human_model.filler -p2 $PATH_BOT$BOT -f ./maps/$MAP -t 99 > $TMP_PTY
        wait $PID_VISU
        pgrep -f adapter | xargs kill -9
        echo "next"
    done
fi

#tail -f /proc/57222/fd/1