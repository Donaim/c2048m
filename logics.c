#pragma once

#include <time.h>
#include <math.h>
#include <stdbool.h>


double rand01() { return rand() / (double)RAND_MAX; }

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

/* 
    bigger RAND_RATE generates bigger primes and vice-versa
    dont set it bigger than 1.649
*/

double powi(int x, int y) {
    int re = 1;
    while (y-- > 0) {
        re *= x;
    }
    return (double)re;
}

/// 1 - (0.1) , 1 - (0.1 / 2)
#define RAND_RATE 1
int rand_cell() {
    double r = rand01();
    for (int i = 0; true; i++) {
        if (RAND_RATE / powi(2, i) < r) { return nth_prime(i); }
    }
}


void init_logics() {
    srand(time(0));
}