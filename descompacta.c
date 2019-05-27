#include <stdio.h>
#include <stdlib.h>
#include "descompacta.h"
#include "types.h"

char *uncompress(FileData *fileData, int logResults) {

    char *ptrOutput = NULL;
    unsigned int cursor = 0;
    unsigned int counter = 0;

    printf("\nDescompactando arquivo %s\n", (*fileData).path);
    if (logResults) {
        printf("(fileData->size): %i\n", fileData->size);
    }

    while (cursor < (fileData->size)) {
        char c = (fileData->data[cursor]);
        cursor++;
        unsigned int occurences = 0;
        if (c == 'L') {
            ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));

            if (ptrOutput == NULL) {
                printf("\nERRO: Memória insuficiente");
                exit(1);
            }

            *(ptrOutput + counter) = '\n';
            counter++;
            if (logResults) {
                printf("\n");
            }
        } else {
            while ((fileData->data[cursor]) >= 48 && (fileData->data[cursor]) <= 57) {
                occurences = occurences * 10 + ((fileData->data[cursor]) - 48);
                cursor++;
            }
            for (unsigned int n = 0; n < occurences; n++) {
                ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));

                if (ptrOutput == NULL) {
                    printf("\nERRO: Memória insuficiente");
                    exit(1);
                }

                *(ptrOutput + counter) = c;
                counter++;
            }
            if (logResults) {
                printf("%c[%u]", c, occurences);
            }
        }
    }

    if (logResults) {
        printf("\nResultado da descompactação: \n%s\n", ptrOutput);
    }

    ptrOutput = realloc(ptrOutput, sizeof(char) + (counter * sizeof(char)));

    if (ptrOutput == NULL) {
        printf("\nERRO: Memória insuficiente");
        exit(1);
    }
    
    *(ptrOutput + counter) = EOF;

    return ptrOutput;
}
