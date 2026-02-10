#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int length = 9;
void init(double[][length]);
void print(const double matrix[][length]);
void avgFilter(const double matrix[][length], double filteredMatrix[][length]);

int main(){
    srand(time(NULL));
    double matrix[length][length];
    double filteredMatrix[length][length];
    init(matrix);
    print(matrix);
    avgFilter(matrix,filteredMatrix);
    print(filteredMatrix);
    return 0;
}

void init(double matrix[][length]) {
    for (int r = 0; r < length ; r++) {
        for (int c = 0 ; c < length ; c++) {
            matrix[r][c] = (double(rand())/RAND_MAX)*10;
        }
    }
}
void print(const double matrix[][length]) {
    for (int r = 0 ; r < length; r++) {
        for (int c = 0 ; c < length; c++) {
            cout << matrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void avgFilter(const double matrix[length][length], double filteredMatrix[length][length]){
    for (int h = 0; h < length; h++) {
        for (int k = 0; k < length; k++) {
            double sum = 0.0;
            int n = 0;
            if (k - 1 >= 0) { // left
                sum += matrix[h][k - 1];
                n++;
            }
            if (k + 1 < length) { // right
                sum += matrix[h][k + 1];
                n++;
            }
            if (h - 1 >= 0) { // up
                sum += matrix[h - 1][k];
                n++;
            }
            if (h + 1 < length) { // down
                sum += matrix[h + 1][k];
                n++;
            }
            filteredMatrix[h][k] = sum / n;
        }
    }
}