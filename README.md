### step 0
make
## rmq
Folder resources contains code given a task.
- resources/players contains default bots. But with high probability, they will not work on your. machine


### step 1
## run bot_vs_bot without visualization
./resources/filler_vm -f ./resources/maps/map00 -p1 ./bot/build/squid.filler -p2 ./bot/build/squid.filler


### step 2
## run bot_vs_human without visualization by hand
You will need 4 separated terminals which should be open in this directory (where you read this README file).
Then do next things in one of them:
  rm mypipe.*
  rm tmp_pty
  mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm; chmod 777 mypipe.*

Then run next commands (one command per terminal):
  ./bot/build/74_human_adapter.filler
  ./bot/build/71_human_view.filler
  ./bot/build/72_human_controller.filler
  ./resources/filler_vm -p1 ./bot/build/70_human_model.filler -p2 ./bot/build/squid.filler -f ./resources/maps/map00 -t 99 > $(cat tmp_pty)


### step 3
## run bot_vs_human without visualization by script
  ./run_without_visu.sh


### step 4
## run bot_vs_bot with visu by hand
  cd visu
  ../resources/filler_vm -f ../resources/maps/map01 -p1 ../bot/build/squid.filler -p2 ../bot/build/squid.filler | ./filler_visu_vm


### step 5
## run bot_vs_bot with visu by hand
  cd visu
  ../resources/filler_vm -f ../resources/maps/map01 -p1 ../bot/build/squid.filler -p2 ../bot/build/squid.filler | ./filler_visu_vm
