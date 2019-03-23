
#define _GNU_SOURCE
#include "File.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <commons/collections/list.h>

#define MAX_STRING 255

struct File
{
    FILE* _imp;
};

File* file_open(char const* fileName, Mode mode)
{
    // pre: mode is a valid Mode
    // filename is a valid path
    char fmode[2] = "";
    switch (mode)
    {
        case F_OPEN_READ:
            fmode[0] = 'r';
            break;
        case F_OPEN_WRITE:
            fmode[0] = 'w';
            break;
        case F_OPEN_APPEND:
            fmode[0] = 'a';
            break;
    }

    File* res = malloc(sizeof(File));
    res->_imp = fopen(fileName, fmode);
    return res;
}

char* file_readline(File const* file, int32_t line)
{
    char* resBuffer = malloc(MAX_STRING);
    size_t sz = MAX_STRING;
    int32_t currLine = 1;
    for (; currLine <= line; getline(&resBuffer, &sz, file->_imp), ++currLine);
    rewind(file->_imp);

    //trim eol
    resBuffer[strcspn(resBuffer, "\r\n")] = '\0';
    return resBuffer;
}

void file_for_each_line(File const* file, FilterFn fn)
{
    char* buf = malloc(MAX_STRING);
    size_t sz = MAX_STRING;

    while (getline(&buf, &sz, file->_imp) > 0)
        fn(buf);

    free(buf);
}

void file_write_transform(File const* file, void* list, TransformFn fn)
{
    // pre: file open for write/append
    char* fnRet = NULL;
    void closure(void* element)
    {
        fnRet = fn((char const*)element);
        fputs(fnRet, file->_imp);
        fputs("\n", file->_imp);
        free(fnRet);
    }

    list_iterate((t_list*)list, &closure);
    rewind(file->_imp);
}

void file_close(File* file)
{
    fclose(file->_imp);
    free(file);
}
