#include <iostream>
#include <fstream>
using namespace std;

// Struttura del nodo
struct Nodo {
    int valore;
    Nodo* prossimo;
};

// Funzione per inserire in coda
void inserisciCoda(Nodo*& testa, int val) {
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->prossimo = nullptr;

    if (testa == nullptr) {
        testa = nuovo;
    } else {
        Nodo* temp = testa;
        while (temp->prossimo != nullptr) {
            temp = temp->prossimo;
        }
        temp->prossimo = nuovo;
    }
}

// Funzione per stampare la lista
void stampaLista(Nodo* testa) {
    Nodo* temp = testa;
    while (temp != nullptr) {
        cout << temp->valore << " -> ";
        temp = temp->prossimo;
    }
    cout << "NULL" << endl;
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Usage: exec <file>" << endl;
        exit(0);
    }
    
    Nodo* testa = nullptr;
    
    fstream input;
    input.open(argv[1], ios::in);
    
    if(input.fail()) {
        cout << "Errore apertura file!" << endl;
        exit(0);
    }
    
    int numero;
    // Lettura numeri dal file
    while (input >> numero) {
        inserisciCoda(testa, numero);
    }

    input.close();

    // Stampa lista creata
    cout << "Lista concatenata:" << endl;
    stampaLista(testa);

    return 0;
}
