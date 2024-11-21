#include <stdio.h>
#include <stdlib.h>

// Funci�n para crear el arreglo e inicializarlo
void crearArreglo(int **arr, int size) {
*arr = (int *)malloc(size * sizeof(int));
if (*arr == NULL) {
printf("Error al asignar memoria\n");
exit(1);

}
for (int i = 0; i < size; i++) {
(*arr)[i] = i + 1;
    }
}

// Funci�n para imprimir el arreglo
void imprimirArreglo(int *arr, int size) {
printf("Elementos del arreglo: ");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");
}

// Funci�n para liberar la memoria del arreglo
void liberarArreglo(int *arr) {
free(arr);
printf("Memoria liberada.\n");
}

int main() {
int *arreglo = NULL; // Puntero para el arreglo
int tamano;

// Solicitar tama�o del arreglo al usuario
printf("Ingrese el tama�o del arreglo: ");
scanf("%d", &tamano);

// Crear el arreglo
crearArreglo(&arreglo, tamano);

// Imprimir el arreglo
imprimirArreglo(arreglo, tamano);

// Liberar la memoria
liberarArreglo(arreglo);

return 0;
}

