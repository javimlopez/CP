#include <stdio.h>


int main(){

    /* Unarios: + o -*/
    int i = +5;
    int j = -7;

    /* Binarios: 
        Aditivos: + o -
        Multiplicativos: *, / y % 
    */    

    printf("Suma: %d Resta: %d Multiplicación: %d División: %d Resto: %d", i+j, i-j, i*j, i/j, i%j);

    return 0;
}