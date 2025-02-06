#include <stdio.h>
#include <string.h>

int es_palindromo(char cadena[]) {
    int i, len = strlen(cadena); // con esto leemos la longitud de cadena
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
    scanf("%s", cadena);//esto guarda la cantidad que se introduce en cadena
    
    if (es_palindromo(cadena)) {// llamada a la funcion es palindromo realizada
        printf("La cadena es un palíndromo.\n");
    } else {
        printf("La cadena no es un palíndromo.\n");
    }
    
    return 0;
}
