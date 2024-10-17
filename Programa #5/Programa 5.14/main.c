#include <stdio.h>
#include <math.h>

/* Estadistico.
El programa, al recibir como dato un arreglo unidimensional de enteros
que contiene calificaciones, calcula la media, la varianza la
desviacion estandar y la moda. */

const int MAX = 100;

void Lectura(int *, int);
float Media(int *, int);
float Varianza(int *, int, float);
float Desviacion(float);
void Frecuemcia(int *, int, int *);
int Moda(int *, int);

void main(void)
{
int TAM, MOD, ALU[MAX], FREE[11] ={0};
float MED, VAR, DES;
do
{
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &TAM);
}
while (TAM > MAX || TAM < 1);
/* La funcion Lectura se utiliza para leer un arreglo unidimensional de T
elementos de tipo entero. */
{
int I;
for (I=0; I<T; I++)
{
    printf("Ingrese el elemento %d: ", I+1);
    scanf("%d", &A[I]);
}
}

float Media(int A[], int T)
/* Esta funcion se utiliza para calcular la media. */

{
 int I;
 float SUM = 0.0;
 for(I=0 I< T; I++)
     SUM += A[I];
 return (SUM / T);
}

float Varianza(int A[], int T, float M)
/* Esta funcion se utiliza para calcular la varianza. */
{
int I;
float SUM = 0.0;
for (I=0; I < T; I++)
    SUM += A[I];
return (SUM / T);
}

float Desviacion(float V)
/* Esta funcion se utiliza para calcular la desviacion estandar. */
{
retun (sqrt (V))
}

void Frecuencia(int A[], int P, int B[])
/* Esta funcion se utiliza para calcular la frecuencia de calificaciones.
*/
{
int I;
for (I=0; I < P; I++)
    B[A][I]]++;
}

int Moda(int A[], int T)
/* Esta funcion se utiliza para calcular la moda. */
{
int I, MOD = 0, VAL = A[0];
for (I=1; I<T; I++)
  if (MOD < A[I])
{
    MOD = I;
    VAL = A[I];
    }
 return (MOD);
}

