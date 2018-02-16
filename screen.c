#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int W = -1, H = -1;
int ** screen;
int ** screen_copy;

void screen_make_copy() {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            screen_copy[x][y] = screen[x][y];
        }
    }
}
void screen_from_copy() {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            screen[x][y] = screen_copy[x][y];
        }
    }
}

void init_screen() {
    screen = (int**)malloc(W * sizeof(int*));
    screen_copy = (int**)malloc(W * sizeof(int*));
    for (int y = 0; y < W; y++) {
        screen[y] = (int*)malloc(H * sizeof(int));
        screen_copy[y] = (int*)malloc(H * sizeof(int));
    }
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            screen[x][y] = 0;
        }
    }

    printf("Initialized %dx%d screen grid\n", W, H);
}

void printscreen() {
    clearscreen();
    for (int y = 0; y < H; y++) {
        putc('\n', stdout);
        for (int x = 0; x < W; x++) {
            int val = screen[x][y];
            if (val != 0) { 
                printf(" %4d ", val);
            } else {
                printf(" %s ", "    ");
            }
        }
        putc('\n', stdout);
        putc('\n', stdout);
        putc('\r', stdout);
    }
}
