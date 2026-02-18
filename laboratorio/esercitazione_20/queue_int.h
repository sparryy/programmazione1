#ifndef QUEUE_INT_H
#define QUEUE_INT_H
#include "stack_int.h"

/* struct Node {
    int value;
    Node *next;
}; */

struct Queue {
    Node * front;
    Node * back;
};

void init(Queue &queue);
void deinit(Queue &queue);
bool enqueue(Queue &queue, int value);
bool dequeue(Queue &queue, int &value);
bool first(Queue &queue, int &value);

#endif