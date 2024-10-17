#include <stdio.h>

/* Busqueda secuencial en arreglos ordenados en forma creciente. */

const int max=100;

void Lectura(int, int);         /* Prototipos de Funciones. */
int Busca(int *, int, int);

void main(void)
{
int RES, ELE, TAM, VEC[MAX];
do
{
    printf("Ingrese el tama�o del arreglo: ");
    scanf("%d", &TAM);

}
while (TAM > MAX || TAM < 1);
/* Se verifica que el tama�o del arreglo sea correcto. */
Lectura(VEC, TAM);
printf("\nIngrese el elemento a buscar:");
scanf("%d", &ELE);
RES = Busca(VEC, TAM, ELE);    /* Se llama a la funcion que busca en el
                                arreglo. */

if (RES)
/* Si RES tiene un valor verdadero -diferente de 0-, se escribe la
posicion en la que se encontro al elemento. */
    printf("\nEl elemento no se encuentra en el arreglo");
else
    printf("\nEl elemento no sen encuentra en el arreglo");
}

void Lectura(int A[], int T)
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
int Busca(int A[], int T, int E)
/* Esta  funcion se utiliza para localizar elemento E en el arreglo
unidimensional A.
Si se encuentra, la funcion regresa la posicion correspondienre. En caso
Contrario regresa 0.*/
{
int RES, I = 0, BAN = 0;
while ((I< T) &&(E >= A[I] && !BAN)
/*Observa que se incorporaben una nueva condicion. */
    if (A[I] == E)
          BAN++;
if (BAN)
    RES = I + 1;
    /* Se asigna I+1 dado que las posiciones en el arreglo comienza des
    de cero.*/
    else
      RES = BAN;
    return (RES);
}
