#include <iostream>
#include <fstream>
using namespace std;

const int N_ALFABETO = 26;

int indexChar(char c);

void stampa(int array[]);

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Usage: <exec> <input_file>" << endl;
        exit(0);
    }

    fstream input;
    input.open(argv[1], ios::in);
    if (input.fail()) {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
        exit(0);
    }

    int *array = new int[N_ALFABETO];

    char c;
    input.get(c);
    while(!input.eof() && !input.fail()) {
        int index = indexChar(c);
        if(index != -1) {
            array[index] = array[index] + 1;
        }
        input.get(c);
    }

    stampa(array);

    delete[] array;
    input.close();
    return 0;
}

int indexChar(char c) {
    int index = -1;
    if(c >= 'a' && c <= 'z') {
        index = c - 'a';
    } else if(c >= 'A' && c <= 'Z') {
        index = c - 'A';
    }
    return index;
}

void stampa(int array[]) {
    cout << "Totale lettere" << endl;
    for(int i = 0; i < N_ALFABETO; i++) {
        cout << (char)('a'+i) << ": " << array[i] << endl;
    }
}