#include <iostream>
#include <cstdlib>
using namespace std;

void popolaArray(double (&array)[], int DIM) {
    for(int i = 0; i< DIM; i++) {
        cout << "Inserisci elemento [" << i << "]: ";
        cin >> array[i];
    }
}

void stampaArray(const double array[], int DIM) {
    cout << "[";
    for(int i = 0; i < DIM - 1; i++) {
        cout << array[i] << " ";
    }
    cout << array[DIM - 1] << "]" << endl;
}

int intervallo(double (&array)[], int DIM, double x, double y) {
    if(x < y) {
        int assegnamenti = 0;
        for(int i = 0; i < DIM; i++) {
            if(array[i] < x || array[i] > y) {
                array[i] = 0;
                assegnamenti++;
            }
        }
        return assegnamenti;
    } else {
        return -1;
    }
}

int main() {
    srand(time(NULL));
    const int DIM = 10;
    double array[DIM];
    double x, y;

    popolaArray(array, DIM);
    stampaArray(array, DIM);
    cout << "Inizio intervallo: ";
    cin >> x;
    cout << "Fine intervallo: ";
    cin >> y;

    cout << "Ci sono stati " << intervallo(array, DIM, x, y) << " assegnamenti" << endl;
    stampaArray(array, DIM);

    return 0;
}