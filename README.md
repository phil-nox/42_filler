# Filler_game

Originally this is one of the projects in a branch of algorithms at School 42 . The original name of the project is Filler.

<details>
  <summary>Description of the game (original papers):</summary>

  Filler is an algorithmic game which consists in filling a grid of a known size in advance
  with pieces of random size and shapes, without the pieces being stacked more than one
  square above each other and without them exceeding the grid. If one of these conditions
  is not met, the game stops.

  Each successfully placed piece yields a number of points, and has only one player, the
  goal of the game could be to get the best score possible. However, it is with two players
  that the filler takes all his interest. Each player has for the purpose of placing as many
  pieces as possible while attempting to prevent his opponent from doing the same. At the
  end of the game, the one with the most points wins the match...

  ![Filler](https://raw.githubusercontent.com/PhilippNox/42_filler/master/resources/img/filler.png)
</details>

According to the project conditions we have:
  1. A program to launch the game     - ./resources/filler_vm
  2. A couple of maps for a game      - ./resources/maps/
  3. Bots that we will fight against  - ./resources/player/

👉 Goal: Create a bot that will work with ./resources/filler_vm and defeat all default bots on all maps.

🌟 The reason why this project is on github. After achieving the goal. Laleta and I developed next things:
  1. Good looking visualization of the game. (Thanks to Laleta 🙏)
  2. Another bot that allows to play a human to this game.


## Getting Started

Let's run the game in your local machine. Here we will launch the game with visualization in mode "human vs bot".

### Prerequisites

This project was developed and launched on Mac OS X.
<details>
  <summary>Mac OS X</summary>

  ```
    ProductName:	Mac OS X
    ProductVersion:	10.15.1
    BuildVersion:	19B88

  ```
  To check this run in your terminal "sw_vers"
</details>
<details>
  <summary>With gcc version</summary>
  
  ```
    Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
    Apple clang version 11.0.0 (clang-1100.0.33.8)
    Target: x86_64-apple-darwin19.0.0
    Thread model: posix
    InstalledDir: /Library/Developer/CommandLineTools/usr/bin
  ```
  To check this run in your terminal "gcc -v"
</details>


### Installing and run

1. Clone this repository.
2. Open terminal and navigate to this directory (where this README is located).
3. Run next command in your terminal:
```
make
```
4. And than this command:
```
./run.sh
```


### Advanced run

Run the game with your bot.
```
./run.sh -b {path_to_your_bot}
Example: ./run.sh -b ./bot/build/squid.filler
```

Run the game with another map.
```
./run.sh -m {path_to_another_map}
Example: ./run.sh -m ./resources/maps/map01
```

How to run bot_vs_bot game.
```
cd visu
../resources/filler_vm -f ../resources/maps/map01 -p1 ../bot/build/squid.filler -p2 ../bot/build/squid.filler | ./filler_visu_vm
```
