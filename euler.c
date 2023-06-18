#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int terms = 0;

/*
Euler’s solution to something called the “Basel problem” gave us this series
*/
double pi_euler(void) {
    double pi = 0.0, term = 1.0;
    for (double i = 1; absolute(term) > EPSILON; i++) {
        double xx = (i * i);
        term = 1 / (xx);
        pi += term;
        terms++;
    }
    pi = sqrt_newton(6 * pi);
    return pi;
}

int pi_euler_terms(void) {
    return terms;
}
