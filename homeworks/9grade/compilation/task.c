#include <stdio.h>
#include "maths.h"

void main() {
    int number;
    printf("Enter the number: ");
    scanf("%d", &number);
    long result = factorial(number);

    printf("Factorial of %d is %ld\n", number, result);
}
