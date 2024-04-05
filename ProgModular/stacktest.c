#include "stack.h"

int main(){

    Stack myStack;
    myStack = stackCreate();

    stackPush(myStack, 4);

    return 0;
}