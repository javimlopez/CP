#include <stdio.h>
#include <stdlib.h>


int main() {

    /*
        Precisión: Un . seguido de un número y depende del carácter de conversión utilizado
        d,i,o,u,x,X (enteros): Número mínimo de dígitos que serán escritos. Se rellenará con ceros si el número es menor
        a, A, e, E, f, F: Número de dígitos que serán escritos después del punto decimal
        g, G: Número máximo de dígitos significativos que serán escritos
        s: Número máximo de caracteres que serán escritos
    */

    int v1 = 3;
    float v2 = 5.3;
    char cad[5] = "hola";

    printf("%.5d %.5f %.3s", v1, v2, cad);

    return 0;
}