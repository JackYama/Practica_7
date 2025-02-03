#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SIZE 10

void limpiarPantalla() {
    system("clear");
}

typedef struct {
    int x, y;
} Posicion;

void inicializarTablero(char **tablero, int filas, int columnas, Posicion *pos) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1) {
                tablero[i][j] = '*';
            } else {
                tablero[i][j] = ' ';
            }
        }
    }
    pos->x = filas / 2;
    pos->y = columnas / 2;
    tablero[pos->x][pos->y] = '#';
}

void imprimirTablero(char **tablero, int filas, int columnas) {
    limpiarPantalla();
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

void moverJugador(char **tablero, int filas, int columnas, Posicion *pos, char direccion) {
    int nuevaX = pos->x;
    int nuevaY = pos->y;

    switch (direccion) {
        case 'w': nuevaX--; break;
        case 's': nuevaX++; break;
        case 'a': nuevaY--; break;
        case 'd': nuevaY++; break;
        default: return;
    }
    
    if (nuevaX > 0 && nuevaX < filas - 1 && nuevaY > 0 && nuevaY < columnas - 1) {
        tablero[pos->x][pos->y] = ' ';
        pos->x = nuevaX;
        pos->y = nuevaY;
        tablero[pos->x][pos->y] = '#';
    }
}

int main(int argc, char *argv[]) {
    int filas = DEFAULT_SIZE, columnas = DEFAULT_SIZE;
    if (argc == 2) {
        filas = columnas = atoi(argv[1]);
    } else if (argc == 3) {
        filas = atoi(argv[1]);
        columnas = atoi(argv[2]);
    }

    char **tablero = malloc(filas * sizeof(char *));
    for (int i = 0; i < filas; i++) {
        tablero[i] = malloc(columnas * sizeof(char));
    }
    
    Posicion pos;
    inicializarTablero(tablero, filas, columnas, &pos);

    char entrada;
    do {
        imprimirTablero(tablero, filas, columnas);
        printf("Usa 'w', 'a', 's', 'd' para mover, 'q' para salir: ");
        scanf(" %c", &entrada);
        moverJugador(tablero, filas, columnas, &pos, entrada);
    } while (entrada != 'q');

    for (int i = 0; i < filas; i++) {
        free(tablero[i]);
    }
    free(tablero);

    return 0;
}
