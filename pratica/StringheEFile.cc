#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
    //dalla libreria <cstdlib>
    int n = std::atoi(argv[2]); //oppure stoi() per tradurre un argomento di cmd in int (atof per i float)
    char stringa[256];
    char carattere;
    cin.eof(); //diverso da 0 se cin ha finito il file
    cin.fail();//diverso da 0 se cin ha errore(str into int)
    cin.clear();//ripristina lo stato del cin dopo un errore
    //nel caso di uso del delimitatore, questo non verrà memorizzato
    //il delimitatore di default è \n, usato nella getline normale
    //legge una linea di input contenente anche possibili spazi
    cin.getline(stringa,10); //oppure cin.getline(buffer, dimensione, delimitatore);
    cin.get(carattere);//legge da cin un singolo carattere(anche spazio) e lo restituisce (\0 se il file è finito)
    cout.put(carattere);//scrive su cout il carattere, più preciso di cout e più veloce in un ciclo continuo dove controllo un carattere alla volta

    ///////////////////////
    // Funzioni Stringhe //
    ///////////////////////

    strlen(stringa);//restituisce la lunghezza di una stringa escluso \0
    strchr(stringa,carattere);//restituisce un puntatore alla prima occorrenza oppure null
    strrchr(stringa,carattere);//restituisce un puntatore alla ultima occorrenza oppure null
    strstr(stringa,"ciao");//restituisce un puntatore alla prima occorrenza di una sottostringa o null
    strcpy(string,"ciao")://copia ciao in string e restituisce string
    strncpy(string,"ciao",2)://copia due caratteri di ciao in string, se non c'è \0 in ciao la stringa sarà malformata
    strcat(string,"ciao")://concatena ciao dopo string e ritorna string
    strncat(string,"ciao",3)://concatena i primi 3 caratteri di ciao dopo string e aggiunge \0 alla fine, poi ritorna string
    strcmp(string,"ciao");//restituisce un valore negativo,nullo o positivo se string è minore, uguale o maggiore di ciao

    ////////////
    // Stream //
    ////////////

    fstream instream,outstream;//definizione stream
    instream.open("nomefile.txt",ios::in);//apre lo stream in lettura
    outstream.open("nomefile2.txt",ios::out)//apre lo stream in scrittura
    outstream.open("nomefile2.txt",ios::out|ios::app) //apre lo stream in scrittura e ogni scrittura avviene sempre (forzatamente) alla fine del file senza sovrascriverlo
    if (!instream.is_open()) {
        cout << "Apertura fallita\n";
        return 1;
    }
    //errore generico
    if (file.fail()) {
        cout << "Errore apertura\n";
    }
    instream >> stringa;
    outstream << stringa;
    instream.getline(stringa,10)
    instream.close()
    return 0;
}