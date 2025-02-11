#include "maths.h"

long factorial(int n) {
    if (n < 0) return 0;

    long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
