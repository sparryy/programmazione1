#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++) {
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    return 0;
}