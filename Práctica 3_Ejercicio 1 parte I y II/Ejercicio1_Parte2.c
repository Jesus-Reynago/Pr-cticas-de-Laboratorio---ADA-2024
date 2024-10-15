#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <time.h>

// Estructura para almacenar un punto en 2D
typedef struct {
    double x, y;
} Punto;

// Función para comparar puntos según su coordenada x
int compararPuntos(const void *a, const void *b) {
    Punto *puntoA = (Punto *)a;
    Punto *puntoB = (Punto *)b;
    return (puntoA->x > puntoB->x) - (puntoA->x < puntoB->x);
}

// Función para calcular la distancia euclidiana entre dos puntos
double calcularDistancia(Punto p1, Punto p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + 
                (p2.y - p1.y) * (p2.y - p1.y));
}

// Función principal del algoritmo divide y vencerás
double encontrarPuntosCercanos(Punto puntos[], int n, Punto *punto1, Punto *punto2) {
    if (n < 2) {
        return DBL_MAX;
    }
    if (n == 2) {
        *punto1 = puntos[0];
        *punto2 = puntos[1];
        return calcularDistancia(puntos[0], puntos[1]);
    }

    qsort(puntos, n, sizeof(Punto), compararPuntos);

    int mid = n / 2;
    Punto *izquierda = puntos;
    Punto *derecha = puntos + mid;
    int nIzquierda = mid;
    int nDerecha = n - mid;

    Punto punto1Izq, punto2Izq, punto1Der, punto2Der;
    double distanciaIzq = encontrarPuntosCercanos(izquierda, nIzquierda, &punto1Izq, &punto2Izq);
    double distanciaDer = encontrarPuntosCercanos(derecha, nDerecha, &punto1Der, &punto2Der);

    double distanciaMin = fmin(distanciaIzq, distanciaDer);
    if (distanciaMin == distanciaIzq) {
        *punto1 = punto1Izq;
        *punto2 = punto2Izq;
    } else {
        *punto1 = punto1Der;
        *punto2 = punto2Der;
    }

    Punto *strip = (Punto *)malloc(n * sizeof(Punto));
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(puntos[i].x - puntos[mid].x) < distanciaMin) {
            strip[j++] = puntos[i];
        }
    }

    qsort(strip, j, sizeof(Punto), compararPuntos);

    for (int i = 0; i < j; i++) {
        for (int k = i + 1; k < j && (strip[k].y - strip[i].y) < distanciaMin; k++) {
            double distancia = calcularDistancia(strip[i], strip[k]);
            if (distancia < distanciaMin) {
                distanciaMin = distancia;
                *punto1 = strip[i];
                *punto2 = strip[k];
            }
        }
    }

    free(strip);
    return distanciaMin;
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

    // Generar puntos aleatorios
    Punto *puntos = (Punto *)malloc(n * sizeof(Punto));
    for (int i = 0; i < n; i++) {
        puntos[i].x = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
        puntos[i].y = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
    }

    // Medir tiempo de ejecución
    clock_t inicio = clock();  // Iniciar medición del tiempo

    // Encontrar los puntos más cercanos
    Punto punto1, punto2;
    double distancia = encontrarPuntosCercanos(puntos, n, &punto1, &punto2);

    clock_t fin = clock();  // Finalizar medición del tiempo
    double tiempoEjecutado = (double)(fin - inicio) / CLOCKS_PER_SEC;

    // Imprimir resultados
    printf("Punto más cercano 1: (%.2f, %.2f)\n", punto1.x, punto1.y);
    printf("Punto más cercano 2: (%.2f, %.2f)\n", punto2.x, punto2.y);
    printf("Distancia mínima: %.6f\n", distancia);
    printf("Tiempo de ejecución: %.6f segundos\n", tiempoEjecutado);

    free(puntos);
    return 0;
}
