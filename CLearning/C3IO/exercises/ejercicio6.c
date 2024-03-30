#include <stdio.h>

int main() {

    int language, publisher, number, digit;


    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d\n",&language, &publisher, &number, &digit);
    printf("Language: %d\n", language);
    printf("Publisher: %d\n", publisher);
    printf("Book number: %d\n", number);
    printf("Check digit: %d\n", digit);

    return 0;
}