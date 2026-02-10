#include <iostream>
#include <cstdlib>
using namespace std;

const int N_ROW = 3;
const int N_COL = 4;

void popolaMatrice(int (&m)[][N_COL]) {
    for(int i = 0; i < N_ROW; i++){
        for(int j = 0; j < N_COL; j++) {
            m[i][j] = rand() % 10;
        }
    }
}

void stampa(int m[][N_COL]) {
    for(int i = 0; i < N_ROW; i++){
        for(int j = 0; j < N_COL; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

void stampaPuntArray(int * pArray) {
    for(int i = 0; i < N_ROW; i++){
        for(int j = 0; j < N_COL; j++) {
            cout << *(pArray + j + (i*N_COL)) << " ";
        }
        cout << endl;
    }
}

int main() {
    srand(time(NULL));
    int matrice[N_ROW][N_COL];
    int* pArray = *matrice;

    popolaMatrice(matrice);
    stampa(matrice);
    cout << "-------" << endl;
    stampaPuntArray(pArray);

    return 0;
}