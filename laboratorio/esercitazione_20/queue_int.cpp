#include <iostream>
#include "queue_int.h"

bool isEmpty(Queue &queue);

void init(Queue &queue) {
    queue.back = NULL;
    queue.front = NULL;
}

void deinit(Queue &queue) {
    int tmp;
    while (dequeue(queue,tmp));
}

bool enqueue(Queue &queue, int value) {
    Node * newNode = new Node{value,NULL};

    if (isEmpty(queue))
    {
        queue.front = newNode;
        queue.back = newNode;
    }
    else
    {
        queue.back->next = newNode;
        queue.back = newNode;
    }
    
    return true;
}

bool dequeue(Queue &queue, int &value) {
    bool result;

    if (isEmpty(queue))
    {
        result = false;
    }
    else
    {
        value = queue.front->value;
        Node * deqNode = queue.front;
        queue.front = queue.front->next;
        delete deqNode;
        result = true;
    }
    return result;
}

bool first(Queue &queue, int &value) {
    bool result;

    if (isEmpty(queue)) {
        result = false;
    }
    else {
        value = queue.front->value;
        result = true;
    }
    return result;
}

bool isEmpty(Queue &queue) {
    return queue.front == NULL;
}