#include <stdlib.h>
#include <stdio.h>
#include "types.h"

int isEOL(char c) {
    return (c == '\n' || c == '\r' || c == '\0') ? 1 : 0;
}

// Implementação simplificada - não utilizada, pois a função sprintf não foi abordada em sala de aula
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

        if (temp == NULL) {
            printf("\nERRO: Memória insuficiente");
            exit(1);
        }

        *(temp + counter) = (char) (number % 10) + 48;
        counter++;
    } while (number /= 10);

    int index = 0;
    for (int i = (counter - 1); i >= 0; i--) {
        output = (char *) realloc(output, sizeof(char) + (index * sizeof(char)));

        if (output == NULL) {
            printf("\nERRO: Memória insuficiente");
            exit(1);
        }

        *(output + index) = temp[i];
        index++;
    }

    free(temp);

    output = realloc(output, sizeof(char) + (index * sizeof(char)));

    if (output == NULL) {
        printf("\nERRO: Memória insuficiente");
        exit(1);
    }
    
    *(output + index) = '\0';

    return output;
}