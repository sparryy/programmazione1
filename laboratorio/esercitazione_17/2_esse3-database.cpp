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

Studente **genera_database(int length, char * &fileName);

Studente *genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);

void stampa_studente(Studente *studente);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Usage: <exec> <file-name> <nStudenti>" << endl;
        exit(0);
    }

    char *fileName = argv[1];
    int length = atof(argv[2]);

    Studente **database = genera_database(length, fileName);

    for(int i = 0; i < length; i++) {
        stampa_studente(database[i]);
        cout << endl;
    }

    for(int i = 0; i < length; i++) {
        delete[] database[i];
    }

    delete[] database;

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

Studente **genera_database(int length, char * &fileName) {
    Studente **database = new Studente*[length];

    fstream input;
    input.open(fileName, ios::in);

    if (input.fail()) {
        cout << "Il file dato in input " << fileName << " non esiste!" << endl;
        exit(0);
    }

    char name[256];
    char cognome[256];
    int  matricola;
    float media;
    
    for(int i = 0; i < length; i++) {
        input >> name;
        input >> cognome;
        input >> matricola;
        input >> media;
        database[i] = genera_studente(name, cognome, matricola, media);
    }

    input.close();
    return database;
}