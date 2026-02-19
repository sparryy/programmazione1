#include <iostream>


/* Inserire qui sotto la dichiarazione della funzione extract */
char * extract(char const * input);
char * extract_rec(char const * input, int n, int i);
/* Inserire qui sopra la dichiarazione della funzione extract */

/* Solo di esempio, non fate assunzioni su questo valore */
const int DIM = 255;

int main(int argc, char ** argv) {
  char input_string[DIM+1];
  char * extracted;
  char answer;

  do {
    std::cout << "Inserire la stringa da controllare: ";
    std::cin >> input_string;

    extracted = extract(input_string);
    std::cout << "La stringa estratta e': " << extracted << std::endl;

    delete [] extracted;
    std::cout << "Si vuole inserire un'altra stringa? [*/n]";
    std::cin >> answer;
  } while (answer != '\0' && answer != 'N' && answer != 'n');
  return 0;
}

/* Inserire qui sotto la definizione della funzione estract */
char * extract(char const * input) {
    return extract_rec(input, 0, 0);
}

char * extract_rec(char const * input, int n, int i) {
    char * output;
    if(input[i] == '\0') {
        output = new char[n+1];
        output[n] = '\0';
    } else if(input[i] == '@') {
        output = extract_rec(input, n+1, i+1);
        output[n] = '@';
    } else {
        output = extract_rec(input, n, i+1);
    }
    return output;
}
/* Inserire qui sopra la definizione della funzione estract */
