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

void mediaMaxMin(int const array[], int DIM) {
    double media = 0;
    int min = array[1], max = array[1];
    for(int i = 0; i < DIM; i++) {
        media += array[i];
        if(array[i] < min) {
            min = array[i];
        }
        if(array[i] > max) {
            max = array[i];
        }
    }
    media = media / DIM;
    cout << "Media: " << media << " | Min: " << min << " | Max: " << max << endl;
}

int main() {
    srand(time(NULL));
    const int DIM = 10;
    int array[DIM];
    
    popolaArray(array, DIM);
    stampaArray(array, DIM);
    mediaMaxMin(array, DIM);

    return 0;
}