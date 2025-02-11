#include <stdio.h>
#include <limits.h>

#define PRINT_TYPE_INFO(TYPE, FORMAT, U_FORMAT, MAX, MIN, UMAX) \
    printf("| %-12s | %-8s | %-6zu | %-22lld | %-22lld | %-8s | %-22llu |\n", \
           #TYPE, FORMAT, sizeof(TYPE), \
           (long long)(MAX), (long long)(MIN), \
           U_FORMAT, (unsigned long long)(UMAX));

void main() {
    printf("+--------------+----------+--------+------------------------+------------------------+----------+------------------------+\n");
    printf("| Type         | Format   | Bytes  | Signed Max             | Signed Min             | UFormat  | Unsigned Max           |\n");
    printf("+--------------+----------+--------+------------------------+------------------------+----------+------------------------+\n");

    PRINT_TYPE_INFO(char, "%d", "%u", CHAR_MAX, CHAR_MIN, UCHAR_MAX);
    PRINT_TYPE_INFO(short, "%hd", "%hu", SHRT_MAX, SHRT_MIN, USHRT_MAX);
    PRINT_TYPE_INFO(int, "%d", "%u", INT_MAX, INT_MIN, UINT_MAX);
    PRINT_TYPE_INFO(long, "%ld", "%lu", LONG_MAX, LONG_MIN, ULONG_MAX);
    PRINT_TYPE_INFO(long long, "%lld", "%llu", LLONG_MAX, LLONG_MIN, ULLONG_MAX);

    printf("+--------------+----------+--------+------------------------+------------------------+----------+------------------------+\n");
}
