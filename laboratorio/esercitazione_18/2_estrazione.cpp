#include "2_estrazione.h"

void appendNextUppercase(char *stringOrginal, int idxOriginal, char *stringUppercase, int idxUppercase) {
    if (stringOrginal[idxOriginal] == '\0') {
        stringUppercase[idxUppercase] = '\0';
    } else {
        if ((stringOrginal[idxOriginal] >= 'A') && (stringOrginal[idxOriginal] <= 'Z')) {
            stringUppercase[idxUppercase] = stringOrginal[idxOriginal];
            idxUppercase++;
        }
        appendNextUppercase(stringOrginal, idxOriginal + 1, stringUppercase, idxUppercase);
    }
}

char* extractUppercase(char *stringOrginal) {
    char *stringUppercase = new char[EXT_UPPER_H_MAX_DIM];

    appendNextUppercase(stringOrginal, 0, stringUppercase, 0);
    return stringUppercase;
}