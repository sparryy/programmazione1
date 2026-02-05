#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n_bin;
    int n_dec = 0;

    cout << "Inserisci un numero binario: ";
    cin >> n_bin;

    int bit = 0;
    while(n_bin > 0) {
        n_dec += (n_bin % 10)*pow(2, bit);
        n_bin /= 10;
        bit++;
    }

    cout << "In decimale è: " << n_dec << endl;

    return 0;
}