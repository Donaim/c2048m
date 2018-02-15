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
    for (int i = 1, count = 0; true; i++) {
        if (is_prime(i)) { count++; }
        if (count >= n) { return i; }
    }
}

#define RAND_RATE 2.5 /* RAND_RATE close to zero generates big primes and vice-versa */
int rand_cell() {
    double r = rand01();
    for (int i = 1; true; i++) {
        if (1.0 / pow((double)i, RAND_RATE) < r) { return nth_prime(i); }
    }
}


void init_logics() {
    srand(time(0));
}