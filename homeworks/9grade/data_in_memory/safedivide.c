#include <stdio.h>
#include <stdlib.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_error("Usage: safedivide <num1> <num2>");
        return 1;
    }

    char *endptr;
    long num1 = strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || num1 > INT_MAX || num1 < INT_MIN) {
        print_error("First argument is out of range for int");
        return 1;
    }

    long num2 = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0' || num2 > INT_MAX || num2 < INT_MIN) {
        print_error("Second argument is out of range for int");
        return 1;
    }

    SafeResult res = safedivide((int)num1, (int)num2);
    if (res.errorflag) {
        print_error("Overflow, underflow, or division by zero occurred");
        return 1;
    }

    printf("Result: %d\n", res.value);
    return 0;
}