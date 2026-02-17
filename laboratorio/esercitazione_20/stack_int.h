#ifndef STACK_INT_H
#define STACK_INT_H

struct Node {
    int value;
    Node *next;
};

typedef Node *Stack;

bool init(Stack &stack);
bool push(Stack &stack, int value);
bool top(Stack &stack, int &value);
bool pop(Stack &stack, int &value);
void deinit(Stack &stack);

#endif