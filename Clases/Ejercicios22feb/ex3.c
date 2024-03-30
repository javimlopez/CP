/*
3) Implementar un programa que lea de teclado dos cadenas (o dos palabras) y las compare carácter a carácter. 
Devolverá 1 si las dos cadenas son iguales y 0 en otro caso. [Parámetros por referencia] 
Cuando las cadenas no sean iguales devolverá  la posición del primer carácter en el que difieren, 
siendo 0 la posición del primer carácter.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    char* cadena1;
    char* cadena2;
    printf("Introducir la cadena 1: \n");
    scanf("%c", &cadena1);
    printf("Introducir la cadena 2: \n");
    scanf("%c", &cadena2);
    
    return compararCadenas(cadena1, cadena2);;
}

int compararCadenas(char* cadena1, char* cadena2) {
    char c1, c2;
    int pos = 0;
    while(&cadena1[pos]==&cadena2[pos]){
        pos ++;
        
    }
    return pos;

}