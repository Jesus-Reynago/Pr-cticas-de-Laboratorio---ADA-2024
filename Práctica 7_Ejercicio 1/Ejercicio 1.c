#include <stdio.h>
#include <string.h>

/* Laboratorio 7 - Reynago Cervantes Jesús */

/* Función para comprimir una cadena contando las repeticiones consecutivas de caracteres */
void compress(char* word, char* comp) {
    int length = strlen(word);  /* Longitud de la palabra original */
    int i = 0, j = 0;  /* Índices para la palabra original (i) y la cadena comprimida (j) */
    
    while (i < length) {
        char current_char = word[i];  /* Carácter actual */
        int count = 1;  /* Contador de repeticiones */
        
        /* Cuenta cuántas veces se repite el carácter consecutivamente (máximo 9 veces) */
        while (i + count < length && word[i + count] == current_char && count < 9) {
            count++;
        }
        
        /* Formatea y añade la cantidad de repeticiones seguida del carácter a la cadena comprimida */
        j += sprintf(&comp[j], "%d%c", count, current_char);
        
        /* Avanza el índice para saltar las repeticiones */
        i += count;
    }
    
    comp[j] = '\0';  /* Termina la cadena comprimida con un carácter nulo */
}

/* Función principal */
int main() {
    char word[] = "pppppppppppprrrssssaaa";  /* Cadena de entrada */
    char comp[100];  /* Arreglo para almacenar la cadena comprimida */
    
    compress(word, comp);  /* Llama a la función de compresión */
    
    printf("Compressed: %s\n", comp);  /* Muestra el resultado comprimido */
    
    return 0;
}
