#include <iostream>
using namespace std;

int invertinumero(int numero);

int main() {
    int numero;
    
    cout << "Inserisci un numero: ";
    cin >> numero;
    
    cout << invertinumero(numero) << endl;
    
    return 0;
}

int invertinumero(int numero) {
    int numeroinverso = 0;
    while (numero != 0) {
        numeroinverso *= 10;
        numeroinverso += numero % 10;
        numero /= 10;
    }
    return numeroinverso;
}