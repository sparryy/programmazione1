#include <iostream>
using namespace std;
//una struttura è una collezione ordinata di elementi non omogenei, detti campi
//ciascun campo può essere un tipo di struttura
//definisco gli struct fuori dal main così posso usarli anche nelle altre funzioni
struct data {
    int giorno, mese, anno;
};
struct persona {// struttura annidata
    char nome[25], cognome[25];
    char comune_nascita[25];
    data data_nascita;
    enum { F, M } sesso;
};
struct studente {
    persona generalita;
    char matricola[10];
    int anno_iscrizione;
};
struct ricorsivo {
    int valore;
    //ricorsivo prossimo; non valido
    //valido, si può lasciare indefinito o nullptr
    ricorsivo* prossimo;
}
int main() {
    persona p = {"mario","rossi","Trento",{1,1,2000},M};
    persona *pp = &p;
    //per accedere ad un campo
    strcpy(p.nome, "dario"); //perchè gli array non sono assegnabili
    //p.nome = "dario";
    //equivalenti
    strcpy((*pp).nome, "fario");
    //(*pp).nome = "fario";
    strcpy(pp->nome, "dario");
    //pp->nome = "zario";
    //funziona a differenza degli array
    //copia tutti i campi, anche nel caso di un array statico 
    //quindi se voglio copiare array posso incapsularli dentro a struct
    //nel caso di uso di array dinamici, la copia non comporta la duplicazione 
    //dell'array ma il puntatore sarà lo stesso, quindi modificandolo in uno struct
    //verrà modificato anche nell'altro
    persona x = p;
    return 0;
}
//possono essere passati per parametro e possono essere ritornati
//a differenza degli array
persona func(persona p){

}