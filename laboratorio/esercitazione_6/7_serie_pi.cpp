#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    cout << "Inserisci il limite della serie: ";
    cin >> num;

    double ris = 0;
    for(int i = 1; i <= num; i++) {
        ris += 1/pow(i, 2);
    }

    cout << "Il risultato della serie è: " << ris << endl;
    return 0;
}