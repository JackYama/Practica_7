#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*En criptografía, el cifrado César, también conocido como 
cifrado por desplazamiento, código de César o desplazamiento de 
César, es una de las técnicas de cifrado más simples y más usadas.
Es un tipo de cifrado por sustitución en el que una letra en el 
texto original es reemplazada por otra letra que se encuentra un 
número fijo de posiciones más adelante en el alfabeto. Por ejemplo,
con un desplazamiento de 3, la A sería sustituida por la D (situada
3 lugares a la derecha de la A), la B sería reemplazada por la E, etc.(Wikipedia)*/


void cifrar(char *texto, int clave) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z')) {
            texto[i] = (texto[i] - 'a' + clave) % 26 + 'a';
        } else if ((texto[i] >= 'A' && texto[i] <= 'Z')) {
            texto[i] = (texto[i] - 'A' + clave) % 26 + 'A';
        }
    }
}

int main() {
    char texto[100];
    int clave;

    // Leer texto y clave
    printf("Introduce el texto: ");
    fgets(texto, 100, stdin);
    
    printf("Introduce la clave de desplazamiento: ");
    scanf("%d", &clave);

    // Cifrado
    cifrar(texto, clave);
    printf("Texto cifrado: %s", texto);

    // Descifrado
    cifrar(texto, -clave);
    printf("Texto descifrado: %s", texto);

    return 0;
}

/* Alternativa:

int main() {
    char texto[100];
    int clave;

    // Leer texto y clave
    printf("Introduce el texto: ");
    fgets(texto, 100, stdin);
    printf("Introduce la clave: ");
    scanf("%d", &clave);

    Cifrado
    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z'))
            texto[i] = (texto[i] - 'a' + clave) % 26 + 'a';
        else if ((texto[i] >= 'A' && texto[i] <= 'Z'))
            texto[i] = (texto[i] - 'A' + clave) % 26 + 'A';
    }

    printf("Texto cifrado: %s", texto);

    Descifrado
    for (int i = 0; texto[i] != '\0'; i++) {
        if ((texto[i] >= 'a' && texto[i] <= 'z'))
            texto[i] = (texto[i] - 'a' - clave + 26) % 26 + 'a';
        else if ((texto[i] >= 'A' && texto[i] <= 'Z'))
            texto[i] = (texto[i] - 'A' - clave + 26) % 26 + 'A';
    }

    printf("Texto descifrado: %s", texto);

    return 0;
}
*/