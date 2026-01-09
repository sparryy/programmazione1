#include <iostream>
using namespace std;

int main() {
    int a = 5, b = 9;

    cout << "A: " << a << " - B: " << b << endl;

    a += b;
    b = a - b;
    a -= b;

    cout << "A: " << a << " - B: " << b << endl;

    return 0;
}