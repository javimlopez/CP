#include <stdio.h>

int main() {
    /* Devuelve FILE *fopen(const char *filename, const char *mode); */
    /* En el modo 2 letras: Lectura, escritura, anexar (r, w, a: de append, escribir al final del fichero) y segunda letra si es texto o binario (la t se puede omitir)*/
    /* Write de un fichero inexistente lo crea. Si existe machaca la información que ya haya */
    /* Abrir en r+ o w+ es para lectura/escritura */

    FILE *fw;
    if ((fw = fopen("fichero.txt", "wt"))== NULL) { /* Fichero en modo apertura */

        exit(-1); /* Siempre hay que comprobar que el puntero que me devuelve no es nulo */
        perror("Error abriendo fichero.txt"); 
    }
    int num;
    printf("Introduce un número positivo (0 para terminar):");
    while(scanf("%d", &num) && num>0){

        fprintf (fw, "escribir %d\n", 3);
    }
    /* Funciones análogas a printf para el manejo con ficheros*/

    /* fputc, fputs, fprintf -> Escritura en ficheros de texto
       fwrite -> Escritura de ficheros binarios */

    fclose(fw);

    FILE* fr;
    fr = fopen("fichero.txt", "ws");
    
    /* Para lectura de archivos. Mirar fichero_texto.c */
    while(!feof(fw)){ /* feof avisa de que has llegado al final del fichero */
        fscanf(fw, "%d", &num); /* Lee el fichero línea por línea y con el bucle avanzamos por el fichero*/
        printf("%d", num);
    }

}