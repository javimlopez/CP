#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fent = fopen("fichero.txt", "r");
    if (fent = NULL) {
        perror("Error abriendo fichero.txt");
    }

    /*
        La variable errno contiene un número indicando el último error registrado (en funciones de E/S o llamadas al sistema)
    */

    /*
        perror (char * mensaje)
        Imprime el mensaje seguido del error asociado a la vriable errno
    */

    return 0;
}