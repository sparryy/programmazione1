#include <iostream>
#include <cstdlib>
using namespace std;

void popolaArray(int* puntatore, int DIM) {
    for(int i = 0; i < DIM; i++) {
        *(puntatore + i) = rand() % 10;
    }
}

void stampaArray(int* puntatore, int DIM) {
    cout << "{";
    for(int i = 0; i < DIM - 1; i++) {
        cout << *(puntatore + i) << " ";
    }
    cout << *(puntatore + DIM - 1) << "}" << endl;
}

int main() {
    srand(time(NULL));
    const int DIM = 10;
    int array[DIM];
    int* puntatore = array;

    popolaArray(puntatore, DIM);
    stampaArray(puntatore, DIM);

    return 0;
}