#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout <<"Inserisci due numeri interi: " << endl;
    cout <<"A: ";
    cin >> a;
    cout <<"B: ";
    cin >> b;

    cout << "Valore assoluto di (a-b) = " << (a-b)*((a>b)-(a<b)) << endl;

    return 0;
}