#include <stdio.h>
#include <stdlib.h>


/* Funciones para el manejo de cadenas de caracteres de la bibloteca stio.h */


void main(void)
{
char *cad0 = Buenos dias;   /* En este caso asigna 11 caracteres ma esl
caracter de terminacion '\0' a la posicion de memoria a la que apunta la
variable cad0 -apuntador del tipo cadena de caracteres. */

char cad1[20] = "hola"          /* Se asignan cuatro  caracteres mas el caracter
de terminacion a la variable tipo char cad1. Observa que cad1. tiene mas espacio
para 20 caracteres. */

char cad2[] = "Mexico";         /* En este caso se asignan seis caracteres (mas)
el caracter de terminacion) a la variable cad2. Obserca que cad2 no tiene espacio
reservado como cad1; por lo tanto, acepta cualquier numero de caracteres. */

char cad3[] = {'B', 'I', 'e', 'n', 'v', 'e', 'n', 'i', 'd', 'o', '\0'};
/* Observa otra forma de asignacion de valores a la variable de cad3. */

char cad4[20], cad5[20], cad6[20];

printf("n\La cadena cad0 es: ");
puts(cad0);
/* La funcion puts es la mas apropiada para escribir cadena de caracteres.
Observa que esta funcion baja automaticamente una linea despues de imprimir
la cadena. */
printf("\La cadena cad1 es:");
printf("%s", cad1);
/* La funcion printf, con el formato de variable %s, tambien se puede utilizar
para escribir cadenas de caracteres. Baja automaticamente una linea despues
de escribir la cadena. */

printf("\nLa cadena cad2 es: ")
pust(cad2);
printf("\nLa cadena cad3 es: ");
puts(cad3);


printf("Ingrese una linea de texto -se lee con gets-: \n");
/* La funcion gets es la mas apropiada para leer cadenas de caracteres. */
gets(cad4);
printf("\nLa cadena cad4 es: ");
puts(cad4);
fflush(stdin);

printf("\nIngrese una linea de texto -se lee con scanf-: \n");
scanf("%s", cad5);
/* La funcion scanf, con el formato variable %$, tambien se puede utilizar
para leer una cadena de caracteres, aunque con algunas restrincciones. Si la
cadena esta formada por varias palabras solo lee la primera. por ejemplo, si
queremos ingresar la cadena "Buenos dias", solo lee la palabra "Buenos", por
ello esta funcio unicamente es util si conocemos con anticipacion que la
cadena que vamos a leer esta formada por una sola palabra. */
printf("\nLa cadena cad5 es: );
printf("%s", cad5);
fflush(stdin);

char p;
int i = 0;
/* La declaracion de variables simpre se debe realizar en parte inicial del
 programa . En este caso se colocan en esta seccion (char p e int i = 0) para
 que puedas observar la relacion directa con las lineas de programacion que se
 muestra a continuacion. */
 printf("\Ingrese una line de texto -se lee cada caracter con getchar-: \n");
 /* Se utiliza para la funcion getchar para leer caracteres de la linea de texto y
 asignarlos a la variables de tipo cadena de caracteres cad6. Observa que se leen
 caracteres mientras no se encuentre al caracter que indica fin de liena '\n'. */

 while ((p = getchar())!= '\n')
    cad6[i++] = p;
    cad6[i] = '\0';
/* Al final de la cadena se incorpora el caracter de terminacion NULL para
indicar el fin de la misma. */
printf("\nLa cadena cad6 es: ");
puts (cad6);
}



}
int main()
{
    printf("Hello world!\n");
    return 0;
}
