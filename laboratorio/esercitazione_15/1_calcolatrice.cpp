#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cout << "Usage: calcolatrice <numA> <numB> <operatore>" << endl;
        exit(0);
    }

    double n1 = atof(argv[1]);
    double n2 = atof(argv[2]);
    char op = argv[3][0];
    double ris;

    switch(op) {
        case '+':
            ris = n1 + n2;
            break;
        case '-':
            ris = n1 - n2;
            break;
        case 'x':
            ris = n1 * n2;
            break;
        case '/':
            if(n2 != 0) {
                ris = n1 / n2;
            } else {
                cout << "!Impossibile dividere per 0!" << endl;
                exit(1);
            }
            break;
        default:
            cout << "!Operatore non valido!" << endl;
            exit(1);
    }

    cout << n1 << " " << op << " " << n2 << " = " << ris << endl;

    return 0;
}