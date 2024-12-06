#include <stdio.h>
#include <stdlib.h>

/* Laboratorio 9 - Reynago Cervantes Jesús */

// Función para generar el triángulo de Pascal
int** generate(int numRows, int** returnSize) {
    // Asignar memoria para el triángulo de Pascal
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    *returnSize = (int*)malloc(numRows * sizeof(int)); // Asignar memoria para guardar el tamaño de cada fila

    for (int row_num = 0; row_num < numRows; row_num++) {
        // Asignar memoria para cada fila en el triángulo
        triangle[row_num] = (int*)malloc((row_num + 1) * sizeof(int));

        // El primer y el último elemento de cada fila son 1
        triangle[row_num][0] = 1;
        triangle[row_num][row_num] = 1;

        // Guardar el tamaño de la fila actual
        (*returnSize)[row_num] = row_num + 1;

        // Calcular los valores intermedios de la fila usando la suma de elementos de la fila anterior
        for (int j = 1; j < row_num; j++) {
            triangle[row_num][j] = triangle[row_num - 1][j - 1] + triangle[row_num - 1][j];
        }
    }

    return triangle; // Retornar el triángulo generado
}

// Función para liberar la memoria asignada al triángulo de Pascal
void freeTriangle(int** triangle, int numRows) {
    // Liberar cada fila de memoria
    for (int i = 0; i < numRows; i++) {
        free(triangle[i]);
    }

    // Liberar el arreglo principal de filas
    free(triangle);
}

int main() {
    int numRows = 5; // Número de filas del triángulo de Pascal
    int* returnSize; // Arreglo para almacenar el tamaño de cada fila

    // Generar el triángulo de Pascal
    int** triangle = generate(numRows, &returnSize);

    // Imprimir el triángulo de Pascal
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < returnSize[i]; j++) {
            printf("%d ", triangle[i][j]); // Imprimir cada elemento de la fila
        }
        printf("\n"); // Nueva línea después de imprimir cada fila
    }

    // Liberar la memoria asignada
    freeTriangle(triangle, numRows); // Liberar memoria del triángulo
    free(returnSize); // Liberar memoria del arreglo de tamaños de filas

    return 0; // Fin del programa
}
