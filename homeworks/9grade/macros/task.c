#include <stdio.h>

#define SWAP(a, b, TYPE) \
    TYPE temp = a; \
    a = b; \
    b = temp;

#define SORT(ARRAY, SIZE, TYPE, COMPARE) \
    for (int i = 0; i < SIZE - 1; i++) { \
        for (int j = i + 1; j < SIZE; j++) { \
            if (ARRAY[i] COMPARE ARRAY[j]) { \
                SWAP(ARRAY[i], ARRAY[j], TYPE); \
            } \
        } \
    }

void main() {
    char sort;
    int array[] = {5, 2, 9, 1, 6};
    int size = 5;

    printf("Enter how to sort the array(> or <): ");
    scanf("%c", &sort);

    if (sort == '>') {
        SORT(array, size, int, >);
    } else{
        SORT(array, size, int, <);
    }
    printf("Сортиран масив:\n");

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
}
