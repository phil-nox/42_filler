#!/bin/bash
rm -f mypipe.*
rm -f tmp_pty
mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm

MAP=map01

wait_pseudoterminal() {
  while [ ! -f "tmp_pty" ]
  do
    echo "wait for creation of Pseudoterminal, name will be save to tmp_pty file"
    sleep 1
  done
}

control_msg() {
  echo -e "\nUse  ⬆️\n"
  echo -e "  ⬅️  ⬇️  ➡️\n"
  echo -e "For select press 'space' or 'enter' \n\n"
}

( cd visu; ./filler_visu_human ) &
PID_VISU=$!
echo $PID_VISU
#./74_human_adapter.filler &
open ./r_adapter.command

wait_pseudoterminal
TMP_PTY=$(cat tmp_pty)
echo Pseudoterminal= $TMP_PTY

control_msg

./resources/filler_vm -p1 ./bot/build/70_human_model.filler \
-p2 ./bot/build/squid.filler -f ./resources/maps/$MAP -t 99 > $TMP_PTY
wait $PID_VISU
pgrep -f adapter | xargs kill -9
echo -e "Game over - 👇  check result with next command:\ncat filler.trace\n"
