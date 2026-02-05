#include <iostream>
using namespace std;

void controllaChar(char carattere) {
    if(carattere >= 'a' && carattere <= 'z') {
        cout << (char) (carattere - ('a'-'A')) << endl;
    } else {
        cout << "Non è un carattere minuscolo" << endl;
    }
}

int main() {
    char carattere;
    cout << "Inserisci un carattere minuscolo (a-z): ";
    cin >> carattere;

    controllaChar(carattere);

    return 0;
}