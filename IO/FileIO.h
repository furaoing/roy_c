#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* _fread(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    char* str = (char*) malloc(file_size*sizeof(char) + 1);
    fread(str, sizeof(char), file_size, fp);
    *(str + file_size) = '\0';
    fclose(fp);
    return str;
}

char* read(char* pth)
{
    char mode[] = "r";
    FILE* fp = fopen(pth, mode);
    return _fread(fp);
}

void read_clean(char* str)
{
    free(str);
}
