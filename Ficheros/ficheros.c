#include <stdio.h>
#include <stdlib.h>

int main(){
    int codigo, edad, leidos;
    char nombre[20];

    FILE * fd = fopen("personas.txt", "rt");
    while (!feof(fd)){ //Comprueba final de fichero e: end o: of f:file
        leidos = fscanf(fd, "%d %d", &codigo, &edad); // Retorna el número de items leidos
        fgets(nombre, 20, fd);
        printf("%d %d %s", codigo, edad, nombre);
    }
}