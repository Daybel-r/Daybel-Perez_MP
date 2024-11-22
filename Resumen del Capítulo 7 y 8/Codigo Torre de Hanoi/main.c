#include <stdio.h>
#include <stdlib.h>

// Funci�n para crear un arreglo din�mico
int *crearArreglo(int n) {
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf("Error al asignar memoria\n");
exit(1); // Finalizar el programa en caso de error
    }
    return arr;
}

// Funci�n para rellenar el arreglo
void rellenarArreglo(int *arr, int n) {
for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Funci�n para imprimir el arreglo
void imprimirArreglo(int *arr, int n) {
printf("Elementos del arreglo: ");
for (int i = 0; i < n; i++) {
printf("%d ", arr[i]);
    }
printf("\n");
}

// Funci�n para liberar el arreglo
void liberarArreglo(int *arr) {
free(arr);
}

// Funci�n para crear una matriz din�mica
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

// Funci�n para rellenar la matriz
void rellenarMatriz(int **matrix, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
matrix[i][j] = i + j;
        }
    }
}

// Funci�n para imprimir la matriz
void imprimirMatriz(int **matrix, int rows, int cols) {
printf("Matriz:\n");
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d ", matrix[i][j]);
        }
printf("\n");
    }
}

// Funci�n para liberar la memoria de la matriz
void liberarMatriz(int **matrix, int rows) {
for (int i = 0; i < rows; i++) {
free(matrix[i]);
    }
free(matrix);
}

int main() {
int n, rows, cols;

// Arreglo din�mico
printf("Ingrese el tama�o del arreglo: ");
scanf("%d", &n);
int *arreglo = crearArreglo(n);
rellenarArreglo(arreglo, n);
imprimirArreglo(arreglo, n);
liberarArreglo(arreglo);

// Matriz din�mica
printf("\nIngrese el n�mero de filas y columnas: ");
scanf("%d %d", &rows, &cols);
int **matriz = crearMatriz(rows, cols);
rellenarMatriz(matriz, rows, cols);
imprimirMatriz(matriz, rows, cols);
liberarMatriz(matriz, rows);

    return 0;
}
