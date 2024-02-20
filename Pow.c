#include <stdio.h>
#include <limits.h> // for INT_MIN definition

double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    
    if (n == INT_MIN) {
        return myPow(x, n + 1) / x;
    }

    if (n < 0) {
        x = 1.0 / x;
        n = -n;
    }

    double halfPower = myPow(x, n / 2);

    if (n % 2 == 0) {
        return halfPower * halfPower;
    } else {
        return halfPower * halfPower * x;
    }
}
