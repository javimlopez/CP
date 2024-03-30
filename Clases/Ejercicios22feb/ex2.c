/*
2) Implementar un programa que lea de teclado una cadena terminada en el carácter '#' y devuelva
 el número de apariciones de cada una de las vocales. 
Para usar scanf hay que leer carácter a carácter porque no se sabe la longitud de la cadena.
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    char c;
    int a=0, e=0, i=0, o=0, u=0;
    printf("Ingrese una cadena terminada en #\n");
    while((c=getchar())!='#'){
        switch(c){
            case 'a':
            case 'A':
                a++;
                break;
            case 'e':
            case 'E':
                e++;
                break;
            case 'i':
            case 'I':
                i++;
                break;
            case 'o':
            case 'O':
                o++;
                break;
            case 'u':
            case 'U':
                u++;
                break;
        }
    }
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
    return 0;
}