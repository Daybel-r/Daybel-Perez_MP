#include <stdio.h>

/* Frecuencia de calificaciones.
El programa, al recibir como datos las calificaciones de un grupo de 50
alumnos, al recibir como datos de cada una de las calificaciones y ademas
escribe cual es la frecuencia mas alta. */

const int TAM = 50;

void Lectura(int *, int);
void Frecuencia(int, int, int, int);        /* Prototipo de funciones. */
void Impresiones(int *, int);
void Mayor(int *, int);

void main(void)
{
int CAL [TAM], FRE[6] = {0};   /* Declaracion de los arreglos. */
Lectura(CAL, TAM);              /* Se llama a la funcion Lectura. */
Frecuencia(CAL, TAM, FRE, 6);
/* Se llama a la funcion Frecuencia, se pasan ambos arreglos. */
printf("\nFrecuencia de Calificaciones\n");
Impresiones(FRE, 6);
Mayor(FRE, 6);
}

void Lectura (int VEC[], int T)
/* La funcion Lectura se utiliza para leer el arreglo de calificaciones. */
{
int I;
for (I=0; I<T; I++)
{
 printf("Ingrese la calificacion -0:5- del alummno %d: ", I+1);
 scanf("%d", &VEC[I]);
}
}
void Impresion(int VEC[], int T)
/* La funcion Impresion se utiliza para imprimir el arreglo de frecuencias. */
{
 int I;
 for (I=0; I<T; I++)
 printf("\nVEC[%d]: %d", I, VEC[I]);
}

void Frecuencia(int A[], int P, int B[], int T)
/* La funcion calcula la Frecuencia de calificaciones. */
{
 int I;
 for (I=0; I<P; I++)
      if ((A [I] >=0) && (A[I] <6))     /* Se valida que califiacion sea
      correcta. */
      B[A[I]]++;            /*Observa la forma de almacenar e incrementar las
 frecuencias. */

}

void Mayor(int *X, int T)
/* Esta funcion obtiene la primera ocurrencia de la frecuencia mas alta. */
{
int I, MFRE = 0, MVAL = X[0];
for(I=1; I<T; I++)
  if (MVAL < X[I])
{
   MFRE = I;
   MVAL = X[I];
    }
 printf("\n\nMayor frecuencia de calificaciones: %d \tValor: %d" , MFRE, MVAL);
}
