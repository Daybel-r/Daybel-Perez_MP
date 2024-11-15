#include <stdio.h>

/* Archivo y caracteres.
El programa escribe caracteres en un archivo.*/

void main (void)
{
char p1;
FILE *ar;

ar = fopen("C:\\Users\\Daybel\\Desktop\\C3-2024-MP2\\Proyecto 9.1\\Lectura.txt", "r") if (ar != NULL)
if (ar != NULL)
{
    while ((p1=getchar())) != '\n' && p1 != EOF)
    {
        putchar(p1); // Imprime el caracter en pantalla
    }
   fclose(ar);

}
else
{

    printf("No se puede abrir el archivo");
}

    return 0;

}
