#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Studente
{
    char nome[30];
    char cognome[30];
    int matricola;
    float media;
};

Studente **genera_database(int length);

Studente *genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);

void stampa_studente(Studente *studente);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Usage: <exec> <file-name> <nStudenti>" << endl;
        exit(0);
    }

    fstream input;
    input.open(argv[1], ios::in);

    if (input.fail()) {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
        exit(0);
    }
    
    int length = atof(argv[2]);

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

Studente **genera_database(int length) {
    Studente **database = new Studente*[length];
}