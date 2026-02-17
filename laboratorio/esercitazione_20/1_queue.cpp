#include <iostream>
#include <fstream>
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

    Queue queue;
    init(queue);

    int nIN;
    while(input >> nIN) {
        enqueue(queue, nIN);
    }

    int nOUT;
    while(dequeue(queue, nOUT)) {
        output << nOUT << endl;
    }

    deinit(queue);

    return 0;
}