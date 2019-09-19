#!/bin/bash
#run after make

PATH_R="./resources"
YOUR_PLY="./resources_my/squid.filler"
DEBUG_PLY="./resources_my/squid_debug.filler"

IDX=0
CMD_BASE=$PATH_R/filler_vm
CMD=''

CMD_VISU="cd resources_my ; ../resources/filler_vm"
YOUR_PLY_VISU="./squid.filler"
#../resources/filler_vm -p2 ../resources/players/carli.filler -p1 ../build/wgorold.filler -f ../resources/maps/map00

for map in $PATH_R/maps/*; do
    #((IDX+=1))
    #echo $IDX
    #echo $map
    for player in $PATH_R/players/*; do
        ((IDX+=1))
        CMD="$CMD_BASE -p1 $YOUR_PLY -p2 $player -f $map"
        CMD_D="$CMD_BASE -p1 $DEBUG_PLY -p2 $player -f $map"
        CMD_V="$CMD_VISU -p1 $YOUR_PLY_VISU -p2 .$player -f .$map"
        echo $IDX
        echo $CMD
        eval "$CMD -q"
        echo "$CMD -s $(grep seed filler.trace | sed 's/seed = //')" >> filler.trace
        echo "$CMD_D -s $(grep seed filler.trace | sed 's/seed = //')" >> filler.trace
        echo "$CMD_V -s $(grep seed filler.trace | sed 's/seed = //') | ./filler_visu_vm" >> filler.trace
        mv filler.trace ./result/filler.trace$IDX

        ((IDX+=1))
        CMD="$CMD_BASE -p2 $YOUR_PLY -p1 $player -f $map"
        CMD_D="$CMD_BASE -p2 $DEBUG_PLY -p1 $player -f $map"
        CMD_V="$CMD_VISU -p2 $YOUR_PLY_VISU -p1 .$player -f .$map"
        echo $IDX
        echo $CMD
        eval "$CMD -q"
        echo "$CMD -s $(grep seed filler.trace | sed 's/seed = //')" >> filler.trace
        echo "$CMD_D -s $(grep seed filler.trace | sed 's/seed = //')"  >> filler.trace
        echo "$CMD_V -s $(grep seed filler.trace | sed 's/seed = //') | ./filler_visu_vm" >> filler.trace
        mv filler.trace ./result/filler.trace$IDX
    done
done