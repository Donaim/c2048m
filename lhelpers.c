#pragma once
#include <stdlib.h>
#include <stdbool.h>

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
