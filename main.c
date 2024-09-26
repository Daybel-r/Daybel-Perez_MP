#include <stdio.h>

/* Numeros perfectos.
El programa, al recibir como dato un numero entero positivo como limite, obtiene
los numeros perfectos que hay entre 1 y ese numero, y ademas imprime cuantos
numeros perfectos hay en el intervalo.

I, J, NUM, C: variables de tipo entero. */

voidmain(void)
{
int I, J, NUM, SUM, C =0;//I Es el numero a verificar, J es el divisor, NUM es el limite, SUM almacena la suma de divisores, C cuenta los numeros perfectos.
printf("\nIngrese el numero limite: ");
scanf("%d", &NUM);// Solicita y lee el numero limite ingresado por el usuario.
for(I = 1; I <= NUM; I++)// Ciclo para encontrar los divisores de I
{
    SUM = 0;// Inicializa la suma de divisores en 0 para cada nuevo numero I.
    for (J = 1; J <= (I /2); J++) // Ciclo para encontrar los divisores de I
    if ((I % J)== 0) //Si J es divisor del I (el residuo del I divido por J es 0
            SUM += J; // Suma el divisor J a la variable SUM.
    if (SUM == I)// Si la suma de los divisores es igual I, entonces es un numero perfecto
    {
        printf("\n%d es un numero perfecto", I);// imprime que I es un numero perfecto.
        C++;// Incrementa el contador de numeros perfectos.
        }
    }
    printf("\nEntres 1 y %d hay %d numeros perfectos", NUM, C);// Imprime el numero total  de numeros perfectos encontrados en el intervalo.
    }
