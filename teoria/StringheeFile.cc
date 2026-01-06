#include <iostream>
//permette la creazione di stream per leggere e scrivere su file
//fstream eredita da iostream tutti i suoi operatori e funzioni (getline,eof,<<,...)
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
    //una stringa è un array di char con ultimo carattere il carattere nullo '\0'
    //la dimensione di questi array sarà quindi 5
    char stringa[] = "Ciao"; //permesso solo nella inizializzazione perchè negli array non esiste l'assegnazione
    char stringa2[] = {'C','i','a','o','\0'};
    char buffer[256];
    //questi operatori operano direttamente sulle stringhe
    //memorizza finchè non incontra una spaziatura (che non viene letta)
    //come spazio, tabulazione, invio
    //e memorizza \0 come ultimo carattere
    cin >> buffer;
    //scrive in sequenza i caratteri della stringa finchè non raggiunge un \0
    cout << buffer;

    cin.getline(stringa,10); //oppure cin.getline(buffer, dimensione, delimitatore);
    cin.get(carattere);//legge da cin un singolo carattere(anche spazio) e lo restituisce (\0 se il file è finito)
    cout.put(carattere);//scrive su cout il carattere, più preciso di cout e più veloce in un ciclo continuo dove controllo un carattere alla volta

    //in c++ si possono passare argomenti da linea di comando tramite parametri del main
    //argc è il numero delle parole della linea di comando (incluso ./a.out)
    //argv è l'array di puntatori a stringhe dove vengono copiate le parole della linea di comando argv[1] → primo argomento.. argv[argc] → nullptr
    //per tradurre gli argomenti in int:
    //int n = std::stoi(argv[2]);

    //per definire uno stream
    fstream instream,outstream;//definizione stream
    instream.open("nomefile.txt",ios::in);//apre lo stream in lettura, con il puntatore all'inizio dello stream
    //nel caso il file non esiste viene creato per gli outstream
    outstream.open("nomefile2.txt",ios::out)//apre lo stream in scrittura, con il puntatore all'inizio dello stream, sovrascrivendo il file
    outstream.open("nomefile2.txt",ios::out|ios::app) //apre lo stream in scrittura e ogni scrittura avviene sempre (forzatamente) alla fine del file senza sovrascriverlo

    instream >> stringa;
    outstream << stringa;
    instream.getline(stringa,10)
    //buona prassi chiudere gli stream quando non più necessari
    instream.close();
    outstream.close();
    return 0;
}