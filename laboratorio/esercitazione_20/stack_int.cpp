#include <iostream>
#include "stack_int.h"

bool isEmpty(Stack &stack);

bool init(Stack &stack) {
    stack = NULL;
    return true;
}

bool top(Stack &stack, int &value) {
    bool result;

    if(isEmpty(stack)) {
        result = false;
    } else {
        value = stack->value;
        result = true;
    } 
    return result;
}

bool push(Stack &stack, int value) {
    Node * newNode = new Node{value, stack};

    stack = newNode;

    return true;
}

bool pop(Stack &stack, int &value) {
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
    int tmp;
    while(pop(stack,tmp));
    stack = NULL;
}

bool isEmpty(Stack &stack) {
    return stack == NULL;
}