#include <stdio.h>
#define PI 3.14159

int main(){
    int radio = 10;
    float volume = (4/3) * PI * (radio * radio * radio);
    printf("El volumen de la esfera es : %.2f  \n", volume);
}