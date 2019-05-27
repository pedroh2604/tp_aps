#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#include "types.h"
#include "compacta.h"
#include "descompacta.h"
#include "fileutils.h"

#define LOG_FILE_ACTIVITY 0
#define LOG_COMPRESS_ACTIVITY 0

#define SOURCE_PATH "imagemConvertida.txt"
#define COMPRESSED_PATH "imagemCompactada.txt"
#define UNCOMPRESSED_PATH "imagemDescompactada.txt"

int main() {

    setlocale(LC_ALL, "Portuguese");

    FileData sourceData = readFile(SOURCE_PATH, LOG_FILE_ACTIVITY);
    writeFile(COMPRESSED_PATH, compress(&sourceData, LOG_COMPRESS_ACTIVITY), LOG_FILE_ACTIVITY);
    FileData compressedData = readFile(COMPRESSED_PATH, LOG_FILE_ACTIVITY);
    writeFile(UNCOMPRESSED_PATH, uncompress(&compressedData, LOG_COMPRESS_ACTIVITY), LOG_FILE_ACTIVITY);

    return 0;
}
