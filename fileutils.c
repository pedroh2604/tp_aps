#include <stdio.h>
#include "fileutils.h"
#include "types.h"

FileData readFile(char *ptrFullPath, int logResults) {

    FILE *ptrFile = fopen(ptrFullPath, "r");
    char *ptrData = NULL;
    int counter = 0;
    FileData fileData;

    if (ptrFile == NULL) {
        printf("\nERRO: Não foi possível abrir o arquivo %s", ptrFullPath);
        exit(1);
    }

    if (logResults) {
        printf("\nMODO DEPURAÇÃO\n");
    }

    printf("\nLendo arquivo %s\n", ptrFullPath);
    while(!feof(ptrFile)) {
        ptrData = realloc(ptrData, sizeof(char) + (counter * sizeof(char)));

        if (ptrData == NULL) {
            printf("\nERRO: Memória insuficiente");
            exit(1);
        }

        *(ptrData + counter) = fgetc(ptrFile);
        if (logResults) {
            printf("%c", *(ptrData + counter));
        }
        counter++;
    }

    fclose(ptrFile);

    fileData.path = ptrFullPath;
    fileData.data = ptrData;
    fileData.size = counter;

    return fileData;
}

void writeFile(char *ptrFullPath, char *ptrData, int logResults) {

    FILE *ptrFile = fopen(ptrFullPath, "w");
    int counter = 0;

    if (ptrFile != NULL) {
        if (logResults) {
            printf("\nMODO DEPURAÇÃO\n");
        }
        printf("\nGravando arquivo %s\n", ptrFullPath);
        while(*(ptrData + counter) != EOF) {
            fputc(*(ptrData + counter), ptrFile);
            if (logResults) {
                printf("%c", *(ptrData + counter));
            }
            counter++;
        }
    } else {
        printf("\nERRO: Não foi possível abrir o arquivo %s", ptrFullPath);
        exit(1);
    }

    free(ptrData);

    fclose(ptrFile);
}
