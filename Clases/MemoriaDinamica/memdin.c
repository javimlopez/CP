#include <stdio.h>

int main(){

    int * ptr1 = (int *)malloc(20*sizeof(int)); // a block of the size of 20 ints is requested
    if (ptr1 = NULL) {
        fprintf(stderr, "Error requesting memory for 20 int\n");
        exit(-1);
    }

    double * ptr2 = (double *)calloc(20, sizeof(double)); // a block of 20 doubles is requested

    int * ptr3 = (int * )realloc(ptr1, 40); //the block of 20 doubles is increased to 40 doubles

    //free(ptr1); ptr1 y ptr3 apuntan a la misma zona de memoria
    free(ptr2);
    free(ptr3);
}