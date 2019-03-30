
#include "Basics.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

char* string_concat(char const* left, char const* right)
{
    char* result;
    string_concat_dinamyc(left, right, &result);
    return result;
}

void string_concat_dinamyc(char const* left, char const* right, char** result)
{
    *result = malloc(strlen(left) + strlen(right) + 1);
    strcpy(*result, left);
    strcat(*result, right);
}

void mail_split(char const* mail, char** user, char** domain)
{
    // Pre: mail is a valid mail address
    size_t off = strcspn(mail, "@");
    *user = calloc(off + 1, 1);
    strncpy(*user, mail, off);

    *domain = malloc(strlen(mail + off));
    strcpy(*domain, mail + off + 1); // skip '@'
}
