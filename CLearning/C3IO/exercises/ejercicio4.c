#include <stdio.h>

int main(){

    int i, j, k;

    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &i, &j, &k);
    printf("\nYou entered the date: %d/%d/%d: ", k, i, j);

    return 0;
}