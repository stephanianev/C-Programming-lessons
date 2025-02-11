#include <stdio.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Invalid number of arguments.\n");
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    size_t length = strlength(argv[1]);
    printf("%zu\n", length);
    return 0;
}