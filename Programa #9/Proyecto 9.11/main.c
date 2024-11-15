#include <stdio.h>

/* Incrementa salarios.
El programa incrementa el salario de los empleados de una empresa
-actualiza el archivo correspondiente- si sus ventas son superiores
al millon de pesos anuales. */

typedef struct              /* Declaracion de la estructura empleado. */
{
int clave;
int departamento;
float salario;
float ventas[12];
}empleado;

void incrementas(FILE *);       /Prototipo de funcion. */

void main(void)
{
FILE *ar;
if((ar = fopen("ad5.dat", "rt"))!= NULL)
/* El archivo se abre en la modalidad para leer y escribir. */
   incrementa(ar);
else
   printf("\nEl archivo no se puede abrir");

rewind(ar);
/*La funcion rewind se utiliza para posicionarnos en el inicio del
archivo cada vez que sea necesario. En ete programa no tiene ninguna
utilidad, solo se escribio para explicar su uso. */

fclose(ar);
}

void inrementa(FILE *ap)
/* Esta funcion se utiliza para incrementar el salario de todos aquellos
empleados que hayas tenido ventas anuales por mas de $ 1,000, 000.
Actualiza ademas el archivo correspodiente. */
{
int i, j, t;
float sum;
empleado emple;

t = sizeof(empleado);
/* La funcion sizeof se utiliza para conocer el tamaño de la estructura
empleado. */

fread(&emple, sizeof(empleado), 1, ap);     /* Se lee el primer registro
                                                del archivo. */
while(!feof(ap))
{
    if = ftell(ap) / t;
    /* La funcion ftell se utiliza para conocer la posicion de nuestro
    apuntador el archivo. La variable i nos proporciona en este caso
    el tamaño de todos los bloques que existen debajo de nuestra
    posicion. Si conocemos el tamaño cada bloque, entonces podemos
    obtener el numero de bloques que hay exactamente debajo de nuestra
    posicion. */

    sum = 0;
    for (j=0; j<12; j++)
     sum += emple.ventas[j];        /* Se calcula las ventas cada
                                        vendedor. */

if (sum > 10000000)
{
    emple.salario = emple.salario * 1.10;       /*Se incrementa el
                                                   salario. */

fseek(ap,(i-1)*sizeof(empleado), 0);
/* Nos posicionamos para escribir el registro actualizado. */
fwrite(&emple, sizeof(empleado), 1, ap);
fseek(ap, i*sizeof(empleado), 0);
/*Nos prosicionamos nuevamente para leer el siguiente registro.
Esta instruccion no deberia ser necesario, pero la funcion
fwrite se comporta a veces de manera inestable  en algunos
complicadores de C. para aseguranos que siempre funcione
correctamente, realizamos este nuevo reposicionamiento. */



    }
    fread(&emple, sizeof(empleado), 1, ap);

}
}
