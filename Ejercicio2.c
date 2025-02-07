#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definimos el struct Estudiante
typedef struct {
    char nombre[50];   // Nombre del estudiante
    char apellido[50]; // Apellido del estudiante
    float nota;        // Nota del estudiante
} Estudiante;

// Función para ordenar por nota (de mayor a menor)
void ordenarPorNota(Estudiante *estudiantes, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (estudiantes[j].nota < estudiantes[j + 1].nota) {
                Estudiante temp = estudiantes[j];  
                estudiantes[j] = estudiantes[j + 1]; 
                estudiantes[j + 1] = temp;           
            }
}

// Función para ordenar por apellido (orden alfabético)
void ordenarPorApellido(Estudiante *estudiantes, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcmp(estudiantes[j].apellido, estudiantes[j + 1].apellido) > 0) {
                Estudiante temp = estudiantes[j];    
                estudiantes[j] = estudiantes[j + 1]; 
                estudiantes[j + 1] = temp;           
            }
}

int main() {
    int n;
    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &n); // Leemos el número de estudiantes

    // Reservamos memoria para los estudiantes
    Estudiante *estudiantes = malloc(n * sizeof(Estudiante));
    if (!estudiantes) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    // Leemos los datos de los estudiantes
    for (int i = 0; i < n; i++) {
        printf("\nEstudiante %d\n", i + 1); // i+1 para que empiece en 1 y no en 0

        printf("Nombre: ");
        scanf(" %[^\n]", estudiantes[i].nombre); // Leemos toda la línea hasta el salto de línea

        printf("Apellido: ");
        scanf(" %[^\n]", estudiantes[i].apellido); // Igual que en nombre

        printf("Nota: ");
        scanf("%f", &estudiantes[i].nota); // Leemos la nota
    }

    // Ordenamos los estudiantes por nota, de mayor a menor
    ordenarPorNota(estudiantes, n);
    printf("\nEstudiantes ordenados por nota:\n");
    for (int i = 0; i < n; i++)
        printf("%s %s - Nota: %.2f\n", estudiantes[i].nombre, estudiantes[i].apellido, estudiantes[i].nota);

    // Ordenamos los estudiantes por apellido, de forma alfabética
    ordenarPorApellido(estudiantes, n);
    printf("\nEstudiantes ordenados por apellido:\n");
    for (int i = 0; i < n; i++)
        printf("%s %s - Nota: %.2f\n", estudiantes[i].nombre, estudiantes[i].apellido, estudiantes[i].nota);

    // Liberamos la memoria reservada para los estudiantes
    free(estudiantes);
    return 0;
}
