#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout <<"Inserisci due numeri interi: " << endl;
    cout <<"A: ";
    cin >> a;
    cout <<"B: ";
    cin >> b;

    bool diversi = a^b;
    bool uguali = !diversi;

    cout << "Uguali? " << uguali << endl;

    return 0;
}