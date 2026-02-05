#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    int random_number = rand() % 10 + 1;
    int guess;
    bool guessed = false;

    cout << "Indovina il numero tra 1 e 10" << endl;

    while (!guessed) {
        cin >> guess;

        if(guess == random_number) {
            cout << "Bravo! Hai indovinato" << endl;
            guessed = true;
        } else {
            cout << "Ritenta :(" << endl;
        }
    }

    return 0;
}