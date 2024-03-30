#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/********************************************************************************************************************************************************
 * 5) Define los siguientes tipo registro y sus funciones asociadas. Además, implementa un programa principal que te permita probar todas las funciones:*
 *                                                                                                                                                      *    
  - TTimeStamp: el registro almacena 3 enteros, cada uno almacena el número de horas, minutos y segundos de una marca de tiempo.                        *
    Implementa la función isValid que determina si un timestamp tiene valores correctos en los campos horas, minutos y segundos.                        *
    Implementa la función readTimestamp que lee de teclado un timestamp válido y lo devuelve.                                                           *
    Implementa la función showTimeStamp que dada una variable TTimestamp muestra por pantalla la marca de tiempo con el formato                         *
    hh:mm:ss                                                                                                                                            *
                                                                                                                                                        *
  - Dada la definición del tipo enumerado event:                                                                                                        *
    enum event {START, STOP, PAUSE, FORWARD, BACKWARD};                                                                                                 *
    Implementa la función stringToEvent que dado un string con el nombre de uno de los eventos, devuelve el valor enumerado que lo representa.          *
    Implementa la función eventToString que dado un valor de tipo enum event muestre por pantalla un string con el nombre del evento correspondiente.   *
    [Parámetros por referencia] no muestra por pantalla sino que devuelve una cadena con el nombre del evento.                                          *
                                                                                                                                                        *
  - TTimedEvent: el registro almacena un TTimestamp y una variable de tipo enum event. Utilizando las funciones definidas para estos tipos,             *
    implementa las siguientes funciones para TTimedEvent.                                                                                               *
    Implementa la función readTimedEvent que devuelve la información de un TTimedEvent que ha leído por teclado.                                        *
    El TTimedEvent debe ser válido, es decir que el Timestamp es válido y el evento también.                                                            *
    Mientras la información que se introduzca por teclado no sea válida deberá pedir al usuario que siga proporcionando los datos correctamente.        *
                                                                                                                                                        *
   Implementa la función showTimedEvent que dada una variable TTimedEvent muestra por pantalla la marca de tiempo y el nombre del evento.               *
*********************************************************************************************************************************************************/
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

int main() {
    /* Apartado TTimeStamp*/
    int horas, minutos, segundos;
    struct TTimeStamp marcaTiempo = readTimestamp();
    showTimestamp(&marcaTiempo);

    /* Apartado Enum Event*/
    enum event prueba = STOP;
    char* cadena = "START";
    int length = strlen(cadena);
    prueba = stringToEvent(&cadena, length);
    cadena = eventToString(&prueba);
    printf("El valor de la enum es: %s\n", cadena);
    printf("El valor de la enum es: %s\n", eventToString(&prueba));

    /* Apartado TTimedEvent*/
    struct TTimedEvent eventoMedido = readTimedEvent();
    showTimedEvent(&eventoMedido);

    return 0;
    
}

