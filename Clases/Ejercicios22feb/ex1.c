#include <stdio.h>
#include <stdlib.h>

/*
1) Implementar la función int esPrimo(int n) que dado un entero n devuelve 1 si es primo y 0 en otro caso. 
Implementa un método main que pida al usuario un número, le pase como argumento ese número 
a la función esPrimo, y muestre por pantalla una frase indicado si el número es o no primo.
*/

int main(){
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    if(esPrimo(&numero)){
        printf("El numero %d es primo\n", numero);
    }else{
        printf("El numero %d no es primo\n", numero);
    }   
    return 0;
}

int esPrimo(int *numero){
    int i;
    for(i=2; i<&numero; i++){
        if(*numero%i==0){
            return 0;
        }
    }
    return 1;
}



