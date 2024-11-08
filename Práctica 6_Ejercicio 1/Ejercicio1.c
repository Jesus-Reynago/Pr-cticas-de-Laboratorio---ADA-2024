#include <stdio.h>

/* Laboratorio 6 - Jesús Reynago Cervantes */

/* Función para encontrar la cantidad máxima de agua que se puede almacenar */
int maxArea(int* height, int n) {
    int izquierda = 0;
    int derecha = n - 1;
    int max_area = 0;

    /* Utilizan dos punteros, uno al principio y otro al final */
    while (izquierda < derecha) {
        // Calcula el área con las dos líneas actuales
        int altura = height[izquierda] < height[derecha] ? height[izquierda] : height[derecha];
        int ancho = derecha - izquierda;
        int area_actual = altura * ancho;

        /* Actualiza el área máxima si el área actual es mayor */
        if (area_actual > max_area) {
            max_area = area_actual;
        }

        /* Mueve el puntero de la línea más pequeña hacia el centro */
        if (height[izquierda] < height[derecha]) {
            izquierda++;
        } else {
            derecha--;
        }
    }

    return max_area;
}

/* Función principal */
int main() {
    int height[] = {4, 7, 9};  // Ejemplo 1
    int n = sizeof(height) / sizeof(height[0]);

    int resultado = maxArea(height, n);
    printf("La máxima cantidad de agua que se puede almacenar es: %d\n", resultado);

    return 0;
}
