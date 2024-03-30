#include <stdio.h>

/* Operadores lógicos
        
    a: 10101010 
    b: 00001111
    |: OR. a|b -> 10101111
    &: AND. Intersección bit a bit. a&b -> 00001010
    ^: OR exclusivo. a ^ b -> 10100101
    <<X: Mover x posiciones a la izquierda. 10101010 -> a << 1 -> (1) 01010100 (Se rellena con un 0).
    >>X: Mover x posiciones a la derecha
    ~: Complemento ~b -> 11110000
*/
int main(){

    /* A nivel de memoria, los desplazamientos son operaciones más eficientes que las normales 
    
       Desplazar uno a la izquierda: Dividir entre 2
       Desplazar uno a la derecha: Multiplicar por 2
    */
    /* 
        Operaciones de bitmask
    */

    /* 
        a (20): 00010100
        a | (11111111) -> Los 1 la máscara SET ON => 1..1 (255, FF)
        a | (00000001) -> 00010101 

        Esto es para poner a 1 las posiciones que queremos en 1 aplicando la máscara correspondiente.

        Para desactivar las posiciones x que queremos de a utilizaremos una máscara y aplicaremos un & (AND)

        a & (00000000) -> Todo a 0
    */
    return 0;
}