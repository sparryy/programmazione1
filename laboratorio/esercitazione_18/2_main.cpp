#include <iostream>
#include "2_estrazione.h"

using namespace std;

int main() {
    char  string[EXT_UPPER_H_MAX_DIM];
    char *resultString;

    cout << "Inserisci una stringa senza spazi: " << endl;
    cin >> string;
    resultString = extractUppercase(string);
    cout << "Le lettere maiuscole sono: " << resultString << endl;

    delete[] resultString;

    return 0;
}
