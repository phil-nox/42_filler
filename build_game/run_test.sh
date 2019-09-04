#!/bin/bash
#source ./run_draw_menu.sh

while true
do
    read -r -sn1 t
    if [[ "$t" == "" ]]; then break; fi
    case $t in
        A) echo -en "   up         \r";;
        B) echo -en "   down       \r";;
        C) echo -en "   right      \r";;
        D) echo -en "   \033[0;35;1mleft\033[0m       \r";;
    esac
done
#column -t