#include <iostream>
#include <cstdlib>
using namespace std;

void randomizzaArray(int array[]);

void stampaArray(const int array[]);

int controlla(const int array1[], const int array2[]);


int main() {
    srand(time(NULL));
    int dim;
    cout << "Seleziona la dimensione degli array: ";
    cin >> dim;

    int array1[dim];
    int array2[dim];

    randomizzaArray(array1);
    randomizzaArray(array2);
    stampaArray(array1);
    stampaArray(array2);
    cout << "Ci sono " << controlla(array1, array2) << " elementi uguali" << endl;
    return 0;
}

void randomizzaArray(int array[], int& dim) {

}

void stampaArray(const int array[]) {

}

int controlla(const int array1[], const int array2[]){
    return 0;
}