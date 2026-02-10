#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM = 3;

void popolaMatrice(int (&m)[][DIM]) {
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++) {
            m[i][j] = rand() % 10;
        }
    }
}

void stampa(int m[][DIM]) {
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int calcolaTriangoloSup(int (&m)[][DIM]) {
    int somma = 0;
    for(int i = 0; i < DIM; i++){
        for(int j = i; j < DIM; j++) {
            somma += m[i][j];
        }
    }
    return somma;
}

int main() {
    srand(time(NULL));
    int matrice[DIM][DIM];

    popolaMatrice(matrice);
    stampa(matrice);
    cout << "La somma del triangolo superiore è " << calcolaTriangoloSup(matrice) << endl;

    return 0;
}