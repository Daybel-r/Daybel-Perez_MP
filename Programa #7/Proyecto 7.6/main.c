#include <stdio.h>
#include <string.h>

/* Funciones de la biblioteca string.h para el manejo de cadenas de
caracteres. */

void main(void)
{
char *cad0 = "Hola Mexico";
char cad1[20], cad2[20], cad3[20] = ", buenos dias!!!";

strcpy(cad1, cad0);
/*La funcion strcpy permite copiar una cadena de caracteres completa. En este
caso se copia la cadena cad0 = a cad1. Si el espacio reservado para cad1 es
menor que el de cad0, se genera un error en la ejecucion del programa. */
printf("\nPrueba de la funcion strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

strcpy(cad1, cad3);
/* La funcion strcpy permite copiar un cadena de caracteres completa. En este
caso se copia la cadena cad0 a cad1. Si el espacio reservado para cad1 es
menor que el de cad0, se genera un error en la ejecucion del programa.*/
printf("\nPrueba de la funcion strcpy. Se copia la cadena cad0 a cad1: %s\n", cad1);

strcpy(cad1, "XX");
printf("\nPrueba de la funcion strcpy. Se copia la cadena XX a cad1: %s\n", cad1);

strcpy(cad2, cad0, 4);
 cad2[4] = '\0';
/* La funcion strncpy permite copiar un numpero determinado de caraceteres a
otra cadena de caracteres. En este caso se copian 4 caracteres de la cadena
cad0 -segundo argumento- a cad2 - primer argumento. Siempre se debe
incorporar al final de la cadena el caracter de terminacion. Si el espacio
reservado para cad2 es menor que lo que se pretende copiar, se genera
un error en la ejecucion del programa.*/
printf("\nPrueba de la funcion strncpy. Se copian 4 caracteres de cad0 a
       cad2: %s\n");
                        cad2);

strcat(cad0, cad3);
/* La funcion stract permite incorporar una cadena de caracteres a otra
cadena dada. En este caso se agrega la cadena cad3 a cad0. Si el espacio
reservado para cad0 es menor a lo que se debe almacenar se genera un error
de ejecucion. */
printf("\nPrueba de la funcion stract. Se incorpora la cadena YY a cad1:
       %s\n", cad0);


stract(cad1, "YY");
printf("\nPrueba de la funcion strcat. Se inorporan 4 caracteres de cad0
       a cad2
                %s\n", cad2);
/* La funcion strncat permite incorporar un numero determinado de caracteres
a una cadena. En este caso se agrefan cuatro caracteres de la cadena cad0
a cad2. Si el espacio de cad2 es menor a lo que se debe almacenar ocurre
un error de ejecucion. */

cad0 = strstr(cad0, "Mexico");
printf("\nPrueba de la funcion strstr. Se trata de localizar la cadena
       Mexico dentro de cad0: %s\n" , cad0);
       /* La funcion strstr se utiliza para localizar un cadena de caracteres dentro
       de otra cadena. Si la encuentra, regresa un apuntador al inicio de la
       primera ocurrencia de la cadena localizada, De otra forma, regresa NULL. */

       cad0 = strstr(cad0, "Guatemala");
       printf("\nPrueba de la funcion strst. Se trata de localizar de la cadena
              Guatemala dentro de cad0: %s\n", cad0);


