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

void inserimento(int (&array)[], int DIM, int val, int pos) {
    if(pos >= 0 && pos < DIM) {
        for(int i = DIM - 1; i > pos; i--) {
            array[i] = array[i-1];
        }
        array[pos] = val;
    } else {
        cout << "!Posizione non valida!" << endl;
    }
}

int main() {
    srand(time(NULL));
    const int DIM = 10;
    int array[DIM];
    int val, pos;
    
    popolaArray(array, DIM);
    stampaArray(array, DIM);
    
    cout << "Inserisci un nuovo elemento: ";
    cin >> val;
    cout << "A che posizione?: ";
    cin >> pos;
    
    inserimento(array, DIM, val, pos);
    stampaArray(array, DIM);

    return 0;
}