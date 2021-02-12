#include "snake_game.h"

void window_create() {
    int line = 1;
    int column = 1;

    do {
        if (column == window_var.height) {
            gotoxy(line, column);
            printf("%c", 219);
        } else {
            gotoxy(line, column);
        }
        if (line == window_var.width) {
            printf("%c", 219);
            column++;
            line = 1;
        } else {
            line++;
        }
    } while (column != window_var.height + 1);
}

void apple_create() {
    srand(time(NULL));

    do {
        apple.rand_line = rand() % (window_var.width - 2);
        apple.rand_column = rand() % (window_var.height - 2);
    } while (apple.rand_line == 0 || apple.rand_column == 0);

    gotoxy(apple.rand_line, apple.rand_column);
    printf("%c", 254);
}

void apple_destroy() {
    if (snake.snake_movement.line == apple.rand_line && snake.snake_movement.column == apple.rand_column) {
        snake.size++;
        snake.speed -= 5;
        apple_create();
    }
}

void snake_moviment() {
    do {
        snake.snake_movement.key = (char) getch();
        switch (snake.snake_movement.key) {
            // W
            case 119: {
                snake.snake_movement.direction = 3;
                break;
            }
            // A
            case 97: {
                snake.snake_movement.direction = 1;
                break;
            }
            // S
            case 115: {
                snake.snake_movement.direction = 4;
                break;
            }
            // D
            case 100: {
                snake.snake_movement.direction = 2;
                break;
            }
        }
    } while (snake.snake_movement.key != 27);
}

void snake_size() {
    for (int i = 0; i <= snake.snake_movement.movement_count.count_movements; ++i) {
        gotoxy(snake.snake_movement.movement_count.count_line[i], snake.snake_movement.movement_count.count_column[i]);
        printf("%c", 0);

        window_create();

        gotoxy(apple.rand_line, apple.rand_column);
        printf("%c", 254);
        Sleep((snake.speed / 15));
    }
}

void snake_create() {
    snake.snake_movement.line = window_var.width / 2;
    snake.snake_movement.column = window_var.height / 2;
    do {
        if (snake.snake_movement.direction == 1) {
            snake_size();
            snake.snake_movement.movement_count.count_movements = 0;
            do {
                snake.snake_movement.line--;

                apple_destroy();

                snake.snake_movement.movement_count.count_movements++;
                snake.snake_movement.movement_count.count_line[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.line;
                snake.snake_movement.movement_count.count_column[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.column;

                gotoxy(snake.snake_movement.line, snake.snake_movement.column);
                printf("%c", 219);

                gotoxy(snake.snake_movement.line + snake.size, snake.snake_movement.column);
                printf("%c", 0);

                Sleep(snake.speed);
            } while (snake.snake_movement.direction == 1);
        }

        if (snake.snake_movement.direction == 2) {
            snake_size();
            snake.snake_movement.movement_count.count_movements = 0;
            do {
                snake.snake_movement.line++;

                apple_destroy();

                snake.snake_movement.movement_count.count_movements++;
                snake.snake_movement.movement_count.count_line[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.line;
                snake.snake_movement.movement_count.count_column[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.column;

                gotoxy(snake.snake_movement.line, snake.snake_movement.column);
                printf("%c", 219);

                gotoxy(snake.snake_movement.line - snake.size, snake.snake_movement.column);
                printf("%c", 0);

                Sleep(snake.speed);
            } while (snake.snake_movement.direction == 2);
        }

        if (snake.snake_movement.direction == 3) {
            snake_size();
            snake.snake_movement.movement_count.count_movements = 0;
            do {
                snake.snake_movement.column--;

                apple_destroy();

                snake.snake_movement.movement_count.count_movements++;
                snake.snake_movement.movement_count.count_line[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.line;
                snake.snake_movement.movement_count.count_column[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.column;

                gotoxy(snake.snake_movement.line, snake.snake_movement.column);
                printf("%c", 219);

                gotoxy(snake.snake_movement.line, snake.snake_movement.column + snake.size);
                printf("%c", 0);

                Sleep(snake.speed);
            } while (snake.snake_movement.direction == 3);
        }

        if (snake.snake_movement.direction == 4) {
            snake_size();
            snake.snake_movement.movement_count.count_movements = 0;
            do {
                snake.snake_movement.column++;

                apple_destroy();

                snake.snake_movement.movement_count.count_movements++;
                snake.snake_movement.movement_count.count_line[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.line;
                snake.snake_movement.movement_count.count_column[snake.snake_movement.movement_count.count_movements] = snake.snake_movement.column;

                gotoxy(snake.snake_movement.line, snake.snake_movement.column);
                printf("%c", 219);

                gotoxy(snake.snake_movement.line, snake.snake_movement.column - snake.size);
                printf("%c", 0);

                Sleep(snake.speed);
            } while (snake.snake_movement.direction == 4);
        }
    } while (snake.snake_movement.key != 27);
}

void *function(void *arg) {
    int *pvalor;

    pvalor = arg;

    if (*pvalor == 1) {
        snake_moviment();
    }
    if (*pvalor == 2) {
        snake_create();
    }

    return NULL;
}

void start() {
    pthread_t threads[N_THREAD];
    int i, arg[N_THREAD];

    for (i = 0; i < N_THREAD; ++i) {
        arg[i] = i + 1;
        pthread_create(&threads[i], NULL, function, (void *)&arg[i]);
    }

    for (i = 0; i < N_THREAD; ++i)
        pthread_join(threads[i], NULL);

    printf("\n");
}