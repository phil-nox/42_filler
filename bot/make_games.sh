#!/bin/bash
#run after make

cd games

PATH_R="../resources"
YOUR_PLY="../build/boa.filler"
DEBUG_PLY="../build/boa_debug.filler"

IDX=0
CMD_BASE=$PATH_R/filler_vm
CMD=''
#../resources/filler_vm -p2 ../resources/players/carli.filler -p1 ../build/wgorold.filler -f ../resources/maps/map00

for map in $PATH_R/maps/*; do
    #((IDX+=1))
    #echo $IDX
    #echo $map
    for player in $PATH_R/players/*; do
        ((IDX+=1))
        CMD="$CMD_BASE -p1 $YOUR_PLY -p2 $player -f $map -q"
        CMD_D="$CMD_BASE -p1 $DEBUG_PLY -p2 $player -f $map"
        echo $IDX
        echo $CMD
        $($CMD)
        echo "$CMD -s $(grep seed filler.trace | sed 's/seed = //')" >> filler.trace
        echo "$CMD_D -s $(grep seed filler.trace | sed 's/seed = //')" >> filler.trace
        mv filler.trace filler.trace$IDX

        ((IDX+=1))
        CMD="$CMD_BASE -p2 $YOUR_PLY -p1 $player -f $map -q"
        CMD_D="$CMD_BASE -p2 $DEBUG_PLY -p1 $player -f $map"
        echo $IDX
        echo $CMD
        $($CMD)
        echo "$CMD -s $(grep seed filler.trace | sed 's/seed = //')" >> filler.trace
        echo "$CMD_D -s $(grep seed filler.trace | sed 's/seed = //')"  >> filler.trace
        mv filler.trace filler.trace$IDX
    done
done