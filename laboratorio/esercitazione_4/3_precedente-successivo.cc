#include <iostream>
using namespace std;

int main() {
    int x;

    cout <<"Inserisci un numero intero: ";
    cin >> x;

    cout << "Precedente: " << (--x)++ << " | Successivo: " << (++x) << endl;

    return 0;
}