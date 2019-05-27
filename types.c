#include <stdlib.h>
#include <stdio.h>
#include "types.h"

int isEOL(char c) {
    return (c == '\n' || c == '\r' || c == '\0') ? 1 : 0;
}

void intToString(unsigned int number, char *output) {
    sprintf(output, "%u", number);
}

// Implementação alternativa
char *intToString2(unsigned int number) {
    char *temp = NULL;
    char *output = NULL;
    int counter = 0;
    do {
        temp = (char *) realloc(temp, sizeof(char) + (counter * sizeof(char)));
        *(temp + counter) = (char) (number % 10) + 48;
        counter++;
    } while (number /= 10);

    int index = 0;
    for (int i = (counter - 1); i >= 0; i--) {
        output = (char *) realloc(output, sizeof(char) + (index * sizeof(char)));
        *(output + index) = temp[i];
        index++;
    }
    output = realloc(output, sizeof(char) + (index * sizeof(char)));
    *(output + index) = '\0';

    return output;
}