#include <stdio.h>
#include <stdlib.h>
#include "gestion_memoria.h"


/* Crea la estructura utilizada para gestionar la memoria disponible. Inicialmente, s�lo un nodo desde 0 a MAX */
	void crear(T_Manejador* manejador){
        *manejador = malloc(sizeof(struct T_Nodo));
        if(*manejador == NULL){
            printf("Ha habido un problema en la asignación de memoria");
            exit(-1);
        } else {
            (*manejador)->inicio = 0;
            (*manejador)->fin = 999;
            (*manejador)->sig = NULL;
        }
    }

/* Destruye la estructura utilizada (libera todos los nodos de la lista. El par�metro manejador debe terminar apuntando a NULL */
	void destruir(T_Manejador* manejador){

        T_Manejador aux;
        while(*manejador != NULL){
           aux = *manejador;
           *manejador = (*manejador)->sig;
           free(aux);
        }

    }

/* Devuelve en �dir� la direcci�n de memoria �simulada� (unsigned) donde comienza el trozo de memoria continua de tama�o �tam� solicitada.
Si la operaci�n se pudo llevar a cabo, es decir, existe un trozo con capacidad suficiente, devolvera TRUE (1) en �ok�; FALSE (0) en otro caso.
 */
	void obtener(T_Manejador *manejador, unsigned tam, unsigned* dir, unsigned* ok){
        T_Manejador curr = *manejador; //Utilizamos un nodo current para manejarnos por los nodos de la estructura
        T_Manejador prev = NULL; // Tenemos un puntero al nodo previo como referencia
        *ok = 0;

        while(curr != NULL && !(*ok)){
            if(curr->fin - curr->inicio + 1 > tam){
                *dir = curr->inicio;
                *ok = 1;
                curr->inicio += tam;
            } else if(curr->fin - curr->inicio + 1 == tam){
                *dir = curr->inicio;
                *ok = 1;
                if(prev == NULL){ //Borramos el primer nodo de la lista
                    *manejador = (*manejador)->sig;
                } else { // borramos el nodo intermedio o final
                    prev-> sig = curr->sig;
                }
                free(curr);
            }
        }
    }

/* Muestra el estado actual de la memoria, bloques de memoria libre */
	void mostrar (T_Manejador manejador){
        T_Manejador aux = manejador;
        while(aux != NULL){
            printf("**** Mostrando la memoria ****\n");
            printf("[%u, %u]", aux->inicio, aux->fin);
            aux = aux->sig;
        }
        printf("\n");
    }
/* Insertar un nodo */
    void insertarNodo ( T_Manejador *manejador, unsigned inicio, unsigned tam){
        // Caso base: Lista vacía  o el nuevo nodo tiene que insertarse antes que el primero
        if(*manejador == NULL || inicio < (*manejador)->inicio){
            T_Manejador aux = (T_Manejador) malloc(sizeof(struct T_Nodo));
            if(aux == NULL){
                printf("Error al reservar memoria para el nodo - insertarNodo");
                exit(-1);
            }
            aux->inicio = inicio;
            aux -> fin = inicio + tam + 1;
            aux->sig = *manejador;
            *manejador = aux;
        } else {
            //Caso recursivo
            insertarNodo(&((*manejador)->sig), inicio, tam);
        }
    }
    void compactar ( T_Manejador manejador){
        T_Manejador curr = manejador;
        while ( curr != NULL && curr->sig != NULL ){ // Al menos dos nodos en la lista
            if(curr-> fin + 1 == curr->sig->inicio){
                T_Manejador aux = curr->sig;
                curr->fin = curr->sig->fin;
                curr->sig = curr->sig->sig;
                free(aux);
                //No avanza curr por si el siguiente nodo también es consecutivo en memoria
            } else {
                curr = curr->sig;
            }
        }
    }

/* Devuelve el trozo de memoria continua de tama�o �tam� y que
 * comienza en �dir�.
 * Se puede suponer que se trata de un trozo obtenido previamente.
 */
	void devolver(T_Manejador *manejador,unsigned tam,unsigned dir){
        insertarNodo(manejador, dir, tam);
        compactar(manejador);
    }
