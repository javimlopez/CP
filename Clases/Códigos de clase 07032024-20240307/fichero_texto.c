/*
 * fichero_texto.c
 * Author: Laura
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



int main(int argc, char **argv)
{
	int num;
	setvbuf(stdout, NULL, _IONBF, 0);
	/* 
	 * Creamos un fichero de texto con los datos que introduzca el usuario
	*/
	
	//Creamos un fichero en modo wt - inicialmente vacio, si existia perdemos la informacion que tenia
	FILE *fw = fopen("fichero.txt", "wt");
	if(fw==NULL){
		perror("Error al abrir fichero.txt en modo wt");
		exit(-1);
	}

	//copiamos en el fichero informacion que pasa el usuario por teclado
	printf("Introduce un numero positivo (0 para terminar):");
	while(scanf(" %d",&num) && num>0){
		fprintf(fw,"%d ",num);		
	}

	//cerramos el fichero
	fclose(fw);

	/* 
	 * Mostramos por terminal los números que hay en un fichero de texto
	*/

	//Abrimos el fichero en modo rt
	FILE *fr = fopen("fichero.txt", "rt");
	if(fr==NULL){
		perror("Error al abrir fichero.txt en modo rt");
		exit(-1);
	}
	// Leemos el contenido hasta llegar al final del fichero
	while(!feof(fr)){
		fscanf(fr, " %d", &num);
		printf(" %d", num);
	}

	//cerramos el fichero
	fclose(fr);

	return 0;
}
