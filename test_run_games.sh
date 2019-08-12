#!/bin/bash
#run after make

cd games

PATH_R="../resources"
YOUR_PLY="../build/wgorold.filler"

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
        echo $IDX
        echo $CMD
        $($CMD)
        echo "$CMD -s $(grep seed filler.trace | sed 's/seed = //')"  >> filler.trace
        mv filler.trace filler.trace$IDX

        ((IDX+=1))
        CMD="$CMD_BASE -p2 $YOUR_PLY -p1 $player -f $map -q"
        echo $IDX
        echo $CMD
        $($CMD)
        echo "$CMD -s $(grep seed filler.trace | sed 's/seed = //')"  >> filler.trace
        mv filler.trace filler.trace$IDX
    done
done