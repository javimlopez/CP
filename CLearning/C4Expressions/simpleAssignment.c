#include <stdio.h>

int main(){

    int i = 1;
    int j;
    int k =  1 + (j = i);
    printf("%d %d %d\n", i, j, k); /* prints "1 1 2"*/

    return 0;
}