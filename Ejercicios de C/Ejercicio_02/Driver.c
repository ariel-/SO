
#include "File.h"
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <commons/collections/list.h>

int main(void)
{
    File* prueba = file_open("tests.txt", F_OPEN_READ);

    char* linea = file_readline(prueba, 1);
    assert(!strcmp("Linea1", linea));
    free(linea);

    linea = file_readline(prueba, 4);
    assert(!strcmp("Linea4", linea));
    free(linea);

    {
        size_t counter = 0;
        void ContarCaracteres(char const* linea)
        {
            counter += strlen(linea);
        }
        file_for_each_line(prueba, &ContarCaracteres);
        printf("Conteo de caracteres: %zu\n", counter);
    }

    file_close(prueba);

    prueba = file_open("tests.txt", F_OPEN_APPEND);

    t_list* palabras = list_create();
    list_add(palabras, "Luna");
    list_add(palabras, "Abedul");
    list_add(palabras, "Tronco");
    list_add(palabras, "Sol");
    list_add(palabras, "YYZ");

    char* CaesarCipher(char const* linea);
    file_write_transform(prueba, palabras, &CaesarCipher);

    list_destroy(palabras);
    file_close(prueba);

    prueba = file_open("tests.txt", F_OPEN_READ);

    linea = file_readline(prueba, 6);
    assert(!strcmp("Dehgxo", linea));
    free(linea);

    file_close(prueba);
}

char* CaesarCipher(char const* linea)
{
    char* result = malloc(strlen(linea) + 1);
    char* j = result;
    for (char const* i = linea; *i != '\0'; ++i, ++j)
    {
        char c = *i;
        char base = '\0';
        if (isupper(c))
            base = 'A';
        else if (islower(c))
            base = 'a';

        if (base)
            c = ((c - base + 3) % 26) + base;

        *j = c;
    }

    *j = '\0';
    return result;
}
