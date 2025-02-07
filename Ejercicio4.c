#include <stdio.h>
#include <string.h>

/* Un palíndromo es una palabra, frase, número o secuencia de caracteres 
   que se lee igual de izquierda a derecha que de derecha a izquierda, 
   ignorando espacios, signos de puntuación y mayúsculas/minúsculas. */

// Compara los caracteres en las posiciones 'inicio' y 'fin' de la cadena.
// Si son iguales, llama recursivamente a la función para verificar los siguientes caracteres.
int esPalindromoRec(const char *str, int inicio, int fin) {
    if (inicio >= fin) return 1;  // Caso base: Si el índice de inicio es mayor o igual que fin, es palíndromo
    if (str[inicio] != str[fin]) return 0;  // Si los caracteres en 'inicio' y 'fin' no coinciden, no es palíndromo
    return esPalindromoRec(str, inicio + 1, fin - 1);  // Llamada recursiva a la función
}

// Función que recibe una cadena y llama a la función recursiva para verificar si es palíndroma.
// Se pasa la longitud de la cadena para ajustar el índice final.
int esPalindromo(const char *str) {
    return esPalindromoRec(str, 0, strlen(str) - 1);  // Llama a la función recursiva con el índice de inicio y fin adecuados
}

int main() {
    char cadena[100];  // Array para almacenar la cadena ingresada por el usuario

    printf("Introduce una palabra: ");
    scanf("%s", cadena);  // Leemos la palabra ingresada por el usuario (solo palabras simples)

    // Usamos un operador ternario para verificar si la palabra es palíndroma
    // Imprimimos "es palíndroma" si es cierto, y "no es palíndroma" si es falso.
    printf("\"%s\" %s palíndroma.\n", cadena, esPalindromo(cadena) ? "es" : "no es");

    return 0;
}
