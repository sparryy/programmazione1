#include <iostream>
#include <fstream>
#include "3_email.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: verifyemail <input_file>" << endl;
        exit(0);
    }

    fstream input;
    input.open(argv[1], ios::in);

    if (input.fail())
    {
        cout << "Il file " << argv[1] << " non esiste!" << endl;
        exit(1);
    }

    char word[256];

    while (input >> word) {
        cout << word << ": " ;
        if (verifyEmail(word)) {
            cout << "e' una mail valida! " << endl;
        } else {
            cout << "NON e' una mail valida! " << endl;
        }
    };


    return 0;
}