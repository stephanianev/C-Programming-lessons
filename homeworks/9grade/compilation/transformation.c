#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "transformation.h"

transformation string_to_long(const char *input) {
    transformation result;
    char *end;

    result.result = strtol(input, &end, 10);

    if (*end != '\0') {
        result.result = 0;
        snprintf(result.error, sizeof(result.error), "Invalid input string");
    } else {
        result.error[0] = '\0';
    }

    return result;
}
