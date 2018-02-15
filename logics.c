#pragma once

#include <time.h>
#include <math.h>
#include <stdbool.h>

#include "screen.c"


double rand01() { return rand() / (double)RAND_MAX; }
int randr(int min, int max) { return rand01() * (max - min) + min; }

bool is_prime(int x) {
    if (x < 4) { return true; }
    for (int i = 2, to = x / 2; i <= to; i++) {
        if (x % i == 0) { return false; }
    }
    return true;
}
int nth_prime(int n) {
    for (int i = 2, count = 0; true; i++) {
        if (is_prime(i)) { count++; }
        if (count >= n) { return i; }
    }
}

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

void init_logics() {
    srand(time(0));
}