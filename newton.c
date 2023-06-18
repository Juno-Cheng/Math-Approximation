#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int terms = 0;
void sqrt_newton_reset(void);

//Newton's Method for Square Root
/*
def sqrt_newton(x):
    next_y = 1.0
    # initial guess for sqrt(x)
    y = 0.0
    # force while condition to be true initially
    while abs(next_y - y) > epsilon:
        y = next_y
        next_y = 0.5 * (y + x / y)
    return next_y
*/
double sqrt_newton(double x) {
    double next_y = 1.0, y = 0.0;
    while (absolute(next_y - y) > EPSILON) {
        y = next_y;
        next_y = 0.5 * (y + x / y);
        terms++;
    }
    return next_y;
}

int sqrt_newton_iters() {
    int x = terms;
    sqrt_newton_reset();
    return x;
}

void sqrt_newton_reset() {
    terms = 0;
}
