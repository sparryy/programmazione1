// 10 ottobre 2025

#include <iostream>

using namespace std;

int main() {
    int n;

    do {
        cout << "Inserisci un numero: ";
        cin >> n;
        if(n < 0) {
            cout << "Inserisci un numero valido" << endl;
        }
    } while (n < 0);

    if (n <= 1) {
        cout << "F" << n << " = " << n << endl;
        return 0;
    }
	
    int prev1 = 1, prev2 = 0;
  	
  	int curr;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout << "F" << n << " = " << curr << endl;

    return 0;
}
