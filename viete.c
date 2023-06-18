#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int factor = 0;

double pi_viete() {
    double term = 1.0, numerator = 0.0;
    for (double i = 1; absolute((numerator / 2) - 1) > EPSILON; i++) {
        numerator = sqrt_newton(2 + numerator);
        term = (numerator / 2) * term;
        factor++;
    }
    return 2 / term;
}

int pi_viete_factors() {
    return factor;
}
