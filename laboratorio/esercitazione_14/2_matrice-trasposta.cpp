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

void calcolaTrasposta(int m[][DIM]) {
    int tras[DIM][DIM];
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++) {
            tras[i][j] = m[j][i];
        }
    }
    stampa(tras);
}

int main() {
    srand(time(NULL));
    int matrice[DIM][DIM];

    popolaMatrice(matrice);
    stampa(matrice);
    cout << "-------" << endl;
    calcolaTrasposta(matrice);

    return 0;
}