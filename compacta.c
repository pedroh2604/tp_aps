#include <stdio.h>
#include <stdlib.h>
#include "compacta.h"
#include "types.h"

char *compress(FileData *fileData, int logResults) {

    char *ptrOutput = NULL;
    unsigned int cursor = 0;
    unsigned int counter = 0;

    printf("\nCompactando arquivo... %s\n", (*fileData).path);
    if (logResults) {
        printf("(fileData->size): %i\n", fileData->size);
    }
    while (cursor < (fileData->size)) {
        if (logResults) {
            printf("%c", fileData->data[cursor]);
        }
        unsigned int occurences = 1;
        if (isEOL(fileData->data[cursor])) {
            ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));
            *(ptrOutput + counter) = 'L';
            counter++;
            cursor++;
        } else {
            ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));
            *(ptrOutput + counter) = (fileData->data[cursor]);
            counter++;
            if ((cursor + occurences) < (fileData->size)) {
                while ((fileData->data[cursor]) == (fileData->data[cursor + occurences])) {
                    occurences++;
                }
            }
            cursor += occurences;
            char numberString[20];
            intToString(occurences, numberString);
            unsigned int position = 0;
            while(numberString[position] != '\0') {
                ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));
                *(ptrOutput + counter) = numberString[position];
                counter++;
                position++;
            }
        }
    }

    if (logResults) {
        printf("\nResultado da compactação: \n%s\n", ptrOutput);
    }

    ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));
    *(ptrOutput + counter) = EOF;

    return ptrOutput;
}
