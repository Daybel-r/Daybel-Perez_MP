#include <stdio.h>

/*Intercambia.
El programa intercambia las columnas de un arreglo bidimensional. Los
elementos de la primera columna se intercambian con los de la ultima.
los de la segunda con los de la penultima, asi sucesivamente. */

const int max = 50;

void Lectura(float[][MAX], int, int);
void Intercambia(float [][MAX], int, int);      /* Prototipos de funciones.*/
void Imprime(float [][MAX], int, int);

void main(void)
{
int F, C;
float MAT[MAX][MAX];
do
{
    printf("Ingrese el numero de filas: ");
    scanf("%d", &F);

}
while (F > MAX || F < 1);       /* Se verifica que el numero de filas sea correcto. */
do
{
      printf("Ingrese el numero de columnas: ");
      scanf(" %d", &C);

}
while (C > MAX || C < 1);      /* Se verifica que el numero columnas sea
                                correcto.*/

Lectura(MAT, F, C);
Intermcambia(MAT, F, C);
Imprime(MAT, F, C);
}

void Lectura(float A[][MAX], int F, int C)
/* La funcion Lectura se utiliza para leer un arreglo bidimensional de tipo
real de F filas y C columnas. */
{
int I, J;
for (I=0; I< F; I++)
   for (J+0; J<C; J++)
    {
    printf("Ingrese el elementos %d %d:   ", I+1, J+1);
    scanf("%f", &A[I][J];)

    }

}
void Intercambia(float A[][MAX], int F, int C)
/* Esta funcion se utiliza para intercambiar las columnas de arreglo
bidimensional. Observa que el indice correspondiente a las columnas solo se
mueve hasta la mitad de arreglo. */
{
int I, J;
float AUX;
/*Observa que en esta funcion el indice I se utiliza para las columnas, y el
indice J para las filas. */
{
int I, J;
float AUX;
/*Observa que esta funcion el indice I se utiliza para las columnas, y el I se utiliza para las columnas, y el
indice J para las filas. */
for (I=0; I < (C / 2); I++)
        for (J=0; J< F; J++)
        {

        AUX = A[J][I];
        A[J][I] = A[J][C-I-1];
        A[J][C-I-1]=AUX;

    }


}
void Imprime(floatA[][MAX], int F, int C)
/* La funcion Imprime se utiliza para escibir un arreglo bidimensional tipo
real de F filas y C columnas. */
{
int I, J;
for (I=0; I<F; I++)
      for (J=0; J<C; J++)
        printf("\nElemento %d %d: %5.2f", I+1, J+1, A[I][J]});
}