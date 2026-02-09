#include <iostream>
#include <cstdlib>
using namespace std;

void popolaArray(int (&array)[], int DIM) {
    for(int i = 0; i< DIM; i++) {
        array[i] = rand() % 10;
    }
}

void stampaArray(const int array[], int DIM) {
    cout << "[";
    for(int i = 0; i < DIM - 1; i++) {
        cout << array[i] << " ";
    }
    cout << array[DIM - 1] << "]" << endl;
}

void invertiArray(const int array[], int DIM) {
    int yarra[DIM];
    for(int i = 0; i < DIM; i++) {
        yarra[DIM - 1 - i] = array[i];
    }
    stampaArray(yarra, DIM);
}

int main() {
    srand(time(NULL));
    const int DIM = 10;
    int array[DIM];
    
    popolaArray(array, DIM);
    stampaArray(array, DIM);
    invertiArray(array, DIM);

    return 0;
}