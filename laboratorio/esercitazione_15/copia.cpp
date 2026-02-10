#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Usage: copiare <input_file> <output_file>" << endl;
        exit(0);
    }
    
    fstream input, output;
    input.open(argv[1], ios::in);
    output.open(argv[2], ios::out);
    if (input.fail()) {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
        exit(0);
    }

    char c ;
    input.get(c);
    while(!input.eof() && !input.fail()) {
        output.put(c);
        input.get(c);
    }

    output.close();
    input.close();
    return 0;
}