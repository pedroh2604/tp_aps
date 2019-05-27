#include <stdio.h>
#include "types.h"

int isEOL(char c) {
    return (c == '\n' || c == '\r' || c == '\0') ? 1 : 0;
}

void intToString(unsigned int number, char *output) {
    sprintf(output, "%u", number);
}
