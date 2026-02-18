#include <iostream>
#include <fstream>
#include "stack_int.h"
#include "queue_int.h"
using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Usage: exec <fileInput> <fileOutput>" << endl;
        exit(0);
    }

    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if(input.fail() || output.fail()) {
        cout << "Errore apertura file!" << endl;
        exit(0);
    }

    Stack stack;
    init(stack);
    Queue queue;
    init(queue);

    int n;
    while(input >> n) {
        push(stack, n);
    }

    while(pop(stack, n)) {
        enqueue(queue, n);
    }

    while(dequeue(queue, n)) {
        output << n << endl;
    }

    deinit(stack);
    deinit(queue);

    return 0;
}