#include <iostream>
#include <cstdlib>
using namespace std;

int **generate_matrix(int rows, int cols);

int main(int argc, char *argv[]) {
    srand(time(NULL));

    if (argc != 3) {
        cout << "Usage: random-array <nRows> <nColums>" << endl;
        exit(0);
    }

    int rows = atof(argv[1]);
    int cols = atof(argv[2]);

    int **matrix = generate_matrix(rows, cols);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    
    delete[] matrix;

    cout << "matrice eliminata" << endl;
    
    return 0;
}

int **generate_matrix(int rows, int cols) {
    int **matrix = new int *[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}