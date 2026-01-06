#include <iostream>
using namespace std;

int main (){
    //i riferimenti permettono di dare nomi multipli alla stessa variabile
    int x = 0;
    char a = 'a';
    //l'inizializzazione è obbligatoria, e deve essere dello stesso tipo
    int &y = x; 
    y = 6; // quindi anche x = 6
    //l'operatore & ritorna l'indirizzo (L-value) dell'espressione
    cout << &x << endl;
    //i puntatori contengono come R-value l'indirizzo di un espressione
    //può contenere puntatori solo dello stesso tipo della definizione
    //lo spazio allocato per un puntatore è sempre lo stesso (ovviamente)
    int *z = &x;
    //per accedere alla variabile uso l'operatore * di dereference
    //in qesto caso *z diventa proprio x (hanno stesso valore e indirizzo)
    //quindi &x = &(*z) = z
    *z = 1;
    //se voglio avere un puntatore a variabili con tipo diverso
    void *w;
    w = &x;
    //devo dirgli che tipo è
    //ha senso perchè i puntatori hanno tutti r-value di grandezza uguale
    *(int*)w = 10; 
    w = &a;
    *(char*)w = 'b'
    //esistono anche puntatori costanti che non permettono la modifica tramite dereference
    //ma solo tramite la variabile originale
    const int *k = &x;
    //oppure puntatori costanti che non permettono di cambiare variabile a cui si punta
    int *const u = &x;
    //si possono anche usare entrambi allo stesso momento 
    //const int *const u;
    //si possono fare puntatori di puntatori
    //int **c = &z
    //se sommo a un puntatore un intero implicitamente moltiplica l'intero
    //per il sizeof(tipo)
    //se ho due puntatori di tipo uguale e li sottraggo
    //mi da il numero di posizioni di distanza tra le due variabili
    //in scala della grandezza del tipo
    //probabilmente per facilitare gestione degli array
    return 0;

}