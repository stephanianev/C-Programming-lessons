#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "quadraticroots.h"

long double convertToDouble(char str[]) {
    char *endptr;
    errno = 0;
    long double num = strtod(str, &endptr);

    if (errno != 0 || *endptr != '\0') {
        perror("Error ocurred while converting the values!");
        exit(EXIT_FAILURE);
    }

    return num;
}

void main(int argc, char ** argv) {
    int a1, b1, c1;
    float a2, b2, c2;
    char a3, b3, c3;

    printf("Вкарай коефициентите на уравненията подред(a -> b -> c) и в ред- int -> float -> double: ");
    a1 = convertToDouble(argv[1]);
    b1 = convertToDouble(argv[2]);
    c1 = convertToDouble(argv[3]);
    QuadraticRootsResult result1 = findroots(a1, b1, c1);
    if (result1.norealroots) {
        printf("Уравнението с int няма реални корени.\n");
    } else {
        printf("Корените на уравнението с int са: x1 = %.2Lf, x2 = %.2Lf\n", result1.x1, result1.x2);
    }

    a2 = convertToDouble(argv[4]);
    b2 = convertToDouble(argv[5]);
    c2 = convertToDouble(argv[6]); 
    QuadraticRootsResult result2 = findroots(a2, b2, c2);
    if (result2.norealroots) {
        printf("Уравнението с float няма реални корени.\n");
    } else {
        printf("Корените на уравнението с float са: x1 = %.2Lf, x2 = %.2Lf\n", result2.x1, result2.x2);
    }

    a3 = convertToDouble(argv[7]);
    b3 = convertToDouble(argv[8]);
    c3 = convertToDouble(argv[9]);
    QuadraticRootsResult result3 = findroots(a3, b3, c3);
    if (result3.norealroots) {
        printf("Уравнението с double няма реални корени.\n");
    } else {
        printf("Корените на уравнението с double са: x1 = %.2Lf, x2 = %.2Lf\n", result3.x1, result3.x2);
    }
}
