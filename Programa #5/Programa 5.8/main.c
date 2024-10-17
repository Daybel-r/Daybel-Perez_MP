#include <stdio.h>

/* Primos.
El programa almacena en un arreglo unidimensional los primeros 100 numeros
primos. */

const int TAM = 100;

void Imprime(int, int);                 /* Prototipo de Funciones. */
void Primo(int, int *);

void main(void)
{
int P[TAM] = {1,2};
int FLA, J = 2, PRI = 3;
while (J <= TAM)
{
    FLA = 1;
      Primo(PRI, &FLA);         /* Se llama a la funcion determina si PRI es
        Primo. */
        if (FLA)               /* Si FLa es 1, entonces PRI es primo. */
        {
            P[2] = PRI;
            J++;
        }
        PRI += 2;

    }
    Imprime(P, TAM);
    }

    void Primo(int A, int *B)
    /* Esta funcion determinar si A es primo, en cuyo caso el valor de  *B no se
    altera. */
    {
    int DI = 3;
    while (*B && (DI < (A/2)))
    {
        if ((A % DI) ==0)
            *B = 0;
        DI++;

    }
    }

    void Imprime(int Primos[], int T)
    /* Esta funcion Imprime el arreglo unidimensional de numeros primos. */
    {
    int I;
    for (I=0; I<T; I++)
        printf("\nPrimos[%]: %d", I, Primos[I]);

}
