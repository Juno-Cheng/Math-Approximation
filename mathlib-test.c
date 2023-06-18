#include "mathlib.h"

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define OPTIONS "aebmrvnswh"

int main(int argc, char **argv) {
    //double M_PI = 3.141592653589793;
    //double M_E = 2.718281828459045;
    int e_appox = 0, bailey = 0, madhava = 0, euler = 0, viete = 0, newton = 0, wallis = 0,
        stats = 0, help = 0;

    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {

        switch (opt) {

        case 'a': //All Tests
            e_appox = 1;
            bailey = 1;
            madhava = 1;
            euler = 1;
            viete = 1;
            newton = 1;
            wallis = 1;
            break;

        case 'e': //e approximation test
            e_appox = 1;
            break;

        case 'b': //bailey test
            bailey = 1;
            break;

        case 'm': //madhava test...
            madhava = 1;
            break;

        case 'r': //PI
            euler = 1;
            break;

        case 'v': viete = 1; break;

        case 'n': newton = 1; break;

        case 'w': wallis = 1; break;

        case 's': stats = 1; break;

        case 'h': help = 1; break;
        default: help = 1; break;
        }
    }

    //Help Condition
    if (help == 1) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\nUSAGE\n   "
               "./mathlib-test-x86 -[aebmrvnsh]\n\nOPTIONS\n  -a   Runs all tests.\n  -e   Runs e "
               "test.\n  -b   Runs BBP pi test.\n  -m   Runs Madhava pi test.\n  -r   Runs Euler "
               "pi test.\n  -v   Runs Viete pi test.\n  -w   Runs Wallis pi test.\n  -n   Runs "
               "Newton square root tests.\n  -s   Print verbose statistics.\n  -h   Display "
               "program synopsis and usage.\n");
        return 0;
    }

    //Print to stderr if option is not recognized
    if (help == 2) {
        fprintf(stderr,
            "SYNOPSIS\n   A test harness for the small numerical library.\n\nUSAGE\n   "
            "./mathlib-test-x86 -[aebmrvnsh]\n\nOPTIONS\n  -a   Runs all tests.\n  -e   Runs e "
            "test.\n  -b   Runs BBP pi test.\n  -m   Runs Madhava pi test.\n  -r   Runs Euler "
            "pi test.\n  -v   Runs Viete pi test.\n  -w   Runs Wallis pi test.\n  -n   Runs "
            "Newton square root tests.\n  -s   Print verbose statistics.\n  -h   Display "
            "program synopsis and usage.\n");
        return 0;
    }

    int check = 0;
    //E Test
    if (e_appox == 1) {
        check = 1;
        double x = e();
        printf("e() = %16.15lf, M_E = %16.15lf, diff = %16.15lf\n", x, M_E, M_E - x);

        //Check if stats is on
        if (stats == 1) {
            printf("e() terms = %d\n", e_terms());
        }
    }

    //Bailey Test
    if (bailey == 1) {
        check = 1;
        double x = pi_bbp();
        printf("pi_bbp() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", x, M_PI, M_PI - x);

        //Check if stats is on
        if (stats == 1) {
            printf("pi_bbp() terms = %d\n", pi_bbp_terms());
        }
    }

    //Madhava Test
    if (madhava == 1) {
        check = 1;
        double x = pi_madhava();
        printf("pi_madhava() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", x, M_PI, M_PI - x);

        //Check if stats is on
        if (stats == 1) {
            printf("pi_madhava() terms = %d\n", pi_madhava_terms());
        }
    }
    //Euler Pi Test
    if (euler == 1) {
        check = 1;
        double x = pi_euler();
        printf("pi_euler() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", x, M_PI, M_PI - x);

        //Check if stats is on
        if (stats == 1) {
            printf("pi_euler() terms = %d\n", pi_euler_terms());
        }
    }

    //Viete Test
    if (viete == 1) {
        check = 1;
        double x = pi_viete();
        printf("pi_viete() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", x, M_PI, (M_PI - x));

        //Check if stats is on
        if (stats == 1) {
            printf("pi_viete() terms = %d\n", pi_viete_factors());
        }
    }

    //Wallis Test
    if (wallis == 1) {
        check = 1;
        double x = pi_wallis();
        printf("pi_wallis() = %16.15lf, M_PI = %16.15lf, diff = %16.15lf\n", x, M_PI, (M_PI - x));

        //Check if stats is on
        if (stats == 1) {
            printf("pi_wallis() terms = %d\n", pi_wallis_factors());
        }
    }

    //Newton Test
    if (newton == 1) {
        check = 1;
        double cur = 0;
        while (1) {
            double x = sqrt_newton(cur);
            printf("sqrt_newton(%.2lf) = %16.15lf, sqrt(%.2lf) = %16.15lf, diff = %16.15lf\n", cur,
                x, cur, sqrt(cur), sqrt(cur) - x);

            //Check if stats is on
            if (stats == 1) {
                printf("sqrt_newton() terms = %d\n", sqrt_newton_iters());
            }
            cur += .1;

            //Check if cur is greater than 10
            if (cur > 9.9) {
                break;
            }
        }
    }

    //Check if no options were selected
    if (check == 0) {
        printf("SYNOPSIS\n   A test harness for the small numerical library.\n\nUSAGE\n   "
               "./mathlib-test-x86 -[aebmrvnsh]\n\nOPTIONS\n  -a   Runs all tests.\n  -e   Runs e "
               "test.\n  -b   Runs BBP pi test.\n  -m   Runs Madhava pi test.\n  -r   Runs Euler "
               "pi test.\n  -v   Runs Viete pi test.\n  -w   Runs Wallis pi test.\n  -n   Runs "
               "Newton square root tests.\n  -s   Print verbose statistics.\n  -h   Display "
               "program synopsis and usage.\n");
        return 0;
    }

    return 0;
}
