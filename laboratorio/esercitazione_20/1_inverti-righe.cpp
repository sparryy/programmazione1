#include <iostream>
#include <fstream>
#include "stack_int.h"
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

    int nIN;
    while(input >> nIN) {
        push(stack, nIN);
    }

    int nOUT;
    while(pop(stack, nOUT)) {
        output << nOUT << endl;
    }

    deinit(stack);

    return 0;
}