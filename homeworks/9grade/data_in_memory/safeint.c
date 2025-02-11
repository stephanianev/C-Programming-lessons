#include <stdio.h>
#include "safeint.h"
#include <limits.h>

struct SafeResult safeadd(int a, int b) {
    struct SafeResult result = {0, 0};
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
        result.errorflag = 1;
    } else {
        result.value = a + b;
    }
    return result;
}

struct SafeResult safesubtract(int a, int b) {
    struct SafeResult result = {0, 0};
    if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b)) {
        result.errorflag = 1;
    } else {
        result.value = a - b;
    }
    return result;
}

struct SafeResult safemultiply(int a, int b) {
    struct SafeResult result = {0, 0};
    if (a != 0 && ((b > 0 && (a > INT_MAX / b || a < INT_MIN / b)) ||
                   (b < 0 && (a > INT_MIN / b || a < INT_MAX / b)))) {
        result.errorflag = 1;
    } else {
        result.value = a * b;
    }
    return result;
}

struct SafeResult safedivide(int a, int b) {
    struct SafeResult result = {0, 0};
    if (b == 0) {
        result.errorflag = 1;
    } else if (a == INT_MIN && b == -1) {
        result.errorflag = 1;
    } else {
        result.value = a / b;
    }
    return result;
}

struct SafeResult safestrtoint(const char *str) {
    struct SafeResult result = {0, 0};
    int value = 0, sign = 1;
    int i = 0;

    while (str[i] == ' ') {
        i++;
    }

    if (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            sign = -1;
        }
        i++;
    }

    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        struct SafeResult multiply_result = safemultiply(value, 10);
        if (multiply_result.errorflag) {
            result.errorflag = 1;
            return result;
        }

        struct SafeResult add_result = safeadd(multiply_result.value, (str[i] - '0') * sign);
        if (add_result.errorflag) {
            result.errorflag = 1;
            return result;
        }

        value = add_result.value;
    }

    if (i == 0 || (i == 1 && (str[0] == '-' || str[0] == '+'))) {
        result.errorflag = 1;
        return result;
    }

    result.value = value;
    return result;
}
