#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W 5
#define H 5
int screen[W][H];

void init_screen() {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            screen[x][y] = 0;
        }
    }
}

void printscreen() {
    clearscreen();
    for (int y = 0; y < H; y++) {
        putc('\n', stdout);
        for (int x = 0; x < W; x++) {
            printf(" %4d ", screen[x][y]);
        }
        putc('\n', stdout);
        putc('\n', stdout);
        putc('\r', stdout);
    }
}
