#include <stdio.h>

/* Laboratorio 8 - Reynago Cervantes Jesús */

// Función para contar subarreglos de tamaño `k` cuyo promedio >= `threshold`
int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    int required_sum = k * threshold; // Calcula la suma mínima requerida
    int current_sum = 0; // Suma del subarreglo actual
    int count = 0; // Contador de subarreglos válidos

    // Calcula la suma inicial para los primeros `k` elementos
    for (int i = 0; i < k; i++) {
        current_sum += arr[i];
    }

    // Verifica si el primer subarreglo cumple la condición
    if (current_sum >= required_sum) {
        count++;
    }

    // Usa una ventana deslizante para procesar el resto del arreglo
    for (int i = k; i < arrSize; i++) {
        current_sum += arr[i] - arr[i - k]; // Actualiza la suma
        if (current_sum >= required_sum) { // Verifica la condición
            count++;
        }
    }

    return count; // Retorna el número de subarreglos válidos
}

int main() {
    // Caso de prueba 1: Prueba un arreglo con valores repetidos y valores mayores
    int arr1[] = {2, 2, 2, 2, 5, 5, 5, 8};
    int result1 = numOfSubarrays(arr1, 8, 3, 4); // Llama a la función con k=3 y threshold=4
    printf("Output: %d\n", result1); // Imprime el resultado (esperado: 3)

    // Caso de prueba 2: Prueba un arreglo con valores primos variados
    int arr2[] = {11, 13, 17, 23, 29, 31, 7, 5, 2, 3};
    int result2 = numOfSubarrays(arr2, 10, 3, 5); // Llama a la función con k=3 y threshold=5
    printf("Output: %d\n", result2); // Imprime el resultado (esperado: 6)

    return 0; // Fin del programa
}
