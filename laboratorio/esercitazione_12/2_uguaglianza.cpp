#include <iostream>
#include <cstdlib>
using namespace std;

void randomizzaArray(int (&array)[], int DIM, int val_max) {
    for(int i = 0; i < DIM; i++) {
        array[i] = rand() % val_max + 1;
    }
}

void stampaArray(const int array[], int DIM) {
    cout << "[";
    for(int i = 0; i < DIM - 1; i++) {
        cout << array[i] << " ";
    }
    cout << array[DIM - 1] << "]" << endl;
}

int controlla(const int array1[], const int array2[], int DIM){
    int controlla = 0;
    for(int i = 0; i < DIM; i++) {
        if(array1[i] == array2[i]) {
            controlla++;
        }
    }
    return controlla;
}

int main() {
    srand(time(NULL));
    const int DIM = 10;
    int array1[DIM];
    int array2[DIM];
    int val_max;

    do {
        cout << "Inserisci il valore massimo:";
        cin >> val_max; }

    while(val_max > RAND_MAX || val_max < 0);

    randomizzaArray(array1, DIM, val_max);
    randomizzaArray(array2, DIM, val_max);
    stampaArray(array1, DIM);
    stampaArray(array2, DIM);
    cout << "Ci sono " << controlla(array1, array2, DIM) << " elementi uguali" << endl;
    return 0;
}
