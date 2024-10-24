#include <stdio.h>
#include <stdlib.h>

/* Funciones para el manejo de caracteres de la biblioteca  stdio.h*/


void main(void)
{
char p1, p2, p3 = '$';
/* Declaracion de las varibles tipo caracter p1, p2, y p3. Observa que a p3 se le
 asigna el simbolo $. */
printf("\nIngrese un caracter: ");
p1=getchar();                /* Se utiliza la funcion getcher para leer un caracter. */
putchar(p1);                /* Se utiliza para la funcion putchar para escribir ub
caracter. */
printf("\n");
fflush(stdin);
/*Luego de leer un caracter siempre es conveniente escribir la funcion fflush
para limpiar el bufer, porque el generalmente queda con basura y genera un error
en la ejecucion del programa. El error se produce por que cuando se ingresa un
dato se oprime el return y luego cuando volvemos a leer un caracter o una
cadena de caracteres se toma y a ese return como el nuevo dato de ingresado. */

printf("\nEl caracter p3 es: ");
putchar(p3);
/* Se utiliza la funcion putchar para escribir el caracter almacenado en p3. */
printf("\n");
printf("\nIngrese otro caracter: ");
fflush(stdin);
scanf("%c", &p2);
/* Se puede utilizar scanf con el formato de variable %c para leer un caracter. */
printf("%c", &p2);
/* Se puede utilizar printf con el formato de variable %c para escribir un
caracter. */
}
