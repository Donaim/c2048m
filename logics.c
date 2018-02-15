#pragma once

#include <time.h>
#include <math.h>
#include <stdbool.h>

#include "screen.c"
#include "lhelpers.c"

#define RAND_RATE 1.0 /* */
#define RAND_DEG 1.8 /* */
int rand_cell() {
    double r = rand01();
    for (double i = 0, div = 1; i < 100; i++, div *= RAND_DEG) {
        if (RAND_RATE / div < r) { return nth_prime((int)i); }
    }
}


int count_empty() {
    int re = 0;
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            if (screen[x][y] == 0) { re++; }
        }
    }   
    return re;
}
void spawn_at_free(int free_index, int value) {
    int ind = 0;
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            if (screen[x][y] == 0) { ind++; }
            if (ind == free_index) { screen[x][y] = value; return; }
        }
    }
}
void spawn_cell() {
    int empty = count_empty();
    if (empty <= 0) { return; } // no free space

    int r = randr(1, empty + 1);
    int cell = rand_cell();
    spawn_at_free(r, cell);
}
void shift(int xd, int yd) {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            int xn = x + xd;
            int yn = y + yd;
            if ((xn < 0 || xn >= W) || (yn < 0 || yn >= H)) { continue; }
            
            screen[xn][yn] += screen[x][y];
            screen[x][y] = 0;
        }
    }
}

void init_logics() {
    srand(time(0));
}