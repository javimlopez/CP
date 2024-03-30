#include <stdio.h>
#include <stdlib.h>


int main(){

    /*
        Modificadores: El más utilizadoe es el símbolo '-'
        -: Justificación a la izquierda en el campo
        +: Muestra los signos (-,+) de los números
        (espacio): Si no se va a escribir el signo, se inserta un espacio antes del número
        #: Depende del carácter de conversión utilizado (o, x, X, a, A, f, F, e, E, g, G)
        O: Rellana con 0 en lugar de con espacio cuando se especifica un campo ancho
    */

   int v1 = 3;
   float v2 = 5.3;

   printf("%5d %f\n", v1, v2);
   printf("%-5d %f\n", v1, v2);
   printf("%05d %f", v1, v2);
   
   return 0;
}