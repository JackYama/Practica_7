#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void imp_nums(entero *Biblio_int){
 for (int i = 0; i < n; i++) {
        printf("%d ", [i]);
    }
   
}

int main(int argc, char **argv){

	int entero;
	int * Biblio_int;

	   Biblio_int = (int *)malloc(Biblio_int * sizeof(int));
    if ( Biblio_int == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
	}
    printf("Arguments list:\n");
    for (int i = 0; i < argc; i++) {
        printf("\t Argument %d: %s\n", i, argv[i]);
    }

//Los ifs funcionan agregandole argumentos, en este caso y generalmente con relación entre lo que hacen y el nombre
    if (argc == 1) {
  
    } 

    if(argc == 2) {
        if (strcmp(argv[1], "show") == 0) {
            
        }
        if (strcmp(argv[1], "add") == 0) {
           }

        if(strcmp(argv[1], "all") == 0) {
        }

    }

 // Imprimir el array ordenado

    printf("Array ordenado: ");
    printArray(Biblio_int, entero);
    

    free(Biblio_int);

    return 0;
}