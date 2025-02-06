#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("Introduce el número de filas: ");
    scanf("%d", &n);
    printf("Introduce el número de columnas: ");
    scanf("%d", &m);
    
    int matriz[n][m];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matriz[i][j] = i + j; 
        }
    }
    
    // Mostrar la matriz
    printf("Matriz generada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    
    // Calcular la suma del contorno
    int suma = 0;
    for (int j = 0; j < m; j++) {
        suma += matriz[0][j]; // Primera fila
        if (n > 1) suma += matriz[n-1][j]; // Última fila
    }
    for (int i = 1; i < n - 1; i++) {
        suma += matriz[i][0]; // Primera columna
        if (m > 1) suma += matriz[i][m-1]; // Última columna
    }
    
    printf("Suma del contorno: %d\n", suma);
    
    return 0;
}
