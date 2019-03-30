
#include <math.h> // para sqrt (faltante)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// tipo de dato argumento innecesario int main(void)
//Errorn no están declaradas
void Error1(void);
void Error2(void);
void Error3(void);
void Error4(void);
void Error6(void);

int main(void)
{
    Error1();
    Error2();
    Error3();
    Error4();
    Error6();
    printf("Pareciera que esta todo bien!!\n");
}

void Error1()
{
    printf("Error 1 \n");
    // int i; mayor scope al necesario
    char cadena[10] = ""; // variables sin inicializar
    char cadena2[10] = "";
    // index out of range
    //for (i = 1; i <= 10; i++) // post-incremento usa mas instrucciones que pre-incremento
    for (int i = 0; i < 10; ++i)
    {
        // faltan breaks luego de cada case
        switch (i)
        {
            case 1:
                cadena[i] = 'A';
                break;
            case 2:
                cadena[i] = 'B';
                break;
            case 3:
                cadena[i] = 'C';
                break;
            case 4:
                //cadena[i] = "D"; usa comillas dobles (char*) en lugar de simples (char)
                cadena[i] = 'D';
                break;
            default:
                //cadena[i] = "-"; usa comillas dobles (char*) en lugar de simples (char)
                cadena[i] = '-';
                break;
        }
    }

    // cadena[9] = 'a'; null terminator no valido
    cadena[9] = '\0';
    printf("cadena 1: %s", cadena);
    //if (strcmp(cadena2, cadena)) strcmp devuelve 0 si ambas cadenas son iguales
    if (!strcmp(cadena, cadena2))
        printf("Genere 2 cadenas iguales!\n");
}

void Error2()
{
    char* cadena1 = "El Zumba";
    // char* cadena2 = "El Zumba"; error! 
    // al usar puntero, la cadena se genera en la seccion ro, pero luego se llama a strcpy
    // con el puntero como dest. Esto esta muuuyyyy mal, para arreglarlo debemos crear un array en el stack.
    char cadena2[] = "El Zumba";

    // if (cadena1 == cadena2) comparacion con ==
    if (!strcmp(cadena1, cadena2))
        printf("Son iguales! :)\n");

    //char* st; strcpy requiere un bufer alocado en memoria
    char* st = malloc(4);
    strcpy(st, "abc");
    free(st); // free faltante, incluso en el resuelto ;)

    //char* cadena3 = malloc(strlen(cadena1)); se debe alocar espacio para el null-terminator
    char* cadena3 = malloc(strlen(cadena1) + 1);
    strcpy(cadena3, cadena1);
    strcpy(cadena2, cadena3);
    //if (strcmp(cadena1, cadena2) == 0) las cadenas copiadas son la 2 y 3
    if (!strcmp(cadena2, cadena3))
        printf("Genere 2 cadenas iguales!\n");
    free(cadena3); // free faltante x2
}

void Error3()
{
    int x;
    char* st = malloc(31);

    //scanf no imprime
    //scanf("Inserte un numero %d\n", x); // debe ser puntero
    //scanf("Inserte una cadena %30s\n", &st); // st ya es un puntero a la primera posicion
    printf("Inserte un numero ");
    scanf("%d", &x);
    printf("\nInserte una cadena ");
    scanf("%30s", &st[0]);
    printf("\n");
    char* st2 = st;

    // ModificarCadena no declarado
    void ModificarCadena(char**);
    //ModificarCadena(st); pasa la cadena por valor y no por referencia
    ModificarCadena(&st);

    if (strcmp(st, st2) != 0)
        printf("Logre cambiar la cadena! \n");
    else
        printf("No logre cambiar la cadena! \n");

    // memoria sin liberar
    free(st2);
}

void ModificarCadena(char** st)
{
    // al no utilizar * se modifica el parametro local 'st', sin reflejarse el cambio fuera de la funcion
    //st = "Nueva Cadena";
    *st = "Nueva Cadena";
}

void Error4()
{
    double raiz = sqrt(16);
    //if (raiz > 1) //comparacion de double con int (no es un error per-se dada la promocion de enteros, pero meh)
    if (raiz > 1.0)
        printf("Yuppiiie estoy para aprobar AM2!!\n");

    //Error5 no declarado
    //Error5(raiz); no pasa el parametro por referencia, ergo se modifica localmente una copia del argumento


    void Error5(double*);
    Error5(&raiz);

    //if (raiz == 2)
    if (raiz == 16.0) //deberia dar 16 de nuevo, y en el resuelto esta funcion es otro codigo, issue pl0x
        printf("Yuppiiie estoy para aprobar SO!!\n");
    else
        // printf("La raiz de 2 no me dio menor a 1!!!"); raiz de 2? era 16 ayyy
        printf("La raiz de 16 y elevada al cuadrado no me dió 16 nuevamente porque soy muy estúpido y comparo doubles con ==");
}

void Error5(double* raiz)
{
    // raiz = pow(raiz, 2);
    *raiz *= *raiz;
}

void Error6()
{
    int x = 5;
    //while (x > 0); el ; evita la ejecucion de esa otra linea
    //x--;

    // pero lo reescribo para mostrar un uso del postdecremento
    while (x-- > 0);
}
