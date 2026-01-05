#include <iostream>
using namespace std; 
//solo se una variabile è inizializzata fuori 
//da tutte le funzioni allora inizia a 0
int x;
int main() {
    /*
    le variabili sono caratterizzate da:
    nome
    tipo
    l-value (locazione in memoria)
    r-value (valore)
    */
    //per dichiarare una variabile che esiste (in un altro file)
    //e quindi non definirla allocando memoria si usa
    //extern int x;
    //si usa nei file header, si può usare anche per le func
    //se il numero è troppo grande dopo la conversione in binario 
    //allora va in overflow
    float ciao = -1235.6e-2;
    char Ciao;
    //il valore assegnato deve essere calcolabile in fase
    //di compilazione
    const char g = 'a';
    /*

    ////////////////////
    // stream di dati //
    ////////////////////

    in c++ esistono 3 stream(flussi di caratteri) associati a 
    dispositivi fisici (input: tastiera,file...)
    cin
    cout
    cerr
    per utilizzarli si usa #include <iostream>

    per scrivere dati sullo stream: stream << espressione1 << espressione2;
    per prelevare dati dallo stream: stream >> espressione1 >> espressione2;
    equivale a 
    stream >> espressione1;
    stream >> espressione2;

    se si prova a prelevare un tipo di dato dal cin
    esso viene letto finchè non viene trovato un 
    carattere non spazio e quando succede se è 
    compatibile allora lo ritorna e sposta il cursore
    se non lo è allora da errore

    ////////////////////////////
    // funzioni utili per cin //
    ////////////////////////////
    cin.eof() ritorna valore non 0 se cin ha raggiunto eof
    cin.fail() ritorna valore non 0 se c'è errore(stringa per int)
    cin.clear() ripristina stato normale
    */
    /*
    //////////
    // tipi //
    //////////
    fondamentali (int, short, char, enum, long long,long double)
    derivati (array, puntatori)

    per avere un numero senza segno: unsigned int x;
    per avere la dimensione di un tipo: sizeof(int)

    per convertire stringhe in altri tipi uso la funzione atoi, atod... 
    implementando #include <cstdlib>
    cambiando l'ultima lettera come serve(string to int, string to double)

    operazioni bitwise 
    x>>n shift a destra di n posizioni
    x<<n shift a sinistra di n posizioni
    x&y AND bit a bit tra x e y
    x|y OR bit a bit tra x e y
    x^y XOR bit a bit tra x e y
    ~x NOT, complemento bit a bit

    in c++ l'assegnazione ritorna l'lvalue:
    int y;
    int x = y = 9;

    per usare enumeratori enum identificatore { id_or_init1, ..., id_or_initn }
    //////////////////////
    // Utilizzo memoria //
    //////////////////////
    
    Area programmi: destinata a contenere le
    istruzioni (in linguaggio macchina) del
    programma
    Area dati statici: destinata a contenere
    variabili globali o allocate staticamente e le
    costanti del programma.
    Area heap: destinata a contenere le variabili
    dinamiche (di dimensioni non prevedibili a
    tempo di compilazione) del programma.
    Area stack: destinata a contenere le variabili
    locali e i parametri formali delle funzioni del
    programma.
    */
    return 0;
}