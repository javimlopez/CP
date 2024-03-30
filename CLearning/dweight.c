#include <stdio.h>


/* La declaración y asignación de variables de un par de tipos y su printeo por pantalla*/
/* Computes the dimensional weight of a box*/
/* from imput provided by the user*/
#define CUBIC_IN_PER_LB 166 /* Definición de Macros */
#define SCALE_FACTOR (5.0/9.0) /* Operaciones en macros obligatorias entre paréntesis*/
int main () {
    int height, length, width, volume, weight; /* Declaración de variables e inicialización de Height*/
    float profit, loss;
    printf("Enter height of box: "); /* Imprimir por pantalla un número decimal o int*/
    scanf("%d", &height); /* Pide un valor por terminal de tipo int (decimal)*/
    printf("Enter length of box: "); /* Imprimir por pantalla un número float con dos decimales de precisión */
    scanf("%d", &length); 
    printf("Enter width of box: ");
    scanf("%d", &width);
    volume = height * length * width;
    weight = (volume + CUBIC_IN_PER_LB - 1) / CUBIC_IN_PER_LB;

    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensional weight (pounds): %d\n", weight);
    
    return 0;
}
