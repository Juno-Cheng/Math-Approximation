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
The Madhava series (Mādhava of Sangamagrāma, c. 1340 – c. 1425) gives us this series
*/
double pi_madhava(void) {
    double pi = 0.0, term = 1.0, tmp = 0.0;
    for (double i = 0; absolute(term) > EPSILON; i++) {
        if (i == 0) {
            tmp = 1.0;
        } else {
            tmp *= -3;
        }
        term = ((1 / tmp) / (2 * i + 1));
        pi += term;
        terms++;
    }
    return sqrt_newton(12.0) * pi;
}

int pi_madhava_terms(void) {
    return terms;
}
