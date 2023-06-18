#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

static int factors = 0;
/*
John Wallis (1616–1703) was an English clergyman and mathematician who is given partial credit for the
development of infinitesimal calculus. He gave us a series that is purely multiplicative (instead of terms, we
have factors)
*/
double pi_wallis(void) {
    double pi = 1.0, term = 10.0;
    for (double i = 1; (absolute(term) - 1) > EPSILON; i++) {
        term = (4 * i * i) / ((4 * i * i) - 1);
        pi *= term;
        factors++;
    }
    return 2 * pi;
}

int pi_wallis_factors(void) {
    return factors;
}
