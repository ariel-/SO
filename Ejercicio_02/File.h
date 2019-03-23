
#ifndef File_h__
#define File_h__

#include <stdint.h>

typedef struct File File;

typedef enum
{
    F_OPEN_READ   = 0x0,
    F_OPEN_WRITE  = 0x1,
    F_OPEN_APPEND = 0x2
} Mode;

typedef void(*FilterFn)(char const* line);
typedef char*(*TransformFn)(char const* line);

File* file_open(char const* fileName, Mode mode);
char* file_readline(File const* file, int32_t line);
void file_for_each_line(File const* file, FilterFn fn);
void file_write_transform(File const* file, void* list, TransformFn fn);
void file_close(File* file);

#endif //File_h__
