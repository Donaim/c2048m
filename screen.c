#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "logics.c"

#define W 10
#define H 10
int screen[W][H];

void init_screen() {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            // if ((x == 0 || x == W - 1) || (y == 0 || y == H - 1)) {
            screen[x][y] = 0;
        }
    }
}

void printscreen() {
    clearscreen();
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            printf(" %5d ", screen[x][y]);
        }
        putc('\n', stdout);
        putc('\r', stdout);
    }
}
