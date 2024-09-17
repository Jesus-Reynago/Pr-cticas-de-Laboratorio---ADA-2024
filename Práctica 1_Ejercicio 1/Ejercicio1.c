#include <stdio.h>
#include <stdlib.h>

/* DECLARAR FUNCIOONES */
void insertionsort(int b[], int n);
void removeDuplicatesAndReorganize(int b[], int n, int *uniqueCount);

/* FUNCION PARA ORDENAR UN AREEGLO POR INSERCION */
void insertionsort(int b[], int n)
{
    int i, j, key;
    
    for(j = 1; j < n; j++)
    {
        key = b[j];
        i = j - 1;
        
        while(i >= 0 && b[i] > key)
        {
            b[i + 1] = b[i];
            i = i - 1;
        }
        b[i + 1] = key;
    }
    
    printf("\nLa matriz ordenada es:\n");
    for(i = 0; i < n; i++){
        printf("%d | ", b[i]);    
    }
    printf("\n");
}

/* FUNCION PARA ELIMINAR LOS DUPLICADOS Y REORGANIZAR EL ARREGLO */
void removeDuplicatesAndReorganize(int b[], int n, int *uniqueCount)
{
    int i, j;
    int duplicatesCount = 0;

    // ELIMINAR LOS DUPLICADOS Y CONTAR LOS DUPLICADOS
    *uniqueCount = 0;
    for (i = 0; i < n; i++)
    {
        if (i == 0 || b[i] != b[i - 1])
        {
            b[*uniqueCount] = b[i];
            (*uniqueCount)++;
        }
    }
    
    // CONTAR EL NUMERO DE DUPLICADOS
    for (i = 0; i < n; i++)
    {
        if (i == 0 || b[i] != b[i - 1])
        {
            for (j = i + 1; j < n; j++)
            {
                if (b[j] == b[i])
                {
                    b[*uniqueCount + duplicatesCount] = b[j];
                    duplicatesCount++;
                }
            }
        }
    }
    
    // RELLENAR EL RESTO DEL ARREGLO CON LA BASURA DE ELEMENTOS ELIMINADOS
    for (i = *uniqueCount + duplicatesCount; i < n; i++)
    {
        b[i] = -1; // USAMOS -1 O CUALQUIER VALOR CONTENIDO EN LA BASURA PARA CUMPLIR CON LO INDICADO
    }

    // MOSTRAR EL ARREGLO CON LOS VALORES UNICOS SEGUIDOS DE LOS DUPLICADOS
    printf("\nNuevo arreglo:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d | ", b[i]);    
    }
    printf("\n");
}

/* FUNCION PRINCIPAL DEL PROGRAMA */
int main(int argc, char *argv[])
{
    int i, n, *b, uniqueCount;
    
    printf("Asigna el tamaño del arreglo dinámico: \n");
    scanf("%d", &n);
    
    b = (int*)malloc(n * sizeof(int));
    
    if(b == NULL)
    {
        printf("Error al asignar memoria.");
        return 1; 
    }
    
    /* SOLICITAR LOS NUMEROS AL USUARIO */
    printf("Introduce los números del arreglo:\n");
    for(i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &b[i]);
    }
    
    /* ORDENAR EL ARREGLO POR INSERTION */
    insertionsort(b, n);
    
    /* ELIMINAR LOS DUPLICADOS Y REORGANIZAR EL ARREGLO */
    removeDuplicatesAndReorganize(b, n, &uniqueCount);
    
    /* MOSTRAR LA CANTIDAD DE VALORES UNICOS */
    printf("Cantidad de valores únicos: %d\n", uniqueCount);
    
    /* LIBERAR MEMORIA */
    free(b);
  
    return 0;
}
