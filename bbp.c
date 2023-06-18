#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int terms = 0;

double mult(int x);

/*
The Bailey-Borwein-Plouffe formula (BBP formula) is a formula for π. It was discovered in 1995 by Simon
Plouffe and is named after the authors of the article in which it was published, David H. Bailey, Peter
Borwein, and Plouffe. The formula that they discovered is remarkably simple
*/
double pi_bbp() {
    double pi = 0.0, term = 1.0, value = 1.0;
    for (int i = 0; absolute(term) > EPSILON; i++) {
        if (i == 0) {
            value = 1;
        } else {
            value = value * 16.0;
        }

        term = (1 / value) * mult(i);
        pi += term;
        terms++;
    }
    return pi;
}

int pi_bbp_terms() {
    return terms;
}

double mult(int x) {
    return (4.0 / (8.0 * x + 1.0)) - (2.0 / (8.0 * x + 4.0)) - (1.0 / (8.0 * x + 5.0))
           - (1.0 / (8.0 * x + 6.0));
}
