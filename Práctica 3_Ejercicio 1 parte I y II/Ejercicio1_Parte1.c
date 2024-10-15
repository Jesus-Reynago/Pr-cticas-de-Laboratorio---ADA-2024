#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <float.h>

// Estructura para almacenar un punto en 2D
typedef struct {
    double x, y;
} Punto;

// Función para generar puntos aleatorios
void generarPuntos(Punto puntos[], int n) {
    for (int i = 0; i < n; i++) {
        puntos[i].x = ((double) rand() / RAND_MAX) * 200.0 - 100.0; // Rango de -100 a 100
        puntos[i].y = ((double) rand() / RAND_MAX) * 200.0 - 100.0;
    }
}

// Función para calcular la distancia euclidiana entre dos puntos
double calcularDistancia(Punto p1, Punto p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

// Función para encontrar el par de puntos más cercano
void encontrarPuntosCercanos(Punto puntos[], int n, Punto *punto1, Punto *punto2) {
    double minDistancia = DBL_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distancia = calcularDistancia(puntos[i], puntos[j]);
            if (distancia < minDistancia) {
                minDistancia = distancia;
                *punto1 = puntos[i];
                *punto2 = puntos[j];
            }
        }
    }
}

int main() {
    int n;
    
    // Solicitar al usuario que ingrese la cantidad de puntos
    printf("Ingrese la cantidad de puntos a generar: ");
    scanf("%d", &n);
    
    // Verificar que la cantidad de puntos sea válida
    if (n < 2) {
        printf("Debe generar al menos 2 puntos.\n");
        return 1;
    }

    Punto *puntos = (Punto*) malloc(n * sizeof(Punto));
    Punto punto1, punto2;
    
    // Generar puntos aleatorios
    generarPuntos(puntos, n);
    
    // Medir tiempo de ejecución
    clock_t inicio = clock();
    
    // Encontrar los puntos más cercanos
    encontrarPuntosCercanos(puntos, n, &punto1, &punto2);
    
    clock_t fin = clock();
    double tiempoEjecutado = (double)(fin - inicio) / CLOCKS_PER_SEC;
    
    printf("Punto más cercano 1: (%.2f, %.2f)\n", punto1.x, punto1.y);
    printf("Punto más cercano 2: (%.2f, %.2f)\n", punto2.x, punto2.y);
    printf("Tiempo de ejecución: %.6f segundos\n", tiempoEjecutado);
    
    free(puntos);
    
    return 0;
}
