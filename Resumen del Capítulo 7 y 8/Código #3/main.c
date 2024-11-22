#include <stdio.h>
#include <stdlib.h>

// Declaración de funciones
int **allocateMatrix(int rows, int cols);
void fillMatrix(int **matrix, int rows, int cols);
void printMatrix(int **matrix, int rows, int cols);
void freeMatrix(int **matrix, int rows);

int main() {
int rows, cols;

printf("Ingrese el número de filas y columnas: ");
scanf("%d %d", &rows, &cols);

// Asignar memoria para la matriz
int **matrix = allocateMatrix(rows, cols);
if (matrix == NULL) {
printf("Error al asignar memoria\n");
return 1;
    }

// Rellenar la matriz
fillMatrix(matrix, rows, cols);

// Imprimir la matriz
printf("Matriz:\n");
printMatrix(matrix, rows, cols);

// Liberar memoria
freeMatrix(matrix, rows);

return 0;
}

// Función para asignar memoria para la matriz
int **allocateMatrix(int rows, int cols) {
int **matrix = (int **)malloc(rows * sizeof(int *));
if (matrix == NULL) {
return NULL;
    }
for (int i = 0; i < rows; i++) {
matrix[i] = (int *)malloc(cols * sizeof(int));
if (matrix[i] == NULL) {
for (int j = 0; j < i; j++) {
free(matrix[j]);
            }
            free(matrix);
            return NULL;
        }
    }
    return matrix;
}

// Función para rellenar la matriz
void fillMatrix(int **matrix, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
matrix[i][j] = i + j;
        }
    }
}

// Función para imprimir la matriz
void printMatrix(int **matrix, int rows, int cols) {
for (int i = 0; i < rows; i++) {
for (int j = 0; j < cols; j++) {
printf("%d ", matrix[i][j]);
        }
printf("\n");
    }
}

// Función para liberar la memoria de la matriz
void freeMatrix(int **matrix, int rows) {
for (int i = 0; i < rows; i++) {
free(matrix[i]);
    }
free(matrix);
}
