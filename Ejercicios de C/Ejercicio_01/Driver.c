
#include "Basics.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char* string = string_concat("Hola, ", "Mundo!");
    assert(!strcmp("Hola, Mundo!", string));
    free(string);

    string_concat_dinamyc("Hola, ", "K3052!", &string);
    assert(!strcmp("Hola, K3052!", string));
    free(string);

    char* user;
    char* domain;
    mail_split("mail@split", &user, &domain);
    assert(!strcmp("mail", user));
    assert(!strcmp("split", domain));
    free(user);
    free(domain);
}
