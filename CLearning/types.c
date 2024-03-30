#include <stdio.h>
#include <stdlib.h>

/* La declaración y asignación de variables de un par de tipos y su printeo por pantalla*/
int main () {

    int height = 8, length = 12, width = 10, volume, weight; /* Declaración de variables e inicialización de Height*/
    float profit, loss;

    height = 8; /* Asignación de valores */
    length = 12;
    width = 10;
    volume = height * length * width;
    weight = (volume + 165) / 166;
    profit = 2150.48;
    printf("Dimensions: %dx%dx%d\n", length, width, height); /* Imprimir por pantalla un número decimal o int*/
    printf("Volume (cubic inches):  %d\n", volume); /* Imprimir por pantalla un número float con dos decimales de precisión */
    printf("Dimensional weight (pounds): %d\n", weight);
    
    return 0;
}