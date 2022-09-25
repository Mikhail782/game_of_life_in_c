#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

#define WIDTH 80
#define HEIGHT 25

void init_board(int board[][HEIGHT]);
void read_file(int board[][HEIGHT]);
void print(int board[][HEIGHT]);
int adjacment_to(int board[][HEIGHT], int i, int j);
int xadd(int i, int a);
int yadd(int i, int a);
void play(int board[][HEIGHT]);
void button_settings();

int main(void) {
char input_buttons;
int tmp;
int board[WIDTH][HEIGHT];

printf("\n------WELCOME TO THE GAME OF LIFE------\n\n");
printf("To adjust the GAME SPEED: \nPRESS + to increase speed; \nPRESS - to slow down\n\n");
printf("PRESS Control+Z to EXIT the program\n\n");
init_board(board);
read_file(board);
button_settings();
while(1) {
    clear();
    print(board);
    play(board);
    usleep(400000 + tmp);
    input_buttons = getch();
    switch (input_buttons) {
        case '-':
            tmp = 10000;
            break;
        case '+':
            tmp -= 10000;
            break;
    }
}
endwin();
}

void init_board(int board[][HEIGHT]) {
for (int i = 0; i < WIDTH; i++) {
    for  (int j = 0; j < HEIGHT; j++) {
            board[i][j] = 0;
    }
}
}

void button_settings() {
initscr();
noecho();
nodelay(stdscr, TRUE);
}

void read_file(int board[][HEIGHT]) {
int KeyEnter;
FILE*f;
printf("Enter a number from <1 to 5> to see different objects: \n");
printf("1 - STILL LIFES\n");
printf("2 - OSCILLATORS\n");
printf("3 - SPACESHIP & GLIDER\n");
printf("4 - GLIDER GUN\n");
printf("5 - TWO STARS\n");
printf("------Waiting for  input------\n");
scanf("%d", &KeyEnter);

switch (KeyEnter) {
    case 1:
        f = fopen("1.txt", "r");
        break;
    case 2:
        f = fopen("2.txt", "r");
        break;
    case 3:
        f = fopen("3.txt", "r");
        break;
    case 4:
        f = fopen("4.txt", "r");
        break;
    case 5:
        f = fopen("5.txt", "r");
        break;
}
for  (int j = 0; j < HEIGHT; j++) {
    for  (int i = 0; i < WIDTH; i++) {
        fscanf(f, "%d ", &board[i][j]);
    }
}
fclose(f);
}

void print(int board[][HEIGHT]) {
for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
        if (board[i][j] == 0)
            printw("%c", ' ');
        if (board[i][j] == 1)
            printw("%c", 'o');
    }
    printw("\n");
}
refresh();
}

int adjacment_to(int board[][HEIGHT], int i, int j) {
int count = 0;

for (int k=-1; k <= 1; k++) {
    for (int l=-1; l <= 1; l++) {
        if (k || l)
            if (board[xadd(i, k)][yadd(j, l)])
                count++;
    }
}
return count;
}

int xadd(int i, int a) {
i += a;
while (i < 0) i += WIDTH;
while (i >= WIDTH) i -= WIDTH;
return i;
}

int yadd(int i, int a) {
i += a;
while (i < 0) i += HEIGHT;
while (i >= HEIGHT) i -= HEIGHT;
return i;
}

void play(int board[][HEIGHT]) {
int a;
int newboard[WIDTH][HEIGHT];

for (int j = 0; j < HEIGHT; j++) {
for (int i = 0; i < WIDTH; i++) {
    a = adjacment_to(board, i, j);
    if (a == 2) {
        newboard[i][j] = board[i][j];
    }
    if (a == 3) {
        newboard[i][j] = 1;
        }
        if (a < 2) {
            newboard[i][j] = 0;
        }
        if (a > 3) {
            newboard[i][j] = 0;
        }
    }
}

for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
        board[i][j] = newboard[i][j];
    }
}
}
