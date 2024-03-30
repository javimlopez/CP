#include <stdio.h>

int main(){

    int i;
    float x;
    

    i = 40;
    x = 839.21;

    printf("|%d|%5d|%-5.d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x,x,x);

    /* Secuencias de escape 
        \a alert bell
        \b backspace
        \n new line
        \t horizontal tab
    */

    printf("Item\tUnit\tPurchase\n\t\tPrice\tDate\n");
    printf("Alert bell\a\n");

    /* Imprimir comillas */
    printf("\"Hello!\"");
    /* Imprimir \ */
    printf("\\");

}