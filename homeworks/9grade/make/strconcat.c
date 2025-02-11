#include <stdio.h>
#include <string.h>
#include "mystrings.h"

#define MAX_LEN 50

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    if (strlength(argv[1]) > MAX_LEN || strlength(argv[2]) > MAX_LEN) {
        printf("Error: Each string must not exceed %d characters.\n", MAX_LEN);
        return 1;
    }

    char str1[MAX_LEN + 1];
    char str2[MAX_LEN + 1];

    strncpy(str1, argv[1], MAX_LEN);
    strncpy(str2, argv[2], MAX_LEN);

    str1[MAX_LEN] = '\0';
    str2[MAX_LEN] = '\0';

    strconcat(str1, str2);
    printf("%s\n", str1);
    return 0;
}