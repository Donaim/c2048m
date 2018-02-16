#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define W 5
#define H 5
int screen[W][H];
int screen_copy[W][H];

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
