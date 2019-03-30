
#ifndef Basics_h__
#define Basics_h__

/*
 *   Retorna un String nuevo que es la concatenación
 *   de los dos Strings pasados por parámetro
 *   Ejemplo:
 *   char* nombre = "Ritchie";
 *   char* saludo = string_concat("Hola ", nombre);
 *   =>
 *   saludo = "Hola Ritchie"
 */
char* string_concat(char const*, char const*);

/*
 *   Asigna en el tercer parámetro, la concatenación
 *   de los primeros dos Strings
 *   Ejemplo:
 *   char* nombre = "Ritchie";
 *   char* saludo;
 *   string_concat("Hola ", nombre, &saludo);
 *   =>
 *   saludo = "Hola Ritchie"
 */
void string_concat_dinamyc(char const*, char const*, char**);

/*
 *   Separa el mail en un usuario y un dominio.
 *   Ejemplo:
 *   char* mail = "ritchie@ansic.com.ar";
 *   char* user;
 *   char* dominio;
 *   mail_split(mail, &user, &dominio);
 *   =>
 *   user = "ritchie"
 *   dominio = "ansic.com.ar"
 */
void mail_split(char const* mail, char** user, char** dominio);

#endif //Basics_h__
