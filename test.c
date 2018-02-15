#pragma once

#include "screen.c"
#include "logics.c"

void randomize_table() {
    for (int x = 0; x < W; x++) {
        for (int y = 0; y < H; y++) {
            // if ((x == 0 || x == W - 1) || (y == 0 || y == H - 1)) {
            screen[x][y] = rand_cell();
        }
    }
}
