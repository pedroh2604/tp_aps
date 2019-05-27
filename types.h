#ifndef TYPES_H_INCLUDED
#define TYPES_H_INCLUDED

int isEOL(char c);
void intToString(unsigned int number, char *output);
char *intToString2(unsigned int number);

typedef struct fileData{
    char *path;
    char *data;
    int size;
} FileData;

#endif // TYPES_H_INCLUDED
