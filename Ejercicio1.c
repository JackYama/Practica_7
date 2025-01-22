#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Función de comparación para qsort
void ordenarnums(int * arr3, int n2){
    int cambio;
    for (int i = 0; i < n2 ; i++){
        for (int j = 0; j < n2-1 ; j++){
            if(arr3[i] > arr3[j]){
            cambio == arr3[i];
            arr3[i] == arr3[j];
            arr3[j] == cambio;
            }
        }
    }
}


// Función para imprimir un array
void printArray(int *arr1, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n1;
    int * arr2;
    
  arr2 = (int *)malloc(n1 * sizeof(int));
    if (arr2 == NULL) {
        printf("Error al reservar memoria");
        return 1;
    }

    if (argc == 1) {
        n1 = atoi(argv[1]); // Convertir el primer argumento a entero
    } else {
        // Pedir al usuario el número de enteros
        printf("Introduce el número de enteros que quieres ordenar: ");
        scanf("%d", &n1);
    }

    if (n1 <= 0) {
        printf("Dato introducido no valido, introduce un entero mayor que cero.\n");
        return 1;
    }

    // Leer valores del usuario o de los argumentos de línea de comandos
    if (argc == 2) {
        // Leer valores desde los argumentos de línea de comandos
        if (argc < n1) {
            printf("Datos introducidos no validos, introduce solo un entero");
            free(arr2);
            return 1;
        }
        for (int i = 0; i < n1; i++) {
            arr2[i] = atoi(argv[2]);
        }
    } else {
        // Leer valores desde la entrada estándar
        printf("Introduce los %d enteros:\n", n1);
        for (int i = 0; i < n1; i++) {
            scanf("%d", &arr2[i]);
        }
    }
    printf("Cadena ordenada");
    ordenarnums(arr2,n1);

    // Liberar memoria dinámica
    free(arr2);

    return 0;
}
