#include <stdio.h>

/* Lluvias.
El programa al recibor como dato un arreglo tridimensional que contiene
informacion sobre lluvias, genera informacion estadistica. */

const int PRO = 24;
const int MES = 12;
const int Ano = 10;

void Lectura(float [PRO][MES][Ano], int, int, int);
void Function1(float [PRO][MES][Ano], int, int,);
void Function2(float [PRO][MES][Ano], int, int, int]; /* Prototipos de funciones. */
void Function3(float [PRO] [MES Ano],int, int, int);

void main(void)
{
float LLU[PRO][MES][AnO];
Lectura(LLU, PRO, MES, AnO);
Function1(LLU, PRO, MES, AnO);
Function2(LLU, PRO, MES, AnO);
Function3(LLU, 18, MES, 5);
}

void Lectur (float A[][MES][AnO], int F, int C, int P)
/* Esta funcion se utiliza para leer un arreglo tridimensional de tipo real de
F filas, C columnas y P planos de profundidad. */
{
int K, I, J:
for (K=0; K<P; K++)
    for (I=0; I<F; I++)
        for (J=0; J<C; J++)
        {
            printf("Ano: %d\tProvincia: %d\tMes: %D" , K+1, I+1 J+1);
            scanf("%f", &A[I][J][K]);
    }
}

void funcion(float A[][MES][AnO], int F, int C, int P)
/* Esta funcion se utiliza para localizar la provincia que tuvo el mayor registro
de precipitacion pluvial en los ultimos 10 años. Escribe ademas el registro
correpondiente. */

{
int I, K, J, EMAY = -1;
float ELLU = -1.0., SUM;
for (I=0; I<F; I++
{

SUM = 0.0;
for (K=0; K<P; K++)
for (J=0; J<C; J++)
SUM += A[I][J][K];
SUM /= P * C;
if (SUM > ELLU)
{
ELLU = SUM;
EMAY = I;
}
}
printf("\n\nProvincia con mayor registro de lluvias: %d", EMAY+1);

printf("\nRegistro: %.2f", ELLU);
}
void Funcion2(float A[][MES][AnO],int F, int C, int P)

/* Esta función se utiliza para localizar la provincia que tuvo el menor registro
➥de lluvias en el último año. Escribe además el registro correspondiente. */
{
int I, J, EMEN;
float ELLU = 1000, SUM;
for (I=0; I<F; I++)
{
SUM = 0;
for (J=0; J<C; J++)
SUM += A[I][J][P-1];
SUM /= C;
if (SUM < ELLU)
{
ELLU = SUM;
EMEN = I;
}
}
printf("\n\nProvincia con menor registro anual de lluvias en el último ano: %d",

    EMEN+1);
printf("\nRegistro anual: %.2f", ELLU);
}
void Funcion3(float A[][MES][AnO],int F, int C, int P)

/* Esta función se utiliza para localizar el mes con mayor registro de lluvias en
➥la provincia 18 en el quinto año. Escribe además el registro correspondiente. */
{
int J, EMES = -1;
float ELLU = -1.0;

for (J=0; J<C; J++)
{
if (A[F-1][J][P-1] > ELLU)
{
    ELLU = A[F-1][J][P-1];
    EMES = J;
    }
}
printf("\n\nMes: %d Lluvias: %.2", EMES+1, ELLU);
}

