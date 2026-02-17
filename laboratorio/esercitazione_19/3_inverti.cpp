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
void inserisciTesta(lista &testa, int val);
void stampaListaInvertita(lista listaDiNumeri);
lista nuovaListaInvertita(lista listaDiNumeri);
void invertiLista(lista listaDiNumeri);


int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Usage: exec <file>" << endl;
        exit(0);
    }
    
    char *nomeFile = argv[1];
    
    lista miaLista = creaListaDaFile(nomeFile);

    cout << "Lista originale:" << endl;
    stampaLista(miaLista);

    // Stampa invertita (ricorsiva)
    cout << "\nStampa invertita (ricorsiva):" << endl;
    stampaListaInvertita(miaLista);
    cout << "NULL" << endl;

    // Nuova lista invertita
    lista copiaInvertita = nuovaListaInvertita(miaLista);
    cout << "\nNuova lista invertita:" << endl;
    stampaLista(copiaInvertita);

    // Inversione della lista originale
    invertiLista(miaLista);
    cout << "\nLista originale dopo inversione:" << endl;
    stampaLista(miaLista);

    // Distruzione
    distruggiLista(miaLista);
    distruggiLista(copiaInvertita);
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

void stampaListaInvertita(lista listaDiNumeri) {
    if (listaDiNumeri == nullptr)
        return;

    stampaListaInvertita(listaDiNumeri->prossimo);
    cout << listaDiNumeri->valore << " -> ";
}

void inserisciTesta(lista &testa, int val) {
    Nodo* nuovo = new Nodo;
    nuovo->valore = val;
    nuovo->prossimo = testa;
    testa = nuovo;
}

lista nuovaListaInvertita(lista listaDiNumeri) {
    lista nuova = nullptr;

    while (listaDiNumeri != nullptr) {
        inserisciTesta(nuova, listaDiNumeri->valore);
        listaDiNumeri = listaDiNumeri->prossimo;
    }

    return nuova;
}

void invertiLista(lista listaDiNumeri) {
    Nodo* prev = nullptr;
    Nodo* curr = listaDiNumeri;
    Nodo* next = nullptr;

    while (curr != nullptr) {
        next = curr->prossimo;
        curr->prossimo = prev;
        prev = curr;
        curr = next;
    }

    listaDiNumeri = prev;
}