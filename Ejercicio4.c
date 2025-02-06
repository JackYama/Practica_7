#include <stdio.h>
#include <string.h>

int es_palindromo(char cadena[]) {
    int i, len = strlen(cadena);
    for (i = 0; i < len / 2; i++) {
        if (cadena[i] != cadena[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char cadena[100];
    printf("Introduce una cadena: ");
    scanf("%s", cadena);
    
    if (es_palindromo(cadena)) {
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena no es un palíndromo.\n");
    }
    
    return 0;
}
