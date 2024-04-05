#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/************************************************************************************************************************************************************************
 *    1) Un sistema de monitorización extrae información sobre la ejecución del sistema que monitoriza como una secuencia ordenada de eventos temporizados (traza).     *
 *    Utilizando las definiciones de tipos de los ejercicios anteriores (TTimedEvent, TTimestamp), el tipo Trace se define como:                                        *
 *                                                                                                                                                                      *
 *    typedef struct Node *Trace;                                                                                                                                       *
 *    struct Node{                                                                                                                                                      *
 *    TTimedEvent te;                                                                                                                                                   *
 *    Trace next;                                                                                                                                                       *
 *    };                                                                                                                                                                *
 *                                                                                                                                                                      *
 *    Una traza es una lista enlaza de nodos de tipo struct Node que almacena un TTimedEvent y la referencia al siguiente nodo de la lista.                             *
 *    Utilizando las definiciones de tipo y las funciones que se definieron e implementaron en los ejercicios anteriores,                                               *
 *    implementa (de forma eficiente) las siguientes funciones sobre trazas:                                                                                            *
 *                                                                                                                                                                      *
 *        void emptyTrace(Trace *trace): crea una traza vacía (sin eventos)                                                                                             *
 *        void showTrace(Trace trace): muestra por pantalla la información de los eventos                                                                               *
 *        void destroyTrace(Trace *trace): elimina todos los elementos de la traza                                                                                      *
 *        void appendEvent(Trace *trace, TTimedEvent te): añade un nuevo evento temporizado al final de la traza                                                        *
 *        void prependEvent(Trace *trace, TTimedEvent te): añade un nuevo evento temporizado al comienzo de la traza                                                    *
 *        int getIndex(enum event ev, Trace trace): devuelve la posición que de la primera ocurrencia del evento ev en la traza.                                        *
 *        Asumimos que los eventos de la traza se indexan de 0 al tamaño -1                                                                                             *
 *        void insert(Trace *trace, int i, TTimedEvent te): inserta en la posición i de la traza el nuevo evento temporizado,                                           *
 *        de manera que el evento que antes estaba en i ahora estará en i+1. Si la longitud de la traza es menor que i, entonces se añade al final.                     *
 *                                                                                                                                                                      *
 ************************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
struct TTimeStamp {

    int horas;
    int minutos;
    int segundos;

};


enum event {START, STOP, PAUSE, FORWARD, BACKWARD};

struct TTimedEvent {

    enum event evento;
    struct TTimeStamp marca;
};

enum event stringToEvent(const char** nombreEvento, int length){

    char *comparator;
    comparator = (char*)malloc((length+1)*sizeof(char)); //Asignar memoria
    if (comparator == NULL){
        printf("Error al asignar memoria.\n");
        return 1;
    }
    for(int i = 0; i<length; i++) {
        comparator[i] = *(*nombreEvento)++;
    }
    if(strcmp(comparator, "START") == 0){
        return START;
    }
    if(strcmp(comparator, "STOP") == 0){
        return STOP;
    }
    if(strcmp(comparator, "PAUSE") == 0){
        return PAUSE;
    }
    if(strcmp(comparator, "FORWARD") == 0){ 
        return FORWARD;
    }
    if(strcmp(comparator, "BACKWARD") == 0){ 
        return BACKWARD;
    }
    free(comparator);
    exit(1);
}
char* eventToString(enum event* nombreEvento){
    enum event comparator = *nombreEvento;
    if(comparator == START){
        return "START";
    }
    if(comparator == STOP){
        return "STOP";
    }
    if(comparator == PAUSE){
        return "PAUSE";
    }
    if(comparator == FORWARD){ 
        return "FORWARD";
    }
    if(comparator == BACKWARD){ 
        return "BACKWARD";
    }
    exit(1);
}
int isValid(struct TTimeStamp *marcaTiempo){
    
    if(marcaTiempo->horas < 0 || marcaTiempo->horas > 23){
        printf("La hora introducida no es válida\n");
        return 1;
    }
    if(marcaTiempo->minutos < 0 || marcaTiempo->minutos > 59){
        printf("Los minutos introducidos no son válidos\n");
        return 1;
    }
    if(marcaTiempo->segundos < 0 || marcaTiempo->segundos > 59){
        printf("Los segundos introducidos no son válidos\n");
        return 1;
    }

    return 0;
}

struct TTimeStamp readTimestamp(){

    struct TTimeStamp marcaTiempo;
    printf("Introduzca los valores (hh:mm:ss): \n");
    scanf("%d:%d:%d", &marcaTiempo.horas, &marcaTiempo.minutos, &marcaTiempo.segundos);
    if( isValid(&marcaTiempo) == 1 ){
        printf("Marca de tiempo no válida.\n");
        exit(1); //Sale del programa con código de error 1
    }

    return marcaTiempo;
}

void showTimestamp(const struct TTimeStamp *marcaTiempo){

    printf("El timestamp introducido es: %d:%d:%d\n", marcaTiempo->horas, marcaTiempo->minutos, marcaTiempo->segundos);
}

struct TTimedEvent readTimedEvent(){

    struct TTimedEvent tempEvent;
    char* evento;

    // Asignar memoria inicial
    evento = (char *)malloc(100 * sizeof(char));
    if (evento == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        exit(1);
    }
    printf("Introduzca el evento: \n");
    scanf("%ms", &evento);
    int length = strlen(evento);
    tempEvent.evento = stringToEvent(&evento, length);
    printf("Introduzca la marca de tiempo realizada (hh:mm:ss): \n");
    scanf("%d:%d:%d", &tempEvent.marca.horas, &tempEvent.marca.minutos, &tempEvent.marca.segundos);
    if( isValid(&tempEvent.marca) == 1 ){
        printf("Marca de tiempo no válida.\n");
        exit(1); //Sale del programa con código de error 1
    }
    
    return tempEvent;
}

void showTimedEvent(const struct TTimedEvent *timedEvent){

    printf("Evento: %s\n", eventToString(&timedEvent->evento));
    printf("Marca de tiempo alcanzada: %d:%d:%d\n", timedEvent->marca.horas, timedEvent->marca.minutos, timedEvent->marca.segundos);

}

typedef struct Node *Trace;                                                                                                                                       *

struct Node{
    TTimedEvent evento;
    Trace next;
}
