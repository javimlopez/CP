#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argvc, char * argv[]) {

    /*
        fflush(stdout) vacía el buffer intermedio cada vez que se realiza una llamada de E/S
        Se puede utilizar cada vez que se realiza una operación de E/S: fflush(stdout);

        Si no la utilizas y el programa "muere" o se bloquea, es posible que no veas algunos mensajes previos hechos con printf
    */

    printf("Hola, mundo"); /* funcion c de E/S */
    write(1, "Adios, mundo", 13); /* llamada al sistema */

    return 0;
}