#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W 10
#define H 10
char screen[W][H];

void initframe() {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            if ((x == 0 || x == W - 1) || (y == 0 || y == H - 1)) {
                screen[x][y] = 'X';
            }
            else {
                screen[x][y] = ' ';
            }
        }
    }
}

void printscreen() {
    clearscreen();
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            putc(screen[x][y], stdout);
        }
        putc('\n', stdout);
        putc('\r', stdout);
    }
}
