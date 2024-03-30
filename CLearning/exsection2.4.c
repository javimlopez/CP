#include <stdio.h>

/* La declaración y asignación de variables de un par de tipos y su printeo por pantalla*/
/* Computes the dimensional weight of a box*/
/* from imput provided by the user*/
#define CUBIC_IN_PER_LB 166 /* Definición de Macros */
#define SCALE_FACTOR (5.0/9.0) /* Operaciones en macros obligatorias entre paréntesis*/
int main () {
    int height = 8, length = 12, width = 4, volume; /* Declaración de variables e inicialización de Height*/
    volume = height * length * width;
    printf("Peso: %d\n", (volume+165/166));
    
    return 0;
}
