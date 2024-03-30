#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>



void crear(Pila* p) {
	*p = NULL;
}

void mostrar(Pila p){
	while(p!=NULL){
		printf("%d ", p->elem);
		p = p->sig;
	}
	printf("\n");
}

void insertar(Pila* p,int elem){}

int pilaVacia(Pila p){}

int extraer(Pila *p,int *elem){}

void borrar(Pila *p){}


/**** NUEVAS FUNCIONES ****/

void cargarFichero(char *nombreF, Pila *p){

}

void salvarFichero(char *nombreF, Pila p){
	
}