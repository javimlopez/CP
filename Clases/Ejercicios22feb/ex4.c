#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*********************************************************************************************************************************
 * 4) Implementar un calculadora simple que realice las operaciones de suma (+), resta (-), multiplicación (*) y división (/)    *
 * de dos números enteros y muestre por pantalla el resultado.                                                                   *
 * El programa debe dar la opción de hacer un cálculo (el usuario introduce 'c') o terminar (usuario introduce el carácter 'q'). *
 * El usuario introducirá por teclado la expresión en notación infija, es decir <operando 1> <Operador> <operando 2>             *
 * (puede leer elemento a elemento o los 3 a la vez).                                                                            *
 *********************************************************************************************************************************/

int main() {
    char option;
    int numero1, numero2;
    char operacion;

    printf("¿Desea realizar alguna operacion? (Si: c, No: q) \n");
    scanf("%c", &option);

    while(option != 'q'){
        
        printf("Introduzca la operación que quiere llevar a cabo (num1 operacion num2): \n");
        scanf("%d%c%d", &numero1, &operacion, &numero2);
        switch(operacion){

            case '+': printf("Ha elegido Suma. El resultado de la operacion es: %d\n", numero1 + numero2); break;
            case '*': printf("Ha elegido Producto. El resultado de la operacion es: %d\n", numero1 * numero2); break;
            case '-': printf("Ha elegido Resta. El resultado de la operacion es: %d\n", numero1 - numero2); break;
            case '/': printf("Ha elegido Division. El resultado de la operacion es: %d\n", numero1 / numero2); break;
        }

        printf("¿Desea realizar alguna otra operacion? (Si: c, No: q) \n");
        scanf("%c", &option);
    }
    printf("Salida pulsada. Buen día :D!\n");
    return 0;
}