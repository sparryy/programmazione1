#include <iostream>
#include <cstdlib>
#include <ctime>
#include "5_tris.h"

using namespace std;

const int LEN = 3;

void resetMatrix(char matrix[LEN][LEN]) {
    for (int i = 0; i < LEN; ++i)
        for (int j = 0; j < LEN; ++j)
            matrix[i][j] = ' ';
}

void printMatrix(const char matrix[LEN][LEN]) {
    cout << "\n";
    for (int i = 0; i < LEN; ++i) {
        for (int j = 0; j < LEN; ++j) {
            cout << " " << matrix[i][j];
            if (j < 2) cout << " |";
        }
        cout << "\n";
        if (i < 2) cout << "---|---|---\n";
    }
    cout << "\n";
}

bool playMove(char matrix[LEN][LEN], bool userMove, char userSymbol, char computerSymbol) {
    int cell, row, col;
    char symbol = userMove ? userSymbol : computerSymbol;

    do {
        if (userMove) {
            cout << "Inserisci la cella (1-9) in cui giocare: ";
            cin >> cell;
        } else {
            cell = rand() % 9 + 1;
            cout << "Il computer sceglie la cella: " << cell << "\n";
        }        
        // converto la posizione in righe e colonne
        row = (cell - 1) / LEN;
        col = (cell - 1) % LEN;

    } while (matrix[row][col] != ' ' || cell < 1 || cell > 9 );

    matrix[row][col] = symbol;
    return true;
}

char checkWin(const char matrix[LEN][LEN], bool userMove, char userSymbol, char computerSymbol) {
    bool win = false;
    char symbol = userMove ? userSymbol : computerSymbol;
    for (int i = 0; i < LEN; ++i) {
        // controllo colonne e righe
        if ((matrix[i][0] == symbol && matrix[i][1] == symbol && matrix[i][2] == symbol) ||
            (matrix[0][i] == symbol && matrix[1][i] == symbol && matrix[2][i] == symbol))
            win = true;
    }
    
    // controllo le diagonali
    if ((matrix[0][0] == symbol && matrix[1][1] == symbol && matrix[2][2] == symbol) ||
        (matrix[0][2] == symbol && matrix[1][1] == symbol && matrix[2][0] == symbol))
        win = true;

    bool draw = true;
    for (int i = 0; i < LEN; ++i)
        for (int j = 0; j < LEN; ++j)
            if (matrix[i][j] == ' ')
                draw = false;

    return win?(userMove?'u':'c'):(draw?'d':'n');
}

void startGame() {
    char matrix[LEN][LEN];
    
    srand(time(NULL));

    bool continuePlay = false;

    do {
        resetMatrix(matrix);

        bool userMove = rand() % 2;
        char userSymbol = 'X';
        char computerSymbol = 'O';

        cout << "Inizia il gioco del tris!\n";
        if (userMove) {
            cout << "Inizia l'utente!\n";
        } else {
            cout << "Inizia il computer!\n";
        }

        
        printMatrix(matrix);
        char check = 'n';
        do{
            playMove(matrix, userMove, userSymbol, computerSymbol);
            printMatrix(matrix);
            check = checkWin(matrix, userMove , userSymbol , computerSymbol);
            switch(check){
                case 'u':{
                    cout << "Hai vinto!\n";
                    break;
                }
                case 'c':{
                    cout << "Il computer ha vinto!\n";
                    break;
                }
                case 'd':{
                    cout << "Pareggio!\n";
                    break;
                }
                case 'n':{
                    userMove = !userMove;
                    break;
                }
                default:{

                }
            }
        }while(check == 'n');
        
        char choice = 'n';
        do{
            cout << "Vuoi giocare ancore (y/n)? ";
            cin >> choice;
        }while(!(choice=='y' xor choice=='n'));
        continuePlay = choice=='y';
    } while(continuePlay);
}
