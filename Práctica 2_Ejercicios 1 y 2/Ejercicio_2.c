#include <stdio.h>
#include <time.h>

/* Elaborado por: Reynago Cervantes Jesús */

// Función recursiva para calcular Fibonacci
long long fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Función principal
int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    // Solicitar el valor de 'n'
    printf("Introduce un valor para n: ");
    scanf("%d", &n);

    // Medir el tiempo de ejecución
    start = clock();
    long long result = fibonacci(n);
    end = clock();

    // Calcular el tiempo total en milisegundos
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;

    // Mostrar el resultado y el tiempo
    printf("Fibonacci(%d) = %lld\n", n, result);
    printf("Tiempo de ejecución: %lf ms\n", cpu_time_used);

    return 0;
}
