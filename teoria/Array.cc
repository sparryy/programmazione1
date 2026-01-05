#include <iostream>
using namespace std;
//nel caso di problemi con out of bounds, 
//g++ -fsanitize=bounds -fsanitize=bounds-strict
//può aiutare a identificare l'errore
int main(){
    //la dimensione dell'array deve essere valutabile durante la compilazione
    //quindi si possono usare numeri o costanti
    //se non vengono definiti i valori vengono inizializzati allo zero del tipo
    //della variabile

    //una funzione può restituire un array statico solo se è allocato esternamente alla funzione

    //sugli array non sono definite le operazioni, per farle bisogna scrivere
    //funzioni ad hoc. Esiste solo la selezione con indice
    int array1[3];
    int array2[3]={3,2,1};
    int array3[]={3,2,1}; //ricava da solo la dimensione
    //array2[2] ha indirizzo
    cout << array2[2] <<endl;
    //gli array possono essere passati tramite funzione 
    func(array2,2);
    //stampa la dimensione del tipo di variabile all'interno, non della dimensione
    //dell'array
    sizeof(array2);
    int array4[3][4];
    int array5[3][4] = {{3,2,1,0},{3,2,1,0},{3,2,1,0}};
    int array6[][4] = {{3,2,1,0},{3,2,1,0},{3,2,1,0}};
    //se un puntatore punta il primo elemento, il puntatore +1 punta l'elemento successivo
    //il nome dell'array è il puntatore al primo elemento
    return 0;
}
//se scrivo const davanti al parametro formale allora l'array non sarà modificabile
//senza duplicare l'array
int func(const int array[],int n){
    return 0;
}
//!TODO riguardare gli algoritmi di ordinamento, fanno schifo
////////////////////
// Funzioni Utili //
////////////////////

/*              
solo per aggiungere elementi in mezzo tra altri elementi
ordine dei parametri:array, count, variabile da agg, posizione, dimensione array
void addElement(int arr[], int &d, const int x, const int p, const int N) {
    cout << "Adding " << x << " at position " << p << endl;
    if (p >= 0 && p <= d && d < N) {
    for(int i = d; i > p; i--)
        arr[i] = arr[i-1];
        arr[p] = x;
        d++;
    }
}

////////////////////
// Selection Sort //
////////////////////

void selectionsort(int A[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int min = i;
    for(int j = i + 1; j < N; j++) // cerco elemento piu’
        // piccolo nella parte di
        // array ancora da ordinare
        if (A[j] < A[min]) min = j;
            swap(A[i], A[min]); // scambio elemento trovato
    // con elemento dell’array
    // ancora da ordinare
    }
}

////////////////////
// Insertion Sort //
////////////////////

void insertsort( int A[], int N) {
    for(int i = N-1; i > 0; i--) // porto elemento
        // piu’ piccolo in A[0]
        if (A[i] < A[i-1]) swap(A[i], A[i-1]);
            for(int i = 2; i <= N-1; i++) {
                int j = i;
                int v = A[i];
                while( v < A[j-1] ) {
                    A[j] = A[j-1]; j--;
                }
                A[j] = v;
            }
}

////////////////
// Quick Sort //
////////////////

int partition(int A[], int l, int r) {
    int i = l-1, j = r, v = A[r];
    while (true) {
        while (A[++i] < v);
        while (v < A[--j])
            if (j == l) break;
                if (i >= j) break;
                    swap(A[i],A[j]);
    }
    swap(A[i],A[r]);
    return(i);
}

void quicksort(int A[], int N) {
    quicksort_aux(A, 0, N-1);
}
void quicksort_aux(int A[], int l, int r) {
    if (r <= l) return;
        int i = partition(A, l, r);
        quicksort_aux(A, l, i-1);
        quicksort_aux(A, i+1, r);
}



*/