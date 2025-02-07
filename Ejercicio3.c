#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define POR_DEFECTO 10

// Funcion para limpiar la pantalla (solo funciona en sistemas tipo Unix/Linux)
void limpiarPantalla() {
    system("clear");
}

// Estructura para manejar la posicion del jugador
typedef struct {
    int fila, columna;
} PosicionJugador;

// Funcion para inicializar el tablero con bordes y colocar el jugador en el centro
void inicializarTablero(char **tablero, int filas, int columnas, PosicionJugador *jugador) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (i == 0 || i == filas - 1 || j == 0 || j == columnas - 1) {
                tablero[i][j] = '*';  // Borde del tablero
            } else {
                tablero[i][j] = ' ';  // Espacio vacio dentro del tablero
            }
        }
    }
    // Coloca el jugador en el centro del tablero
    jugador->fila = filas / 2;
    jugador->columna = columnas / 2;
    tablero[jugador->fila][jugador->columna] = '#'; // Posicion inicial del jugador
}

// Funcion para imprimir el tablero en pantalla
void imprimirTablero(char **tablero, int filas, int columnas) {
    limpiarPantalla();
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%c ", tablero[i][j]);
        }
        printf("\n");
    }
}

// Funcion para mover al jugador en el tablero sin que se salga de los bordes
void moverJugador(char **tablero, int filas, int columnas, PosicionJugador *jugador, char direccion) {
    int nuevaFila = jugador->fila;
    int nuevaColumna = jugador->columna;
    
    // Determina la nueva posicion basada en la tecla presionada
    switch (direccion) {
        case 'w': nuevaFila--; break;   // Mover arriba
        case 's': nuevaFila++; break;   // Mover abajo
        case 'a': nuevaColumna--; break; // Mover izquierda
        case 'd': nuevaColumna++; break; // Mover derecha
        default: return;  // No hacer nada si la tecla no es valida
    }
    
    // Verifica si la nueva posicion esta dentro de los limites del area jugable
    if (nuevaFila > 0 && nuevaFila < filas - 1 && nuevaColumna > 0 && nuevaColumna < columnas - 1) {
        tablero[jugador->fila][jugador->columna] = ' ';  // Borra la posicion anterior del jugador
        jugador->fila = nuevaFila;
        jugador->columna = nuevaColumna;
        tablero[jugador->fila][jugador->columna] = '#';  // Coloca al jugador en la nueva posicion
    }
}

int main(int argc, char *argv[]) {
    int filas = POR_DEFECTO, columnas = POR_DEFECTO;
    
    // Permite definir el tamano del tablero desde la linea de comandos
    if (argc == 2) {
        filas = columnas = atoi(argv[1]); // Si se pasa un solo argumento, se usa para ambas dimensiones
    } else if (argc == 3) {
        filas = atoi(argv[1]);
        columnas = atoi(argv[2]); // Si se pasan dos argumentos, se usan como filas y columnas
    }
    
    // Reserva memoria para el tablero dinamicamente
    char **tablero = malloc(filas * sizeof(char *));
    for (int i = 0; i < filas; i++) {
        tablero[i] = malloc(columnas * sizeof(char));
    }
    
    // Inicializa la posicion del jugador y el tablero
    PosicionJugador jugador;
    inicializarTablero(tablero, filas, columnas, &jugador);
    
    char entrada;
    do {
        imprimirTablero(tablero, filas, columnas);
        printf("Usa 'w', 'a', 's', 'd' para mover, 'q' para salir: ");
        scanf(" %c", &entrada);
        moverJugador(tablero, filas, columnas, &jugador, entrada);
    } while (entrada != 'q'); // El bucle continua hasta que el usuario presione 'q'
    
    // Libera la memoria asignada al tablero para evitar fugas de memoria
    for (int i = 0; i < filas; i++) {
        free(tablero[i]);
    }
    free(tablero);
    
    return 0;
}
