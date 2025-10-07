// 10 ottobre 2025

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    do {
        cout << "Inserisci un numero (>0): ";
        cin >> n;
        if(n < 0) {
            cout << "!! Deve essere maggiore di 0 !!" << endl;
        }
    } while (n < 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n-i); j++) {
            cout << " ";
        }
        for (int j = 1; j <= (i*2 - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
