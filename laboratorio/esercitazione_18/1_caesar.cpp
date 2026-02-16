#include "1_caesar.h"

void crypt(char string[], int key) {
    for (int i = 0; string[i] != '\0'; i++) {
        int encrypted = (int)string[i];
        encrypted += key;

        if (encrypted > (int)'z') {
            encrypted = encrypted - 'z' + 'a' - 1;
        }
        string[i] = (char)encrypted;
    }
}

void decrypt(char string[], int key) {
    for (int i = 0; string[i] != '\0'; i++) {
        int decrypted = (int)string[i];
        decrypted -= key;

        if (decrypted < 'a') {
            decrypted = decrypted + 'z' - 'a' + 1;
        }
        string[i] = (char)decrypted;
    }
}
