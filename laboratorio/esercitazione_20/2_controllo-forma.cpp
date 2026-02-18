#include <iostream>
#include <fstream>
#include "stack_char.h"
using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Usage: exec <file>" << endl;
        exit(0);
    }

    fstream input, output;
    input.open(argv[1], ios::in);

    if(input.fail()) {
        cout << "Errore apertura file!" << endl;
        exit(0);
    }

    Stack stack;
    init(stack);

    char c;
    input.get(c);
    while(!input.eof() && !input.fail()) {
        if(c == '(' || c == ')') {
            push(stack, c);
        }
        input.get(c);
    }

    bool bilanciato = true;
    int count = 0;
    while(pop(stack, c) && bilanciato) {
        if(c == ')') {
            count++;
        } else if (c == '(') {
            count--;
        }
        cout << count << endl;
        if(count < 0) {
            bilanciato = false;
        }
    }
    if(count != 0) {
        bilanciato = false;
    }

    cout << "Le parentesi";
    if (!bilanciato) {
        cout << " non"; 
    }
    cout << " sono bilanciate" << endl;

    deinit(stack);

    return 0;
}