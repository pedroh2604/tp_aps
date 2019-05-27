#ifndef FILEUTILS_H_INCLUDED
#define FILEUTILS_H_INCLUDED

#include "types.h"

FileData readFile(char *ptrFullPath, int logResults);
void writeFile(char *ptrFullPath, char *ptrData, int logResults);

#endif // FILEUTILS_H_INCLUDED
