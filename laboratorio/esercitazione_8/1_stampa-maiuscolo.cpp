#include <iostream>
using namespace std;

bool controllaChar(char carattere) {
    return (carattere >= 'a' && carattere <= 'z');
}

int main() {
    char carattere;
    cout << "Inserisci un carattere minuscolo (a-z): ";
    cin >> carattere;

    if(controllaChar(carattere)) {
        cout << (char) (carattere - ('a'-'A')) << endl;
    } else {
        cout << "Non è un carattere minuscolo" << endl;
    }

    return 0;
}