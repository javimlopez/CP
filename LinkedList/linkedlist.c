#include <stdio.h>
#include <stdlib.h>
//Definición de tipos
typedef struct NodoNum *ListaNum;
struct NodoNum {
    int num;
    ListaNum sig;
};

/* Operaciones básicas con listas enlazadas */
// Mostrar una lista
void mostrar (ListaNum lista ){

    ListaNum ptr;
    ptr = lista;
    printf("Lista: ");
    while (ptr != NULL){
        printf("%d ",ptr->num);
        ptr = ptr->sig;
    }
    printf("\n");
}

// Buscar un nodo en una lista
ListaNum buscarNodo(ListaNum lista, int elem){
    ListaNum ptr;

    ptr = lista;
    while ((ptr != NULL ) && (elem != ptr->num)){
        ptr = ptr->sig;
    }
    return ptr;
}

// Eliminar el primer nodo
void eliminarPrimero(ListaNum *lista) {
    ListaNum ptr;

    if (lista != NULL) {
        ptr = *lista;
        *lista = (*lista)->sig;
        free(ptr);
    }
}

// Insertar un nodo al principio de la lista
void insertarPrincipio(ListaNum *lista, int elem) {
    ListaNum ptr;

    ptr = malloc(sizeof(struct NodoNum));
    ptr->num = elem;
    ptr->sig = *lista;
    *lista = ptr;
}

// Insertar un nodo en una lista ordenada
void insertarOrdenado (ListaNum *lista, int elem){

    ListaNum nuevoNodo; //Para crear el nuevo nodo
    ListaNum ant, ptr; // Para posicionarnos donde insertar

    //Creamos el nuevo nodo
    nuevoNodo = malloc(sizeof(struct NodoNum));
    nuevoNodo->num = elem;

    //Buscamos donde insertar
    if (*lista == NULL) { //lista vacía
        nuevoNodo->sig = NULL;
        *lista = nuevoNodo;
    } else if (nuevoNodo->num <= (*lista)->num){
        //insertar al principio
        nuevoNodo->sig = *lista;
        *lista = nuevoNodo;
    } else { // insertar en medio o al final
    
        ant = *lista;
        ptr = (*lista)->sig;
        while ((ptr != NULL) && (nuevoNodo->num > ptr->num)){
            ant = ptr;
            ptr = ptr->sig;
        }
        nuevoNodo->sig = ptr;
        ant->sig = nuevoNodo;
    }
}

void eliminar(ListaNum *lista, int elem){
    ListaNum ptr; // Usamos dos variables
    ListaNum ant; // ant siempre va un paso por detrás de ptr.

    if(*lista != NULL) { //lista no vacia
    
        if((*lista)->num == elem){
            eliminarPrimero(lista);
        } else { //buscar elem en resto de la lista
        
            ant = *lista;
            ptr = (*lista)->sig;
            while ((ptr!= NULL) && (ptr->num != elem)){
                ant = ptr;
                ptr = ptr->sig;
            }
            if (ptr != NULL) { //encontrado
                ant->sig = ptr->sig;
                free(ptr); 
            }
        }
    
    }
}

//Crear una lista añadiendo los nodos nuevos al final
// Lee secuencia de números terminada en 0
ListaNum crearLista() {
    int dato;
    ListaNum lista, ptr;

    scanf("%d", &dato);
    if(!dato){ //Si dato contiene 0 se crea la lista vacía
        lista = NULL; 
    
    } else {
        lista = malloc(sizeof(struct NodoNum)); //primer nodo
        lista->num = dato;
        ptr = lista; //Apunta al primer nodo
        scanf("%d", &dato);
        while(dato) { //termina si dato contiene 0
            ptr->sig = malloc(sizeof(struct NodoNum));
            ptr = ptr->sig;
            ptr->num = dato; //Copiar nodo
            scanf("%d", &dato);
        }
        ptr->sig = NULL;
    }
    return lista;
}
int main() {
    
    // Declaración de variables
    ListaNum lista; //apunta al primer nodo
    lista = crearLista(); mostrar(lista);

    insertarPrincipio(&lista, 0); //Importante el uso del &
    mostrar(lista);
    insertarOrdenado(&lista, 5); mostrar(lista);

    eliminarPrimero(&lista); mostrar(lista);
    eliminar(&lista, 5); mostrar(lista);

    return 0;
}