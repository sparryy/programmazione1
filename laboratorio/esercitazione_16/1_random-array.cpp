#include <iostream>
#include <cstdlib>
using namespace std;

int * generate_numbers(int length);

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cout << "Usage: random-array <length>" << endl;
        exit(0);
    }

    int length = atof(argv[1]);

    int *array = generate_numbers(length);

    for(int i = 0; i < length; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    delete[] array;

    
    return 0;
}

int * generate_numbers(int length) {
    int *arrayD = new int[length];
    for(int i = 0; i < length; i++) {
        arrayD[i] = rand() % 100;
    }
    return arrayD;
}