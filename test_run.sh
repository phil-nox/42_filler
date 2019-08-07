#!/bin/bash
make -C./libft && make re && gcc test_put.c obj/*.o -L./libft/build -lft -I./libft -o read.filler
rm test_out test_debug && touch test_out test_debug
./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./read.filler -f ./resources/maps/map00 -t 1