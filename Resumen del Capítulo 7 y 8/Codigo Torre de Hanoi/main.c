#include <stdio.h>
#include <stdlib.h>

// Función para crear un arreglo dinámico
int *crearArreglo(int n) {
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Error al asignar memoria\n");
exit(1); // Finalizar el programa en caso de error
    }
    return arr;
}

// Función para rellenar el arreglo
void rellenarArreglo(int *arr, int n) {
for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Función para imprimir el arreglo
void imprimirArreglo(int *arr, int n) {
printf("Elementos del arreglo: ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
    }
printf("\n");
}

// Función para liberar el arreglo
void liberarArreglo(int *arr) {
free(arr);
}

// Función para crear una matriz dinámica
int **crearMatriz(int rows, int cols) {
int **matrix = (int **)malloc(rows * sizeof(int *));
if (matrix == NULL) {
printf("Error al asignar memoria\n");
exit(1);
    }
for (int i = 0; i < rows; i++) {
matrix[i] = (int *)malloc(cols * sizeof(int));
if (matrix[i] == NULL) {
printf("Error al asignar memoria\n");
exit(1);
        }
    }
    return matrix;
}

// Función para rellenar la matriz
void rellenarMatriz(int **matrix, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
matrix[i][j] = i + j;
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int **matrix, int rows, int cols) {
printf("Matriz:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d ", matrix[i][j]);
        }
printf("\n");
    }
}

// Función para liberar la memoria de la matriz
void liberarMatriz(int **matrix, int rows) {
for (int i = 0; i < rows; i++) {
free(matrix[i]);
    }
free(matrix);
}

int main() {
int n, rows, cols;

// Arreglo dinámico
printf("Ingrese el tamaño del arreglo: ");
scanf("%d", &n);
int *arreglo = crearArreglo(n);
rellenarArreglo(arreglo, n);
imprimirArreglo(arreglo, n);
liberarArreglo(arreglo);

// Matriz dinámica
printf("\nIngrese el número de filas y columnas: ");
scanf("%d %d", &rows, &cols);
int **matriz = crearMatriz(rows, cols);
rellenarMatriz(matriz, rows, cols);
imprimirMatriz(matriz, rows, cols);
liberarMatriz(matriz, rows);

    return 0;
}
