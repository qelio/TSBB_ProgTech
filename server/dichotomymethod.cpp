#include "dichotomymethod.h"

double dichotomyFunc(double x, double a, double b, double c) {
    return (a * x * x + b * x + c);
}

double dichotomyFind(double left, double right, int count_iters, double a, double b, double c) {
    double x, fl, fr, f;
    int iter = 0;
    do {
        x = (left + right) / 2;
        f = dichotomyFunc(x, a, b, c);
        if (dichotomyFunc(left, a, b, c) < 0) {
            if (f > 0) {
                right = x;
            }
            else {
                left = x;
            }
        }
        else
        {
            if (f < 0) {
                right = x;
            }
            else {
                left = x;
            }
        }
        iter += 1;
    } while (iter < count_iters);
    return x;
}
