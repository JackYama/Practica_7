#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función de comparación para qsort


// Función para imprimir un array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n;
    int *array;

  array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error al reservar memoria");
        return 1;
    }

    if (argc == 1) {
        n = atoi(argv[1]); // Convertir el primer argumento a entero
    } else {
        // Pedir al usuario el número de enteros
        printf("Introduce el número de enteros que quieres ordenar: ");
        scanf("%d", &n);
    }

    if (n <= 0) {
        printf("Dato introducido no valido, introduce un entero mayor que cero.\n");
        return 1;
    }

    // Leer valores del usuario o de los argumentos de línea de comandos
    if (argc == 2) {
        // Leer valores desde los argumentos de línea de comandos
        if (argc < n) {
            printf("Datos introducidos no validos, introduce solo un entero");
            free(array);
            return 1;
        }
        for (int i = 0; i < n; i++) {
            array[i] = atoi(argv[2]);
        }
    } else {
        // Leer valores desde la entrada estándar
        printf("Introduce los %d enteros:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
    }


    // Liberar memoria dinámica
    free(array);

    return 0;
}
