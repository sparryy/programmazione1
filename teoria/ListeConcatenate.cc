#include <iostream>
using namespace std;
//il nodo finale può puntare a null, ad un nodo fittizio o a quello iniziale
//visto che è una lista concatenata la creo dinamicamente, tramite new nodo
//dovrò ricordarmi di deallocarla
//si tiene sempre traccia del primo nodo
// NEL CASO DI ALCUNE FUNZIONI IL NODO AL POSTO DI ESSERE ELIMINATO VIENE RITORNATO
// CONTROLLARE DI ELIMINARLO NEL MAIN ALTRIMENTI AVVENGONO MEMORY LERAKS
struct nodo {
    int valore;
    nodo * next;
}
//esistono anche le liste doppiamente concatenate
struct nododoppio {
    int valore;
    nodo * next;
    nodo * previous;
}

int main() {
    return 0;
}
//per liste non circolari
int length (nodo * s) {
    int l = 0;
    for( ; s != NULL; s = s->next) 
        l++;
    return l;
}
//per liste circolari
int length (nodo * s, nodo * x) {
    int l = 0;
    if (s != NULL) {
        l = 1;
    for(s = s->next; s != x; s = s->next) 
        l++;
    }
    return l;
}
//inserisco t dopo x
void insert_node(nodo * x, nodo *t) {
    if(x != NULL && t != NULL){
        t -> next = x -> next;
        x -> next = t;
    }
}
//cambio il nodo iniziale
//per le liste non circolari
nodo * insert_first(nodo * s, int v) {
    node n = new node;
    n->valore = v;
    n->next = s
    return n;
}
//aggiunge un elemento in fondo alla lista
//se la lista è vuota allora il puntatore p (l'inizio della lista)
//diventa il nuovo elemento
void insert_last(nodo * & p, int n) {
    nodo * r = new nodo;
    r->valore = n;
    r->next = NULL;
    if (p != NULL) {
        node * q = p;
        while(q->next != NULL) {
            q = q->next;
        }
        q->next = r;
    }
    else {
        p = r;
    }
}
void insert_ordinato(nodo * p,int n){
    nodo * q = p;
    
    while(q->next->valore <= n){
        q = q->next;
    }
    //creo il nodo e assegno come prossimo il nodo maggiore
    nodo * n = new nodo;
    n->valore = n;
    n->next = q->next;
    //il nodo corrente cambia il next e mette il nuovo nodo
    q->next = n; 
}

void insert_order(nodo * & p, int inform){
    //controllo se devo inserilo per primo
    if ((p==NULL) || (p->valore >= inform)) {
        insert_first(p, inform);
    }
    else {
        nodo* q=p;
        //finchè il prossimo nodo non è maggiore del valore che ho e ho un prossimo nodo
        while ((q->next != NULL) && (q->next->valore <= inform)) {
            q = q->next;
        }
        nodo* r = new nodo;
        r->valore = inform;
        r->next = q->next;
        q->next = r;
    }
}
//rimuove il nodo dopo x
node * remove_element_after(node *x) {
    //controllo se sono null
    if (x == NULL || x->next == NULL)
        return NULL;

    node * y = x->next;
    x->next = y->next;
    y->next = NULL;
    return y;
}
//ritorna il nuovo primo nodo
nodo * remove_first(nodo * s) {
    nodo * n = s;
    if (s != NULL) {
        s = s->next;
        delete n;
    }
    return s;
}

void search_remove(nodo* &p, int val){
    //se la lista non è nulla
    if (p != NULL) {
        nodo* q = p;
        //se devo eliminare il primo elemento
        if (q->valore == val) {
            //cambio p nel nodo dopo ed elimino il primo nodo
            p = p->next;
            delete q;
        }
        else {
            //cerco il valore
            bool eliminato = false;
            while(q->next != NULL && !eliminato) {
                //se il nodo successivo ha il valore ricercato
                //allora lo elimino
                if (q->next->valore == val) {
                    nodo* r = q->next;
                    q->next = q->next->next;
                    delete r;
                    eliminato = true;
                }
                //se il nodo successivo non ha il valore cercato
                //vado avanti nella ricerca
                if (q->next != NULL) {
                        q=q->next;
                }
            }
        }
    }
}
//rovescia la lista concatenata
node * reverse(node * x) {
    node * t;
    node * y = x;
    node * r = NULL;
    while ( y != NULL ) {
        t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    return r;
}
//per liste doppiamente concatenate
nododoppio * remove_doppio(nododoppio * t) {
    t->next->prev = t->prev;
    t->prev->next = t->next;
    t->next = t->prev = NULL;
    return t;
}

void insert_node(nododoppio * x, nododoppio * t) {
t->next = x->next;
t->next->prev = t;
t->prev = x;
x->next = t;
}

