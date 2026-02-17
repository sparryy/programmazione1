#include <iostream>
#include "stack_char.h"

bool isEmpty(Stack &stack);

bool init(Stack &stack) {
    stack = NULL;
    return true;
}

bool top(Stack &stack, char &value) {
    bool result;

    if(isEmpty(stack)) {
        result = false;
    } else {
        value = stack->value;
        result = true;
    } 
    return result;
}

bool push(Stack &stack, char value) {
    Node * newNode = new Node{value, stack};

    stack = newNode;

    return true;
}

bool pop(Stack &stack, char &value) {
    bool result;

    if(isEmpty(stack)) {
        result = false;
    } else {
        Node *topNode = stack;

        value = topNode->value;
        stack = stack->next;
        
        delete topNode;

        result = true;
    }
    return result;
}

void deinit(Stack &stack) {
    char tmp;
    while(pop(stack,tmp));
    stack = NULL;
}

bool isEmpty(Stack &stack) {
    return stack == NULL;
}