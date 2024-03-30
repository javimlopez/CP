#include "Pila.h"
#include <stdio.h>

/* gcc Principal.c Pila.c -o Principal para */
int main(){
	Pila p;
	int i;
	crear(&p);
	for (i=0;i<10;i++){
		insertar(&p,i);
	}
	mostrar(p);
	printf("fin mostrar\n");
	while(!pilaVacia(p)){
		extraer(&p,&i);
		printf("%d ",i);
	}
	mostrar(p);
	printf("fin mostrar\n");
	crear(&p);
	for (i=0;i<10;i++){
		insertar(&p,i);
	}
	mostrar(p);
	printf("fin mostrar\n");
	borrar(&p);
	mostrar(p);
	printf("fin mostrar\n");
	return 0;
	
	}
