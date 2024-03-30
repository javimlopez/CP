#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include "arbolbb.h"

void crearFicheroAleatorios(char *nombreFich, int TAM)
{
	FILE *fichero;
	fichero = fopen(nombreFich, "wb");
	if (fichero == NULL)
	{
		perror("Ha habido un problema con la escritura del archivo");
		exit(-1);
	}
	srand(time(NULL));
	unsigned num;
	for (int i = 0; i < TAM; i++)
	{
		num = rand() % 100;
		fwrite(&num, sizeof(unsigned), 1, fichero);
	}
	fclose(fichero);
}

void mostrarFicheroAleatorios(char *nombreFich)
{
	FILE *fichero;
	fichero = fopen(nombreFich, "rb");
	if (fichero == NULL)
	{
		perror("Ha habido un problema con la lectura del archivo");
		exit(-1);
	}
	unsigned num;
	while (fread(&num, sizeof(unsigned), 1, fichero) == 1)
	{
		printf("%d\n", num);
	}
	fclose(fichero);
}

void cargaFichero(char *nfichero, T_Arbol *miarbol)
{
	FILE *fich;
	fich = fopen(nfichero, "rb");
	if (fich == NULL)
	{
		perror("cargaFichero: error al abrir el fichero en modo rb");
	}
	else
	{
		unsigned num;
		while (fread(&num, sizeof(unsigned), 1, fich) == 1)
		{
			insertar(miarbol, num);
		}
		fclose(fich);
	}
}
	

int main(int argc, char **argv)
{
	int TAM;
	char nombreFich[30];

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Introduzca nombre fichero:\n");
	scanf("%s", nombreFich);

	printf("Introduzca tamaño:\n");
	scanf("%d", &TAM);

	crearFicheroAleatorios(nombreFich, TAM);
	mostrarFicheroAleatorios(nombreFich);

	printf("\n Ahora lo cargamos en el arbol\n");
	T_Arbol miarbol;
	crear(&miarbol);
	cargaFichero(nombreFich, &miarbol);
	printf("\n Y lo mostramos ordenado\n");
	mostrar(miarbol);

	printf("\n Ahora lo guardamos ordenado\n");
	FILE *fich;
	fich = fopen(nombreFich, "wb");
	if (fich == NULL)
	{
		perror("main: error al abrir el fichero en modo wb");
	}
	else
	{
		salvar(miarbol, fich);
		fclose(fich);
		printf("\n Y lo mostramos ordenado\n");
		mostrarFicheroAleatorios(nombreFich);
	}
	destruir(&miarbol);
}
