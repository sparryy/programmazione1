#include <iostream>
using namespace std;

int main ()
{
	int righe, colonne;

	cout << "Inserire il numero di righe di una tabella: ";
	cin >> righe;
	cout << "Inserire il numero di colonne di una tabella: ";
	cin >> colonne;

	int test = !((righe == 1) || (colonne == 1));

	cout << "Ora stampo 0 se la tabella ha una sola riga oppure una sola colonna oppure un solo elemento" << std::endl;
	cout << "Altrimenti stampo un numero diverso da 0." << endl;
	cout << "Risultato: " << test << endl;

	return 0;
}