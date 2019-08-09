#!/bin/bash
#make -C./libft && make re && gcc test_put.c obj/*.o -L./libft/build -lft -I./libft -o read.filler
#rm test_out test_debug && touch test_out test_debug
#./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1

#cd /Users/wgorold/d06_filler_gitlab &&  ./test_run.sh -g 

if [ $# -eq 0 ]
    then
        USERS=$(find . -maxdepth 1 -name 'test_*.c')

        PS3="Please choose a TEST to run : "
        echo ""
        select choice in $USERS "Exit"
        do
        break
        done
    else
        case $1 in
        -a)
            choice="test_adv.c"
            ;;

        -g)
            choice="test_game.c"
            ;;

        -v)
            choice="test_val.c"
            ;;

        -s)
            choice="test_send.c"
            ;;

        -p)
            choice="test_put.c"
            ;;

        -r)
            choice="test_read_map.c"
            ;;

        *)
            choice="test_put.c"
            ;;
        esac
fi


echo -e "The Choice => $choice\n"
make -C./libft && make re && gcc $choice obj/*.o -L./libft/build -lft -I./libft -o read.filler
rm test_out test_debug && touch test_out test_debug
./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1