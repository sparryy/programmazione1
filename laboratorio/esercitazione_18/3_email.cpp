#include <iostream>
#include "3_email.h"

using namespace std;

bool isValid(char c) {
    return
        (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9') ||
        (c == '.') ||
        (c == '_')
    ;
}

bool verifyEmail(char *string) {
    bool isEmail = true;
    int  idxAt = -1, lastIdxDot = -1;
    int  numberOfAt = 0;
    int  i=0;

    while(string[i] != '\0' || !isEmail) {
        char currentChar = string[i];

        if (currentChar == '@') {
            idxAt = i;
            numberOfAt++;
        } else if (currentChar == '.') {
            if (i == 0) {
                isEmail = false;
            }
            if ( i == lastIdxDot+1){
                isEmail = false;
            }
            if ( i == idxAt+1){
                isEmail = false;
            }
            lastIdxDot = i;

        } else if (!isValid(currentChar)) {
            isEmail = false;
        }
        i++;
    }

    if (numberOfAt != 1) {
        isEmail = false;
    }

    if ((idxAt == 0) || (idxAt == i - 1)) {
        isEmail = false;
    }

    if (lastIdxDot == i - 1) {
        isEmail = false;
    }

    if (lastIdxDot < idxAt) {
        isEmail = false;
    }

    return isEmail;
}
