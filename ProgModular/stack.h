// Módulo para implementar una pila mediante lista enlazada de punteros

#ifndef __STACK_H_:
#define __STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode * StackNode;
struct stackNode {
    int value;
    StackNode ptr ;
};

typedef struct stack * Stack;
struct stack {
    int size;
    StackNode head;
};

Stack stackCreate();
int stackPush(Stack s, int v);
int stackPop(Stack s, int * v);
int stackSize(Stack s);
#endif