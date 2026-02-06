#include <iostream>
using namespace std;
#include <cstdlib>

void generalancio(int& totale);

int main() {
    srand(time(NULL));

    int tentativo, nUno = 0;

    cout << "Indovina quanti 1 verranno fuori: ";
    cin >> tentativo;

    generalancio(nUno);

    cout << "Totale di uno: " << nUno << endl;

    if(tentativo == nUno) {
        cout << "Bravo hai indovinato!" << endl;
    } else {
        cout << "Non hai indovinato..." << endl;
    }
    
    return 0;
}

void generalancio(int& totale) {
    totale = 0;

    for (int i = 0; i < 10; i++) {
        int random_number = rand() % 6 + 1;

        if(random_number == 1) {
            totale++;
        }
    }
}