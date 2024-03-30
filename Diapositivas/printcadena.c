#include <stdio.h>
#include <stdlib.h>

int main(){

    /* int sprintf(char *cadena, char *formato, arg1, arg2, arg3, ...); 

        Realiza las mismas conversiones que printf pero almacena la salida en una cadena.
        Devuelve:
           - Número negativo si algo va mal
           - Número total de caracteres escritos en cadena si todo va bien
        
    */
    char cadena[5];
    sprintf(cadena, "Hola");
    printf(cadena);
    return 0;
}