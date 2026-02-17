#include <iostream>
#include <fstream>
using namespace std;

// Struttura del nodo
struct Nodo {
    int valore;
    Nodo* prossimo;
};

typedef Nodo* lista;

lista creaListaDaFile(char* fileName);
void inserisciCoda(Nodo*& testa, int val);
void distruggiLista(lista &listaDiNumeri);
void stampaLista(lista listaDiNumeri);


int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Usage: exec <file>" << endl;
        exit(0);
    }
    
    char *nomeFile = argv[1];
    
    // Creazione lista
    lista miaLista = creaListaDaFile(nomeFile);

    // Stampa
    cout << "Lista letta dal file:" << endl;
    stampaLista(miaLista);

    // Distruzione
    distruggiLista(miaLista);

    // Controllo caso limite
    cout << "Dopo distruzione:" << endl;
    stampaLista(miaLista);

    return 0;
}

lista creaListaDaFile(char* fileName) {
    fstream input;
    lista testa = nullptr;
    int numero;

    input.open(fileName, ios::in);
    if (input.fail()) {
        cout << "Errore apertura file!" << endl;
        exit(0);
    }

    while (input >> numero) {
        inserisciCoda(testa, numero);
    }

    input.close();
    return testa;
}

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

void distruggiLista(lista &listaDiNumeri) {
    Nodo* temp;

    while (listaDiNumeri != nullptr) {
        temp = listaDiNumeri;
        listaDiNumeri = listaDiNumeri->prossimo;
        delete temp;
    }
}

// Funzione per stampare la lista
void stampaLista(lista listaDiNumeri) {
    if (listaDiNumeri == nullptr) {
        cout << "Lista vuota." << endl;
        return;
    }

    Nodo* temp = listaDiNumeri;
    while (temp != nullptr) {
        cout << temp->valore << " -> ";
        temp = temp->prossimo;
    }
    cout << "NULL" << endl;
}