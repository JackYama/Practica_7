#include <stdio.h>
#include <stdlib.h>

// Función para verificar si un número es primo
int esPrimo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int m;
    printf("Ingresa un número: ");
    scanf("%d", &m);

    // Crear un array dinámico para almacenar los primos
    int *primos = (int*)malloc(sizeof(int) * m);
    if (primos == NULL) {
        printf("Error de memoria\n");
        return 1;
    }

    int count = 0; // Contador de primos

    for (int i = 2; i <= m; i++) {
        if (esPrimo(i)) {
            primos[count] = i; // Guardar el primo
            count++;
        }
    }

    // Imprimir los primos encontrados
    printf("Números primos hasta %d:\n", m);
    for (int i = 0; i < count; i++) {
        printf("%d ", primos[i]);
    }
    printf("\n");

    free(primos); // Liberar memoria
    return 0;
}
