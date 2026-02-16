#include <iostream>
#include <fstream>
#include "1_caesar.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage: caesar <input_file> <output_file> <key>" << endl;
        exit(0);
    }

    fstream input, output;
    char    word[256];
    bool    toBeCrypted;

    char option;
    cout << "Quale operazione vuoi eseguire (c/d)? ";
    cin >> option;

    if (option == 'c') {
        toBeCrypted = true;
    } else {
        toBeCrypted = false;
    }


    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);

    if (input.fail()) {
        cout << "Errore nell'apertura dell'input" << endl;
        exit(1);
    }


    int key = atoi(argv[3]) % 26;

    while (input >> word) {
        if (toBeCrypted) {
            crypt(word, key);
        } else {
            decrypt(word, key);
        }
        output << word << " ";
    }
    cout << endl;


    input.close();
    output.close();

    return 0;
}
