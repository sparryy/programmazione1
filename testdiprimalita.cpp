// 10 ottobre 2025

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    do {
        cout << "Inserisci un numero (0-1000): ";
        cin >> n;
        if(n < 0 || n > 1000) {
            cout << "!! Deve essere tra 0 e 1000 !!" << endl;
        }
    } while (n < 0 || n > 1000);

    if(n <= 1) {
        cout << n << " non è un numero primo" << endl;
        return 0;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            cout << n << " non è un numero primo" << endl;
            return 0;
        }
    }

    cout << n << " è un numero primo" << endl;

    return 0;
}
