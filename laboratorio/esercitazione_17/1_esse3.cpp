#include <iostream>
#include <cstring>
using namespace std;

struct Studente
{
    char nome[30];
    char cognome[30];
    int matricola;
    float media;
};

Studente *genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);

void stampa_studente(Studente *studente);

int main()
{

    char nome1[256] = "Mario";
    char cognome1[256] = "Rossi";
    char nome2[256] = "Paolo";
    char cognome2[256] = "Verdi";

    Studente *s1 = genera_studente(nome1, cognome1, 241232, 28.5);
    Studente *s2 = genera_studente(nome2, cognome2, 345235, 18);

    cout << "Studente 1:" << endl;
    stampa_studente(s1);
    cout << "-------------------" << endl;
    cout << "Studente 2:" << endl;
    stampa_studente(s2);

    delete s1;
    delete s2;

    return 0;
}

Studente *genera_studente(char nome[], char cognome[], int matricola, float media_ponderata)
{
    Studente *studente = new Studente;
    strcpy(studente->nome, nome);
    strcpy(studente->cognome, cognome);
    studente->matricola = matricola;
    studente->media = media_ponderata;
    return studente;
}

void stampa_studente(Studente *studente)
{
    cout << "Nome: " << studente->nome << endl;
    cout << "Cognome: " << studente->cognome << endl;
    cout << "Matricola: " << studente->matricola << endl;
    cout << "Media: " << studente->media << endl;
}