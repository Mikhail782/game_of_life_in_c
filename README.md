# Game of Life in C Language

## This is a learning project, so it's no longer supported!

***== This is a program developed in C – a visualization of The Game of Life. To display the graphics, used only ASCII characters (with output to the terminal). This is an Interactive version, so you can adjust the speed of the "game". ==***

> Playing field is a rectangle of 80 by 25 cells – as a matrix of the state of the "game". 
> It is assumed that the field is "closed to itself", for example, in the lower right square, the neighbor on the right is the lower left square, and the neighbor on the bottom is the upper right.
> There are 5 files prepared with initial states for quick launch and initialized through input redirection.

## Important notes:

* It is recommend to use basic terminal to proper use
* To compile project proceed to `src` folder and enter following command:
  - `gcc -Wall -Werror -Wextra -lncurses game_of_life.c -o game_of_life.c`
  - `./game_of_life`
  
* Interactions:
  > To adjust the GAME SPEED: 
  > PRESS `+` to increase speed; 
  > PRESS `-` to slow down
  > 
  > PRESS `Ctrl + Z` to EXIT the program
  > 
  > Enter a number from <1 to 5> to see different objects: 
  > 1 - STILL LIFES
  > 2 - OSCILLATORS
  > 3 - SPACESHIP & GLIDER
  > 4 - GLIDER GUN
  > 5 - TWO STARS
  
* Source code tested by the static analyzer `cppcheck`, as well as the style linter `cpplint`. 
  
* Instructions on how to run these tests on your computer are in the `materials` folder. 

> Game is developed following the principles of structured programming of E. Dijkstra.

## Known issues:
  - There's no way to correctly exit the programm, so use `Ctrl + C` to kill the process
  - When speed is too high, the image frezes
