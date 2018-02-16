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
bool can_shift(int from, int to) {
    if (to == 0) { return true; }
    else if (from == to) { return true; }
    else { return false; }
}
void shift(int xd, int yd) {

    int xfrom, xto, xinc, yfrom, yto, yinc;
    if (xd < 0) {
        xfrom = 0;
        xto = W;
        xinc = 1;
    } else {
        xfrom = W - 1;
        xto = -1;
        xinc = -1;
    }
    if (yd < 0) {
        yfrom = 0;
        yto = H;
        yinc = 1;
    } else {
        yfrom = H - 1;
        yto = -1;
        yinc = -1;
    }

    for (int x = xfrom; x != xto; x += xinc) {
        for (int y = yfrom; y != yto; y += yinc) {
            int xn = x + xd;
            int yn = y + yd;
            if ((xn < 0 || xn >= W) || (yn < 0 || yn >= H)) { continue; }
            if (can_shift(screen[x][y], screen[xn][yn])) {
                screen[xn][yn] += screen[x][y];
                screen[x][y] = 0;
            }
        }
    }
}

void init_logics() {
    srand(time(0));
}