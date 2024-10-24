#include <stdio.h>
#include <string.h>

/* Otras funciones de la biblioteca string. h para el manerjo de cadenas. */

void main(void)
{
char cad0[20] = "Hola Mexico";
char cad1[20] = "Hola Guatemala";
char cad2[20] = "Hola Venezuela";
char cad3[20] = "Hola Mexico";
char *c, c3;

i = strcmp(cad0, cad1);
/* La funcion strcmp permite comprar dos cadenas de caracteres. Si la
primera cadena -en este caso cad0- es mayor a la segunda -cad1-,
regresa un valor positivo; si es menor, un valor negativo y otra forma,
0. */
printf("\nResultado de la comparacion -cad0 y cad1-: %d", i);

i = strcmp(cad0, cad2);
printf("\nResultado de la comparacion -cad0 y cad2-: %d", i);

i = strcmp(cad0, cad3);
printf("\nResultado de la comparacion -cad0 y cad3-: %d", i);

i = strlen(cad0);
/* La funcion strlen obtiene la longitud - el numero de caracteres- de
una cadena.*/
printf("\nLongitud cadena cad0: %d", i);

i = strlen(cad1;)
printf("\nLongitud cadena cad1: %d", i);

c = strchr(Cad1, 'G');                  /* c es un apuntador de tipo caracter
*/
/* La funcion strchr busca la posicion en la que se encuentra un
determinado caracter de la cadena de caracteres. Si lo encuentra regresa
un apuntador a la primera ocurrencia del caracter en la cadena, de otra
forma regresa NULL. */
{

    C3 = C;                     /* C3 toma el contenido de la celda de memoria a ka
    que apunta c.*/
printf("\nEl valor de c3 es: %c", c3);
}

c= strchr(cad2, 'v');
if (c != NULL )
{

    C3 = *C;

printf("\nEl valor de c3 es : %c", c3);
}
}
