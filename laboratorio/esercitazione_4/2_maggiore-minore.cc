#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout <<"Inserisci due numeri interi: " << endl;
    cout <<"A: ";
    cin >> a;
    cout <<"B: ";
    cin >> b;

    int max = a*(a>=b) + b*(a<b);
    int min = (a+b)-max;

    cout << "Max = " << max << " - Min = " << min << endl;

    return 0;
}