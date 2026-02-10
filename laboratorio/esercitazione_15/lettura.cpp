#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cout << "Usage: leggere <input_file>" << endl;
        exit(0);
    }

    fstream input;
    input.open(argv[1], ios::in);

    if (input.fail()) {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
        exit(0);
    }

    cout << "char[] input version (<<): " <<endl;

    char word[256];

    while (input >> word) {
        cout << word << " ";
    }

    cout << endl << endl;

    input.close();

    cout << "char input version (get(c)): " <<endl;

    input.open(argv[1], ios::in);

    char line[256];
    while (!input.eof() && !input.fail()) {
        if(input.getline(line,256)) {
            cout << line << endl;
        }
    }
    cout << endl;
    input.close();
    return 0;
}