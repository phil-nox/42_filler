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
  echo -e "👇👇\n"
  echo -e "Now you can play a game in terminals 😉\n"
  echo -e "You can see what is going on in terminal with r_view.command"
  echo -e "And control the game by input next list of character Enter-separated in terminal with r_controller.command\n"
  echo -e "\t'w' - move up\n"
  echo -e "\t's' - move down\n"
  echo -e "\t'd' - move right\n"
  echo -e "\t'a' - move left\n\n"
  echo -e "\t'e' - put figure in position\n"
  echo -e "\t'q' - start autoplay\n"
  echo -e "You can see what is going on in terminal with r_view.command\n"
  echo -e "👆👆\n"
}

open ./r_adapter.command
open ./r_view.command
open ./r_controller.command

wait_pseudoterminal
control_msg

TMP_PTY=$(cat tmp_pty)
echo pseudoterminal is $TMP_PTY
echo "./resources/filler_vm -p1 ./bot/build/70_human_model.filler -p2 ./bot/build/squid.filler -f ./resources/maps/$MAP -t 99 > $TMP_PTY"
./resources/filler_vm -p1 ./bot/build/70_human_model.filler -p2 ./bot/build/squid.filler -f ./resources/maps/$MAP -t 99 > $TMP_PTY
