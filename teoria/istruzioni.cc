#include <iostream>
using namespace std;
/*
un programma è un insieme di funzioni con la più importante essere il main
esistono due tipi di istruzioni: semplici e strutturate
semplici: alla base delle complesse, finiscono sempre con ;
(dichiarazioni, input, assegnamento, condizionale(x?y:z)...)
strutturate: per azioni complesse
(condizionali, iterative, salti, composta(blocco tra le graffe))

*/
int main() {
    /////////////////
    // strutturate //
    /////////////////
    
    // composta

    {
        int x;
        x = 2;
        x *= 10;
    }

    // condizionale
    int c;
    if(true)
        //possono essere un blocco
        c = 10;
    else
        c = 12;

    //condizionale switch
    switch (c) {
        case 10: c = 0; break;
        case 12: c = 1; break;
        default: c = -1;
    }

    //iterativa while 

    while (c < 0) 
        //può essere un blocco
        c++;
    //iterativa do while
    do { 
        c++ 
    } while (c < 10);

    //iterativa for
    for (int i = 0; i < 10; i++)
        c += 10;

    //istruzioni di salto (NON USARE MAI)
    /*
    while (...) {
    ...
    //nel caso di utilizzo l'esercizio di esame viene annullato
    return 0; // oppure break o continue o goto
    ... // |
    } // |
    */
    return 0;
}