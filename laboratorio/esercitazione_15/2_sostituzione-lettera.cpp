#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Usage: sostituzione <input_file> <lettera>" << endl;
        exit(0);
    }

    char l = argv[2][0];

    fstream input;
    input.open(argv[1], ios::in);

    if (input.fail()) {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
        exit(0);
    }

    char c;
    input.get(c);
    while (!input.eof() && !input.fail()) {
        cout.put((c == l)? '?': c);
        input.get(c);
    }
    cout << endl;
    input.close();
    return 0;
}