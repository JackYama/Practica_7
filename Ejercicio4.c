#include <stdio.h>
#include <string.h>

/*Un palíndromo es una palabra, frase, número o secuencia de caracteres 
que se lee igual de izquierda a derecha que de derecha a izquierda, 
ignorando espacios, signos de puntuación y mayúsculas/minúsculas.*/

// Función recursiva para verificar si una cadena es palíndroma.
int esPalindromoRec(const char *str, int inicio, int fin) {
    if (inicio >= fin) return 1;  // Caso base: es palíndromo
    if (str[inicio] != str[fin]) return 0;  // Si no coinciden, no es palíndromo
    return esPalindromoRec(str, inicio + 1, fin - 1);  // Llamada recursiva
}

int esPalindromo(const char *str) {
    int len = strlen(str);
    return esPalindromoRec(str, 0, len - 1);
}

int main() {
    char *cadena = "radar";
    if (esPalindromo(cadena))
        printf("\"%s\" es palíndroma.\n", cadena);
    else
        printf("\"%s\" no es palíndroma.\n", cadena);
    return 0;
}

