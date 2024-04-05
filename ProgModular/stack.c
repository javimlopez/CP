#include "stack.h"

Stack stackCreate(){
    printf("stackCreated invoked\n");

    Stack s;
    s = (Stack) malloc(sizeof (struct stack));
    s->size = 0;
    s->head = NULL;
    return s;
}

int stackPush(Stack s, int v) {

    //Implementación de stackPush aquí
    printf("stackPush invoked\n");
    return 0;
}

//Implementar resto de funciones