/*
    Ejemplo de uso de printf para distintos formatos de conversión

*/

#include <stdio.h>

int main() {

    int i, j;
    float x, y;

    i = 10;
    j = 20;
    x = 43.2892;
    y = 5527.0;

    printf("i = %d, j = %d, x = %f, y = %f \n", i, j, x, y);

    /* Forma de la conversión: %m.pX o %-m.pX donde m es la longitud mínima del campo, p la precisión y X la letra (d, f, ...)*/
    /* m justifica a la derecha y - m a la izquierda*/

    /*
        d -> Entero desplegado como decimal
        e -> Flotante desplegado estilo notación científica
        f -> Flotante forma fixed decimal
        g -> Flotante en cualquiera de las formas anteriores dependiendo del tamaño
        ...
    */

}

