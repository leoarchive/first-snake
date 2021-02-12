#include "snake_game.c"

void game_credits() {
    char credits[27] = "Leonado Zamboni the creator";
    for (int i = 0; i <= 27; ++i) {
        if (i == 27)
            printf("\n");
        printf("%c", credits[i]);
        Sleep(50);
    }
    system("pause");
}

int menu() {
    char snake[1500] =
           "                  /||\\\n"
           "                  ||||\n"
           "                  ||||                       _____.-..-.\n"
           "                  |||| /|\\                .-~@@/ / q  p \\\n"
           "             /|\\  |||| |||              .'@ _@/..\\-.__.-/\n"
           "             |||  |||| |||             /@.-~/|~~~`\\|__|/\n"
           "             |||  |||| |||             |'--<||     '~~'\n"
           "             |||  |||| d||             |>--<\\@\\\n"
           "             |||  |||||||/             \\>---<\\@`\\.\n"
           "             ||b._||||~~'               `\\>---<`\\@`\\.\n"
           "             \\||||||||                    `\\>----<`\\@`\\.\n"
           "              `~~~||||               _      `\\>-----<`\\@`\\.\n"
           "                  ||||              (_)       `\\>-----<`\\.@`\\.\n"
           "                  ||||              (_)         `\\>------<`\\.@`\\.\n"
           "  ~~~~~~~~~~~~~~~~||||~~~~~~~~~~~~~~(__)~~~~~~~~~`\\>-------<`\\.@`\\~~~~~~~~~~~~~\n"
           "    \\/..__..--  . |||| \\/  .  ..____( _)@@@--..____\\..--\\@@@/~`\\@@>-._   \\/ .\n"
           "  \\/         \\/ \\/    \\/     / - -\\@@@@--@/- - \\@@@/ - - \\@/- -@@@@/- \\.   --._\n"
           "     .   \\/    _..\\/-...--.. |- - -\\@@/ - -\\@@@@/~~~~\\@@@@/- - \\@@/- - |   .\\/\n"
           "          .  \\/              | - - -@@ - - -\\@@/- - - \\@@/- - - @@- - -|      .\n"
           "  . \\/             .   \\/     ~-.__ - - - - -@@- - - - @@- - - - -__.-~  . \\/\n"
           "     __...--..__..__       .  \\/   ~~~--..____- - - - -____..--~~~    \\/_..--..\n"
           "  \\/  .   .    \\/     \\/    __..--... \\/      ~~~~~~~~~     \\/ . \\/  .\n";
    for (int i = 0; i <= 1476; ++i) {
        printf("%c", snake[i]);
        Sleep(5);
    }
    int menu;
    printf("1 - Start Game\n");
    printf("2 - Game credits\n");
    printf("0 - Exit\n");
    scanf("%d", &menu);
    switch (menu) {
        case 1:
            return 1;
        case 2:
            system("cls");
            game_credits();
            break;
        case 3:
            exit(0);
        default:
            printf("Nao entendi irmao\n");
            break;
    }
}

int main() {
    window_var.height = 20;
    window_var.width = 50;
    snake.speed = 300;
    snake.size = 1;

    menu();
    system("cls");

    window_create();
    apple_create();
    start();

    system("pause");
}