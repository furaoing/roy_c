#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char* _fread(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    char* str = (char*) malloc(file_size*sizeof(char));
    strcpy(str, fp->_IO_read_base);
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
