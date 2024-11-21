#include <stdio.h>
#include <stdlib.h>

// Función para inicializar el arreglo
void inicializarArreglo
(int *arr, int size) {
for (int i = 0; i < size; i++) {
arr[i] = i + 1;
    }
}

// Función para redimensionar el arreglo
int* redimensionarArreglo(int *arr, int oldSize, int newSize) {
int *nuevoArr = (int *)realloc(arr, newSize * sizeof(int));
if (nuevoArr == NULL) {
printf("Error al redimensionar memoria\n");
free(arr); // Liberar memoria anterior si falla realloc
return NULL;
}
// Rellenar nuevos elementos si el tamaño ha aumentado
if (newSize > oldSize) {
for (int i = oldSize; i < newSize; i++) {
            nuevoArr[i] = i + 1;
        }
    }
return nuevoArr;
}

// Función para imprimir el arreglo
void imprimirArreglo(int *arr, int size) {
printf("Arreglo: ");
for (int i = 0; i < size; i++) {
printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
int n = 3;
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Error al asignar memoria\n");
return 1;
    }

// Inicializar arreglo
inicializarArreglo(arr, n);

// Redimensionar el arreglo
int nuevoTamanio = 5;
arr = redimensionarArreglo(arr, n, nuevoTamanio);
if (arr == NULL) {
return 1;
    }

// Imprimir el arreglo
imprimirArreglo(arr, nuevoTamanio);

// Liberar la memoria
free(arr);

return 0;
}
