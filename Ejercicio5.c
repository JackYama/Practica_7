#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m; // Variables para almacenar el número de filas y columnas
    
    // Pedimos al usuario las dimensiones de la matriz
    printf("Introduce el número de filas: ");
    scanf("%d", &n);
    printf("Introduce el número de columnas: ");
    scanf("%d", &m);
    
    // Declaramos una matriz de tamaño n x m
    int matriz[n][m]; 
    
    // Llenamos la matriz con la suma de sus índices (i + j)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = i + j; // El valor de cada celda será la suma de sus índices
        }
    }
    
    // Mostrar la matriz generada
    printf("Matriz generada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]); // Imprime cada valor de la matriz
        }
        printf("\n"); // Salto de línea al final de cada fila
    }
    
    // Calcular la suma de los elementos del contorno de la matriz
    int suma = 0;

    // Sumar los elementos de la primera y última fila
    for (int j = 0; j < m; j++) {
        suma += matriz[0][j]; // Suma los elementos de la primera fila
        if (n > 1) suma += matriz[n-1][j]; // Suma los elementos de la última fila (si hay más de una fila)
    }

    // Sumar los elementos de la primera y última columna (evitando esquinas repetidas)
    for (int i = 1; i < n - 1; i++) { 
        suma += matriz[i][0]; // Suma los elementos de la primera columna
        if (m > 1) suma += matriz[i][m-1]; // Suma los elementos de la última columna (si hay más de una columna)
    }
    
    // Imprimir el resultado de la suma del contorno
    printf("Suma del contorno: %d\n", suma);
    
    return 0;
}
