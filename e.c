#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/*
This file should contain two functions: e() and e_terms() . The former function will approximate the value of e
using the Taylor series presented in §3 and track the number of computed terms by means of a static variable
local to the file.
*/

static int terms = 0;
//Structure Given By Kerry/Long -
double e(void) {
    double e = 1.0, term = 1.0, base = 1.0;
    for (int i = 1; absolute(term) > EPSILON; i++) {
        base *= i;
        term = 1 / base;
        e += term;
        terms++;
    }

    return e;
}

int e_terms(void) {
    return terms;
}
