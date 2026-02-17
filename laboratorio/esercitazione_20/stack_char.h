#ifndef STACK_CHAR_H
#define STACK_CHAR_H

struct Node {
    char value;
    Node *next;
};

typedef Node *Stack;

bool init(Stack &stack);
bool push(Stack &stack, char value);
bool top(Stack &stack, char &value);
bool pop(Stack &stack, char &value);
void deinit(Stack &stack);

#endif