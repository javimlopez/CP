#include <stdio.h>
#include <stdlib.h>

int main(){

    /* 
        
       printf(char *format, arg1, arg2, argn)
       Convierte, da formato e imprime los argumentos en la salida estándar bajo el control de format
        -format: Caracteres ordinarios que se mostrarán tal cual y especificaciones de formato/conversión:
            %[modificador][ancho][precision][longitud][carácter conversión]

            - Modificador {-, +, (espacio), #, 0}
            - Ancho: Ancho del espacio mínimo del campo
            - Precisión: Punto y nnúmero.
            - Longitud: Letras que modifican la longitud del tipo
            - Caracteres de conversión:
                d or i: Signed decimal integer => 392
                u: Unsigned decimal integer => 7235
                o: Unsigned octal => 610
                x: Unsigned hexdecimal integer => 7fa
                X: Unsigned hexadecimal integer (uppercase) => 7FA
                f: Decimal floating point, lowercase => 392.65
                F: Decimal floating point, uppercase => 392.65
                e: Scientific notation (mantissa/exponent), lowercase: => 3.9265e+2
                E: Scientific notation (mantissa/exponent), uppercase: => 3.9265E+2
                g: Use the shortest representation: %e or %f => 392.65
                G: Use the shortest representation: %E or %F => 392.65
                a: Hexadecimal floating point, lowercase => -0xc.90fep-2
                A: Hexadecimal floating point, uppercase => -0XC.90FEP-2
                c: Character => a
                s: String of characters => sample
                p: Pointer address => b8000000
                n: Nothing printed. The corresponding argument must be a pointer to a signed int. The number
                of characters written so far is stored in the pointer location.
                %: A % followed by another % character will write a sigle % to the stream => %

    */

    int s = 10;
    printf("El valor de la variable s es = %d\n", s);

    char cadena[15] = "hola";
    printf("Valor de cadena = %s\n", cadena);

    return EXIT_SUCCESS;
}