#include <stdio.h>

int main() {

    int x = 5;
    int y = 4.6;

    printf("Mete el numero entero: \n");
    scanf(" %d", &x);
    printf("%d", x);
    printf("\nMete el numero entero otra vez: \n");
    scanf("%d", &x);
    printf("%d", x);
    printf("Mete el número flotante: \n");
    scanf(" %f", &y);
    printf("%f", &y);
    printf("\nMete el numero entero otra vez: \n");
    scanf("%f", &y);
    printf("%f", y);

    return 0;
}