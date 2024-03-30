#include <stdio.h>

int main(){

    int item;
    float price;
    int month, day, year;
    printf("Enter item number: ");
    scanf("%d", &item);
    printf("\nEnter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n%-d\t\t$ %f\t%-d/%d/%d\n", item, price, month, day, year);


    return 0;
}