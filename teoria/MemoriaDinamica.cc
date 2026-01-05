#include <iostream>
using namespace std;

int main() {
    //l'allocazione dinamica permette di gestire la memoria durante l'esecuzione del programma
    //viene allocata nell'heap, gestendo l'accesso tramite puntatori 
    //l'allocazione e deallocazione fatta tramite new e delete
    int i;
    cin >> i;
    int *p, *q;
    char *stringa;
    int *a;
    //new alloca la memoria adeguata a seconda del tipo, la inizializza nel caso ci sia un valore
    //e ritorna il puntatore alla variabile
    p = new int;
    q = new int (5);
    //un'array dinamico è il puntatore del suo primo elemento
    //tutte le funzioni per le stringhe di <cstring> funzionano anche sulle stringhe dinamiche
    stringa = new char[3*i];
    a = new int[n];
    //cin lavora con i puntatori, quindi non serve deallocare
    //ATTENZIONE nel caso nel cin ci siano più caratteri di quanti predisposti allora si va in overflow
    cin >> stringa;
    //il primo carattere diventa c, serve deallocare in questo caso
    *stringa = 'c'
    //dopo l'utilizzo va sempre eliminato per evitare memory leak
    //nel caso di array di array dinamici avrei da cancellare prima gli array interni e poi quelli esterni
    //PER OGNI NEW CI SARA UN DELETE
    delete p;
    delete[] stringa;//se fosse una matrice dovrei deallocare prima le cose interne e poi questo
    return 0;
}