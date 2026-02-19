#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Usage: exec <inputFile> <outputFile>" << endl;
        exit(0);
    }

    fstream input, output;

    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if(input.fail() || output.fail()) {
        cout << "Errore nell'apertura di un file!" << endl;
        exit(0);
    }

    char c;
    input.get(c);
    if(c >= 'a' || c <= 'z') {
        c = c - 'a' + 'A';
    }
    output << c;
    bool maiusc;
    input.get(c);
    while(!input.eof() && !input.fail()) {
        if(c == '.' || c == '!' || c == '?') {
            maiusc = true;
        }
        if('a' <= c && c <= 'z' && maiusc == true) {
            c = c - 'a' + 'A';
            maiusc = false;
        }
        if('A' <= c && c <= 'Z' && maiusc == true) {
            maiusc = false;
        }
        output << c;
        input.get(c);
    }
    
    input.close();
    output.close();

    return 0;
}