#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int casuale;
    int prova;
    int num = 0;

    srand(time(NULL));

    casuale = rand() % 11 + 5;
    cout << "Indovina il numero tra 5 e 15 ";
    while (true) {
        num++;
        cin >> prova;
        if(prova != casuale) {
            cout << "Sbagliato riprova: ";
        } else {
            cout << "hai indovinato in " << num << " tentativi"<< endl;
            break;
        }
    }
    return 0;
}