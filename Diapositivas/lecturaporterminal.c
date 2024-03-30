#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    /* scanf(char *format, arg1, arg2...); 
    
       Proporciona las mismas facilidades de conversión en la dirección opuesta
       Devuelve:
        - Número de argumentos que se han podido leer
        - Indicador de error sis se produce error en la lectura
        - Los argumentos deben ser punteros a las variables!!! Indican dónde debe almacenarse la entrada correspondiente convertida
    */

    double sum, v;
    sum = 0;

    while(scanf("%1f", &v) == 1)
        printf("\t%.2f\n", sum+=v);
        
    return 0;
}