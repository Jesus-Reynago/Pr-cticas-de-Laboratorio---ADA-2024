#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Elaborado por: Reynago Cervantes Jesús */

// Función para comparar dos enteros (usada por qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Función para fusionar dos arreglos ordenados
void merge(int nums1[], int m, int nums2[], int n, int merged[]) {
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            merged[k++] = nums1[i++];
        } else {
            merged[k++] = nums2[j++];
        }
    }
    while (i < m) {
        merged[k++] = nums1[i++];
    }
    while (j < n) {
        merged[k++] = nums2[j++];
    }
}

// Función para encontrar la mediana
double findMedian(int merged[], int size) {
    if (size % 2 == 0) {
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    } else {
        return merged[size / 2];
    }
}

int main() {
    int m, n;
    
    // Leer tamaño de los arreglos
    printf("Introduce el tamaño del primer arreglo: ");
    scanf("%d", &m);
    printf("Introduce el tamaño del segundo arreglo: ");
    scanf("%d", &n);
    
    // Validación de restricciones
    if (m < 0 || m > 1000 || n < 0 || n > 1000 || (m + n > 2000)) {
        printf("Error: Las longitudes de los arreglos no cumplen las restricciones.\n");
        return -1;
    }
    
    // Asignación dinámica de memoria para los arreglos
    int *nums1 = (int *)malloc(m * sizeof(int));
    int *nums2 = (int *)malloc(n * sizeof(int));
    int *merged = (int *)malloc((m + n) * sizeof(int));
    
    if (nums1 == NULL || nums2 == NULL || merged == NULL) {
        printf("Error al asignar memoria.\n");
        return -1;
    }
    
    // Leer valores de los arreglos
    printf("Introduce los elementos del primer arreglo:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }
    
    printf("Introduce los elementos del segundo arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // Ordenar los arreglos en caso de que no estén ordenados
    qsort(nums1, m, sizeof(int), compare);
    qsort(nums2, n, sizeof(int), compare);
    
    // Medir el tiempo de ejecución
    clock_t start, end;
    double cpu_time_used;
    
    start = clock(); // Inicio del reloj
    
    // Fusionar los arreglos
    merge(nums1, m, nums2, n, merged);
    
    // Encontrar la mediana
    double mediana = findMedian(merged, m + n);
    
    end = clock(); // Fin del reloj
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Cálculo del tiempo
    
    // Imprimir la mediana y el tiempo de ejecución
    printf("Mediana: %.1f\n", mediana);
    printf("Tiempo de ejecución: %f segundos\n", cpu_time_used);
    
    // Liberar memoria dinámica
    free(nums1);
    free(nums2);
    free(merged);
    
    return 0;
}
