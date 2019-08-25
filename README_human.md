#Check folder "human_control" as a general example.

make human

#Then run next lines in three different terminals
    ./resources/filler_vm -p2 ./resources/players/carli.filler -p1 ./70_human_model.filler  -f ./resources/maps/map00 -t 99
    ./71_human_view.filler
    ./72_human_controller.filler