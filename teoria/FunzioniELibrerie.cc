//iostream è la header della standard library
//dove sono dichiarate le funzioni
//mentre nel file oggetto sono definite e compilate
//insieme formano una libreria
#include <iostream>
//esempio di una libreria per la matematica
#include <cmath> //prendono valori double e restituiscono valori double
/*
fabs(x): valore assoluto di tipo float
sqrt(x): radice quadrata di x
pow(x,y): eleva x alla potenza di y
exp(x): eleva e alla potenza di x
log(x): logaritmo naturale di x
log10(x): logaritmo in base 10 di x
sin(x) e asin(x): seno e arcoseno trigonometrico
cos(x) e acos(x): coseno e arcocoseno trigonometrico
tan(x) e atan(x): tangente e arcotangente trig.
*/
//esempio di una libreria per random
#include <cstdlib>
/*
abs(n): valore assoluto
rand(): numero pseudocasuale tra 0 e la costante RAND_MAX
srand(n): inizializza la funzione rand (per cambiare il seed)
*/
#include <cctype> //prendono valori char e restituiscono valori bool 
/*
isalnum(c): carattere alfabetico o cifra decimale
isalpha(c): carattere alfabetico
iscntrl(c): carattere di controllo
isdigit(c): cifra decimale
isgraph(c): carattere grafico, diverso da spazio
islower(c): lettera minuscola
isprint(c): carattere stampabile, anche spazio
isspace(c): spazio,salto pagina,nuova riga o tab.
isupper(c): lettera maiuscola
isxdigit(c): cifra esadecimale
tolower(c): rende tutto minuscolo (il valore ritornato è un char)
toupper(c): rende tutto maiuscolo
*/
using namespace std;
//dichiarazione di una funzione(l'identificatore della variabile è opzionale)
int ciao(int a);
//variabile globale, se non inizializzata sarà 0
int b;
//le funzioni vengono gestite tramite uno stack nella memoria(LIFO)
//perchè l'ultima funzione eseguita sarà la prima a finire
int main() {
    return 0;
    //variabile locale, muore alla fine della funzione 
    int a = 1;
    //chiamata di una funzione
    cout << ciao(1) << endl;
    //nella chiamata di funzioni con molteplici parametri, nel caso di uso di 
    //operazioni con "sideeffect" non è sicuro il comportamento, perchè
    //non è detto che un parametro venga valutato prima di un altro. es
    pow(a++,a++);
}

//definizione di una funzione 
//bisogna avere sempre un solo return
//così evito problemi nel caso manchi qualche return (compila comunque il codice)
//o nel caso di bug per una uscita implicita da una funzione
int ciao (int a){
    return a+1;
}
//i parametri sono anche detti parametri formali
//procedura, funzione che ritorna void
void ciaus (int b){}
//assegna ad a il valore passato, come se facesse a = ...
//può essere eseguito anche tramite un espressione senza l-value
//ad esempio parametroPerValore(2); -> int a = 2
//nel caso sia un tipo compatibile la conversione è implicita
//l'informazione è quindi duplicata
void parametroPerValore(int a) {}
//il valore assegnato deve essere un espressione con indirizzo
//l'informazione non viene duplicata
//se modifico il parametro formale, modifico il parametro attuale(la variabile iniziale)
void parametroPerRiferimento(int& a) {}
//se devo passare oggetti "grossi" senza doverli ricopiare ma senza poterli modificare
//posso passare per riferimento costante
void parametroPerRiferimentoCostante(const int& a) {}

//uso l'indirizzo dell'oggetto passato
//il parametro formale è un puntatore al parametro attuale
//molto simile al passaggio per riferimento
void parametroPerPuntatore(int * a)
//se voglio posso restituire un riferimento
//se lo eseguo con questa riga: restituireUnRiferimetno(a=9,b=3) = 4 allora a diventerà 4.
int& restituireUnRiferimento(int& a, int&b){
    //ritorna il maggiore
    return a > b ? a : b;
}
//i parametri opzionali sono gli ultimi e hanno valori di default
int parametriOpzionali(int a,int b = 0,int c = 0){}