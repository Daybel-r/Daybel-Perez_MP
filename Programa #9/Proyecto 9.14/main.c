#include <stdio.h>
#include <ctype.h>

/* Letras minusculas y mayusculas.
El programa, al recibir como datos un archivo formado por cadena de caracteres,
determina el numero de letra minuscula y mayuscula que hay en el archivo. */

void minymay(FILE *);               /*Prototipo de funcion. */
/* Observa que esta funcion va a recibir un archivo como parametro. */

void main(void)
{
char p;
FILE *ar;
if ((ar = fopen("arc5.txt", "r")) !=NULL)
{
  minymay(ar);
  /* Se llama a la funcion minymay. Se pasa el archivo ar como parametro. */
  fclose(ar);
}
else
   printf("No se puede abrir el archivo");
}

void minymay(FILE *arc)
/* Esta funcion cuenta el numero de minuscula y mayuscula que hay en el
archivo arc. */
{
int min = 0, may = 0;
char p;
while (!feof(arc))
{
    p = fgetc(arc);         /* Se utiliza la funcion fgetc() para leer caracteres
                                del archivo. */
if (islower(p))
     min++;

else
   if (isupper(p))

}
printf("\nNumero de minusculas: %d", min);
printf("\nNumero de mayusculas: %d", may);
}
