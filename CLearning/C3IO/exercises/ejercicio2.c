#include <stdio.h>

int main(){

    float x = 34.506;

    printf("x1: %-8.1e\n", x);
    printf("x2: %10.6e\n", x);
    printf("x3: %-8.3f\n", x);
    printf("x4: %6.f\n", x);

    return 0;
}