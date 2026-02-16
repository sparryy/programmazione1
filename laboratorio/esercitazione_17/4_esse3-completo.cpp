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

const int DEFAULT_MAX_N_STUDENTI = 100;

void stampa_studente(Studente *studente);
void stampa_database(Studente **database, int n_studenti);
Studente *genera_studente(char nome[], char cognome[], int matricola, float media);
Studente **carica_database(char file_name[], int &n_studenti, int max_n_studenti);
void dealloca_database(Studente **database, int n_studenti);

// Salva il database su un file di testo
void salva_database(Studente **database, char file_name[], int n_studenti);

// Modifica i dati di uno studente dato l'indice, chiedendo i valori con cin
void modifica_studente(Studente **database, int indice, int n_studenti);

int cerca_matricola(Studente **database, int matricola, int n_studenti);
int cerca_nome_e_cognome(Studente **database, char nome[], char cognome[], int n_studenti);
int studente_top_media(Studente **database, int n_studenti);

int main(int argc, char *argv[])
{

    // init a standard empty database of DEFAULT_MAX_N_STUDENTI size
    int max_n_studenti = DEFAULT_MAX_N_STUDENTI;
    Studente **database = new Studente *[max_n_studenti];
    int n_studenti = 0;



    char azione = 'k';

    while (azione != 'e')
    {
        char menu[] = ""
                      "[ESSE3++] Cosa vuoi fare?\n"
                      "(f) carica database da file_name\n"
                      "(i) inserisci nuovo studente\n"
                      "(a) aggiorna i dati di uno studente\n"
                      "(c) cerca per indice\n"
                      "(m) cerca per matricola\n"
                      "(n) cerca per nome e cognome\n"
                      "(t) cerca studente top media\n"
                      "(p) stampa intero database\n"
                      "(s) salva database su file\n"
                      "(e) esci\n: ";
        
        cout << menu;
        cin >> azione;

        switch (azione)
        {
        case 'i':
        {
            if (n_studenti == max_n_studenti)
                cout << "[ESSE3++] Raggiunta la dimensione massima del database!" << endl;
            else
            {
                char nome[30], cognome[30];
                int matricola;
                float media;
                cout << "[ESSE3++] Inserisci i dati dell'utente (nome, cognome, matricola, media): ";
                cin >> nome >> cognome >> matricola >> media;
                Studente *s_tmp = genera_studente(nome, cognome, matricola, media);
                database[n_studenti] = s_tmp;
                n_studenti++;
            }

            break;
        }
        case 'a':
        {
             int indice;
             cout << "[ESSE3++] Inserisci l'indice dello studente da modificare [0-" << (n_studenti-1) << "]: ";
             cin >> indice;
             modifica_studente(database, indice, n_studenti);
             break;
         }
        case 'c':
        {
            int indice;
            cout << "[ESSE3++] Inserisci l'indice dell'utente che vuoi leggere [0-" << (n_studenti-1) <<"]: " ;
            cin >> indice;

            if (indice >=0 && indice < n_studenti)
                stampa_studente(database[indice]);
            else
                cout << "[ESSE3++] L'utente con questo indice non esiste!" << endl;
            break;
        }
        case 'f':
        {
            char procedere = 'n';
            do{
                cout<<"Tutti i dati non salvati saranno persi! Procedere (s/n): ";
                cin >> procedere;
            } while (!((procedere=='s') xor (procedere=='n')));
            if(procedere=='s'){
                dealloca_database(database,n_studenti);
                char file_name[30];
                cout << "[ESSE3++] Inserisci il nome del file: ";
                cin >> file_name;
                cout << "[ESSE3++] Inserisci la dimensone massima del database: ";
                cin >> max_n_studenti;
                database = carica_database(file_name, n_studenti, max_n_studenti);
            }
            break;
        }
        case 'm':
        {
            int matricola;
            cout << "[ESSE3++] Inserisci la matricola da cercare: ";
            cin >> matricola;
            int indice = cerca_matricola(database, matricola, n_studenti);

            if (indice != -1)
                stampa_studente(database[indice]);
            else
                cout << "[ESSE3++] Studente non trovato!" << endl;
            break;
        }
        case 'n':
        {
            char nome[30], cognome[30];
            cout << "[ESSE3++] Inserisci nome e cognome da cercare: ";
            cin >> nome >> cognome;
            int indice = cerca_nome_e_cognome(database, nome, cognome, n_studenti);

            if (indice != -1)
                stampa_studente(database[indice]);
            else
                cout << "[ESSE3++] Studente non trovato!" << endl;
            break;
        }
        case 't':
        {
            int indice = studente_top_media(database, n_studenti);

            if (indice != -1)
                stampa_studente(database[indice]);
            else
                cout << "[ESSE3++] Studente non trovato!" << endl;
            break;
        }
        case 'p':
        {
            stampa_database(database,n_studenti);
            break;
        }
        case 's':
        {
            char file_name[30];
            cout << "[ESSE3++] Inserisci il nome del file su cui salvare: ";
            cin >> file_name;
            salva_database(database, file_name, n_studenti);
            cout << "[ESSE3++] Database salvato su " << file_name << endl;
            break;
        }
        case 'e':
            dealloca_database(database,n_studenti);
            cout << "[ESSE3++] Arrivederci!" << endl;
            break;
        default:
            cout << "[ESSE3++]  Comando non riconosciuto!" << endl;
        }
    }

    return 0;
}

void stampa_studente(Studente *studente)
{
    cout << "Studente (matricola: " << studente->matricola << ") :" << endl;
    cout << "\tNome: " << studente->nome << endl;
    cout << "\tCognome: " << studente->cognome << endl;
    cout << "\tMedia: " << studente->media << endl;
}

void stampa_database(Studente **database, int n_studenti)
{
    cout << "Indice\tMatricola\tNome\t\tCognome\t\tMedia" << endl;
    for (int i = 0; i < n_studenti; i++)
    {
        cout << (i) << "\t";
        cout << database[i]->matricola << "\t\t";
        cout << database[i]->nome << "\t\t";
        cout << database[i]->cognome << "\t\t";
        cout << database[i]->media << endl;
    };
}

Studente *genera_studente(char nome[], char cognome[], int matricola, float media)
{
    Studente *studente = new Studente;

    studente->matricola = matricola;
    studente->media = media;
    strcpy(studente->nome, nome);
    strcpy(studente->cognome, cognome);
    return studente;
}

Studente ** carica_database(char file_name[], int &n_studenti, int max_n_studenti)
{
    max_n_studenti = max_n_studenti>0 ? max_n_studenti :DEFAULT_MAX_N_STUDENTI;
    
    Studente **database = new Studente *[max_n_studenti];
    n_studenti = 0;

    fstream input;
    input.open(file_name, ios::in);
    if (input.fail())
    {
        cout << "Errore nella lettura del file_name" << endl;
    }
    else
    {
        char nome[31], cognome[31];
        int matricola;
        float media;

        while ((n_studenti < max_n_studenti) && (input >> nome >> cognome >> matricola >> media))
        {
            database[n_studenti] = genera_studente(nome, cognome, matricola, media);
            n_studenti++;
        }
    }
    input.close();
    return database;
}

void dealloca_database(Studente **database, int n_studenti){
    for (int i = 0; i < n_studenti; i++)
    {
        delete database[i];
    }
    delete[] database;
}

int studente_top_media(Studente **database, int n_studenti)
{
    float max = 0;
    int indice = 0;

    for (int i = 0; i < n_studenti; i++)
    {
        if (database[i]->media > max)
        {
            indice = i;
            max = database[i]->media;
        }
    }
    return indice;
}

int cerca_nome_e_cognome(Studente **database, char nome[], char cognome[], int n_studenti)
{
    int indice = -1;

    for (int i = 0; (i < n_studenti) && (indice == -1); i++)
    {
        if ((strcmp(database[i]->nome,
                    nome) == 0) &&
            (strcmp(database[i]->cognome,
                    cognome) == 0))
        {
            indice = i;
        }
    }
    return indice;
}

int cerca_matricola(Studente **database, int matricola, int n_studenti)
{
    int indice = -1;

    for (int i = 0; (i < n_studenti) && (indice == -1); i++)
    {
        if (database[i]->matricola == matricola)
        {
            indice = i;
        }
    }
    return indice;
}

// Modifica i dati di uno studente dato l'indice, chiedendo i valori con cin
void modifica_studente(Studente **database, int indice, int n_studenti)
{
    if (indice < 0 || indice >= n_studenti) {
        cout << "[ESSE3++] Indice non valido!" << endl;
        return;
    }
    cout << "[ESSE3++] Dati attuali dello studente:" << endl;
    stampa_studente(database[indice]);
    cout << "[ESSE3++] Inserisci i nuovi dati (nome cognome matricola media): ";
    char nome[31], cognome[31];
    int matricola;
    float media;
    cin >> nome >> cognome >> matricola >> media;
    strcpy(database[indice]->nome, nome);
    strcpy(database[indice]->cognome, cognome);
    database[indice]->matricola = matricola;
    database[indice]->media = media;
    cout << "[ESSE3++] Dati aggiornati con successo!" << endl;
}

// Implementazione della funzione per salvare il database su file
void salva_database(Studente **database, char file_name[], int n_studenti)
{
    fstream output;
    output.open(file_name, ios::out);
    if (output.fail()) {
        cout << "[ESSE3++] Errore nell'apertura del file per la scrittura!" << endl;
    }
    else{
        for (int i = 0; i < n_studenti; ++i) {
        output << database[i]->nome << ' '
               << database[i]->cognome << ' '
               << database[i]->matricola << ' '
               << database[i]->media << endl;
    }
    }
    
    output.close();
}