#include <stdio.h>
#include <string.h>

size_t strlength(const char *str) {
    return strlen(str);
}

void strconcat(char *dest, const char *src) {
    strcat(dest, src);
}

int strcompare(const char *str1, const char *str2) {
    return strcmp(str1, str2);
}

void main() {
    printf("Приложението съдържа следните функции:\n");
    printf("1. strlength - намира дължината на символен низ.\n");
    printf("2. strconcat - обединява два символни низа.\n");
    printf("3. strcompare - сравнява два символни низа.\n");
}
