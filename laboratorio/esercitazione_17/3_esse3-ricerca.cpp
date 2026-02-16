#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

struct Studente
{
    char nome[31];
    char cognome[31];
    int matricola;
    float media;
};

int cerca_matricola(Studente ** database, int matricola, int len);

int cerca_nome_e_cognome(Studente ** database, char * nome, char * cognome, int len);

int studente_top_media(Studente ** database, int len);

Studente **genera_database(int length, char * &fileName);

Studente *genera_studente(char nome[], char cognome[], int matricola, float media_ponderata);

void stampa_studente(Studente *studente);

int main(int argc, char *argv[])
{
    if (argc != 3) {
        cout << "Usage: <exec> <file-name> <nStudenti>" << endl;
        exit(0);
    }

    int length = atof(argv[2]);
    
    if (length < 1) {
        cout << "nStudenti deve essere maggiore di 0" << endl;
        exit(1);
    }

    char *fileName = argv[1];
    
    Studente **database = genera_database(length, fileName);

    char nome[] = "Giovanni";
    char cognome[] = "Giovannini";

    int index = cerca_matricola(database, 79359, length);
    if(index != -1) {
        stampa_studente(database[index]);
    }
    index = cerca_nome_e_cognome(database, nome, cognome, length);
    if(index != -1) {
        stampa_studente(database[index]);
    }
    index = studente_top_media(database, length);
    if(index != -1) {
        stampa_studente(database[index]);
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

int cerca_matricola(Studente ** database, int matricola, int len) {
    for(int i = 0; i < len; i++) {
        if(database[i]->matricola = matricola) {
            return i;
        }
    }
    return -1;
}

int cerca_nome_e_cognome(Studente ** database, char * nome, char * cognome, int len) {
    for(int i = 0; i < len; i++) {
        if((strcmp(database[i]->nome, nome) == 0) && (strcmp(database[i]->cognome, cognome) == 0)) {
            return i;
        }
    }
    return -1;
}

int studente_top_media(Studente ** database, int len) {
    int max = 0;
    for(int i = 1; i < len; i++) {
        if(database[i]->media > database[max]->media) {
            max = i;
        }
    }
    return max;
}