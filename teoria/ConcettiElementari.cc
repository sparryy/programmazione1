/*
il namespace organizza funzioni insieme, 
usando using elimino il dover chiamare la funzione 
attraverso il namespace e la chiamo direttamente
*/

// inserisce il contenuto di questo file nel file corrente  
#include <iostream>
using namespace std;

int main (){
    //manda dati in output standard (solitamente terminale)
    //operatore << è inserimento nel flusso
    cout << "ciao a tutti" << endl;
    //gli identificatori devono iniziare sempre con una lettera ("_" è una lettera) 
    //è case sensitive
    float ciao = -1235.6e-2;
    char Ciao;
    return 0;
}

// per buildare un file con g++ e eventualmente dargli un nome (senza -o builda in a.out) si usa:
//g++ file.cc -o file.cc
// per compilare senza linkare, e poi linkare separatamente
//g++ -c file.cc
//g++ prova.o -o prova