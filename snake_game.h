/*                  /||\
 *                  ||||
 *                  ||||                       _____.-..-.
 *                  |||| /|\                .-~@@/ / q  p \
 *             /|\  |||| |||              .'@ _@/..\-.__.-/
 *             |||  |||| |||             /@.-~/|~~~`\|__|/
 *             |||  |||| |||             |'--<||     '~~'
 *             |||  |||| d||             |>--<\@\
 *             |||  |||||||/             \>---<\@`\.
 *             ||b._||||~~'               `\>---<`\@`\.
 *             \||||||||                    `\>----<`\@`\.
 *              `~~~||||               _      `\>-----<`\@`\.
 *                  ||||              (_)       `\>-----<`\.@`\.
 *                  ||||              (_)         `\>------<`\.@`\.
 *  ~~~~~~~~~~~~~~~~||||~~~~~~~~~~~~~~(__)~~~~~~~~~`\>-------<`\.@`\~~~~~~~~~~~~~
 *    \/..__..--  . |||| \/  .  ..____( _)@@@--..____\..--\@@@/~`\@@>-._   \/ .
 *  \/         \/ \/    \/     / - -\@@@@--@/- - \@@@/ - - \@/- -@@@@/- \.   --._
 *     .   \/    _..\/-...--.. |- - -\@@/ - -\@@@@/~~~~\@@@@/- - \@@/- - |   .\/
 *          .  \/              | - - -@@ - - -\@@/- - - \@@/- - - @@- - -|      .
 *  . \/             .   \/     ~-.__ - - - - -@@- - - - @@- - - - -__.-~  . \/
 *     __...--..__..__       .  \/   ~~~--..____- - - - -____..--~~~    \/_..--..
 *  \/  .   .    \/     \/    __..--... \/      ~~~~~~~~~     \/ . \/  .
 *
 * SNAKE GAME
 * CREATE BY @ LEONARDO ZAMBONI NUNES 11 / 08 / 2020
 *
 * Assignment required for functions containing *
 *
 * CMakeLists 3.17
 * find_package (Threads)
 * target_link_libraries (game ${CMAKE_THREAD_LIBS_INIT})
 */

// Required libraries
#include <stdlib.h>
#include <windows.h>
#include "conio.c"
#include <pthread.h>

// Required defines
#define N_THREAD 2
#define MAX 500

// Snake structures
/* Counter:
 * movement history to limit the size
 */
typedef struct movement_counter {
    int count_line[MAX];
    int count_column[MAX];
    int count_movements;
}Count;

/* Snake movement:
 * movement matrix and direction of the key pressed
 */
typedef struct snake_movement {
    int direction;
    int line;
    int column;
    char key;
    Count movement_count;
}Movement;

/* Snake:
 * speed and size snake
 */
typedef struct snake {
    int size;
    int speed;
    Movement snake_movement;
}Snake;
Snake snake;
// A global Snake variable for snake structures

// Window structures
/* Window resolution
 * define height and width of the window
 */
typedef struct window_resolution {
    int height;
    int width;
}Window;
Window window_var;
// A global Window variable for window size

// Apple structures
/* Random apple
 * aleatory position of apple spawn
 */
typedef struct random_apple {
    int rand_line;
    int rand_column;
}Apple;
Apple apple;
// A global Apple variable for apple positions

/* Function window_create*
 * creates the window with size of window_var.height* and window_var.width*
 */
void window_create();

/* Function apple_create*
 * responsible for generating the first apple
 */
void apple_create();

/* Function apple_create
 * responsible for checking the snake ate the apple
 */
void apple_destroy();

/* Function snake_moviment
 * responsible for moving the snake
 */
void snake_moviment();

/* Function snake_size
 * responsible for limiting the size of the snake
 */
void snake_size();

/* Function snake_create*
 * responsible for creating the snake with snake.speed* and snake.size*
 */
void snake_create();

/* Function start*
 * responsible for starting the snake game
 */
void start();
