# FILLER

make

rm mypipe.\*; mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm; chmod 777 mypipe.*

'bot vs bot'

./filler_vm -f maps/map00 -p1 players/carli.filler -p2 players/hcao.filler|./filler_visu_vm


'human vs bot'

./filler_vm -f maps/map00 -p1 ./70_human_model.filler -p2 players/hcao.filler|./74_human_adapter.filler
./filler_visu_human
