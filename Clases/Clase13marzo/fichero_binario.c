/*
 * fichero_binario.c
 * Author: Laura
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


void mostrarFichero(char *filename){
	  FILE * pFile;
	  char * buffer = NULL;
	  size_t result;
	  int size;

	  pFile = fopen ( filename , "rb" );
	  if (pFile==NULL) {
	  	perror("Error al abrir fichero para lectura"); 
	  }else{
	  	//Opcion 1: leer byte a byte y mostra cada byte por pantalla como un char, solo necesitamos una variable char
	  	//Opcion 2: calcular el tamaño del fichero, reservar memoria dinamica, leer todo en un unico fread y mostrar por pantalla, por ejemplo como string
	  	//Vamos a ver la opcion 2
	  	
	  	//asi podemos obtener el tamaño del fichero
	  	fseek (pFile , 0 , SEEK_END); //mueve el puntero del file al final
	  	size = ftell (pFile);
	  	rewind (pFile); //mueve el puntero del file al principio
	  	//-------
	  
	  	// reservar memoria para guardar todo el fichero
	 	 buffer = (char*) malloc (sizeof(char)*size);
	  	if (buffer == NULL) {
	  		perror("Error al reservar memoria\n");
	  	}else{
	  		// copiar el contenido del fichero en el buffer
	  		if (fread (buffer,1,size,pFile) != size)
	  			perror ("Error al leer de fichero"); 
	  		else //si el fichero es binario no veremos nada legible por pantalla
	  			printf("Contenido del fichero:\n%s\n", buffer); 
	  		free(buffer);
	  	}
	  	fclose (pFile);
	  }
}


#define SIZE 8
void copiarFichero(char *origen, char *destino){
	FILE *fOrigen, *fDestino;
	unsigned char buffer[SIZE];
	size_t leo = 0, escribo=0;


	if((fOrigen=fopen(origen,"rb"))==NULL)
	{
		perror("Error abriendo fichero origen");
		exit(-1);
	}

	if((fDestino = fopen(destino,"wb"))==NULL)
	{
		perror("Error abriendo fichero destino");
		fclose(fOrigen);
		exit(-1);
	}
	do{
		leo = fread(buffer, 1, SIZE, fOrigen);
		escribo = fwrite(buffer, 1, leo,fDestino);
	}while(leo>0 && leo==escribo);
		
	fclose(fOrigen);
	fclose(fDestino);

}


int main(int argc, char **argv){

int num;
	setvbuf(stdout, NULL, _IONBF, 0);
	/* 
	 * Creamos un fichero BINARIO con los datos que introduzca el usuario
	*/
	
	//Creamos un fichero en modo wb - inicialmente vacio, si existia perdemos la informacion que tenia
	FILE *fw = fopen("fichero.dat", "wb");
	if(fw==NULL){
		perror("Error al abrir fichero.dat en modo wb");
		exit(-1);
	}

	//copiamos en el fichero informacion que pasa el usuario por teclado
	printf("Introduce un numero positivo (0 para terminar):");
	while(scanf(" %d",&num) && num>0){
		fwrite(&num,sizeof(num),1, fw);		
	}

	//cerramos el fichero
	fclose(fw);

	/* 
	 * Mostramos por terminal los numeros que hay en un fichero BINARIO
	*/

	//Abrimos el fichero en modo rb
	FILE *fr = fopen("fichero.dat", "rb");
	if(fr==NULL){
		perror("Error al abrir fichero.dat en modo rb");
		exit(-1);
	}
	// Leemos el contenido hasta llegar al final del fichero
	while(!feof(fr) && fread(&num, sizeof(num),1,fr)){
		printf(" %d", num);
	}
	//cerramos el fichero
	fclose(fr);
	
	copiarFichero("fichero.dat","copia.dat");			
	
	return 0;
}