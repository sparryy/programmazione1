// 10 ottobre 2025

#include <iostream>

using namespace std;

int main() {
    int n, n1;

    do {
        cout << "Inserisci un numero POSITIVO: ";
        cin >> n;
        if(n <= 0) {
            cout << "!! Deve essere positivo !!" << endl;
        }
    } while (n <= 0);

    n1 = n;

    int count = 1;

    while (n / 10 != 0) {
        n /= 10;
        count++;
    }
    
    cout << n1 << " ha " << count << " cifre" <<endl;

    return 0;
}
