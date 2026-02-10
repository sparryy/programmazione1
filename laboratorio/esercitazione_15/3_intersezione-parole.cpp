#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
const int WORD_LENGTH = 100;
const int LIST_LENGTH = 1000;
bool addUniqueWord(char word[], char wordList[][WORD_LENGTH], int &insertedWords);
void printStringArray(char array[][WORD_LENGTH], int length);
bool addCommonWord(char word[WORD_LENGTH], char wordUniqeList[][WORD_LENGTH],
                   int uniqueWords, char wordCommonList[][WORD_LENGTH], int &commonWords);
int main(int argc, char *argv[])
{
    fstream inputA, inputB;

    if (argc < 3)
    {
        cout << "Usage: intersezione <input_file_A> <input_file_B>" << endl;
        exit(0);
    }

    inputA.open(argv[1], ios::in);
    inputB.open(argv[2], ios::in);

    if (inputA.fail())
    {
        cout << "Il file dato in inputA " << argv[1] << " non esiste!" << endl;
        exit(1);
    }
    if (inputB.fail())
    {
        cout << "Il file dato in inputB " << argv[1] << " non esiste!" << endl;
        exit(1);
    }
    char word[WORD_LENGTH];
    char wordListA[LIST_LENGTH][WORD_LENGTH];
    char wordListB[LIST_LENGTH][WORD_LENGTH];
    char wordCommonList[LIST_LENGTH][WORD_LENGTH];
    int uniqueWordsA = 0;
    int uniqueWordsB = 0;
    int commonWords = 0;
    // read file A and store unique words in uniqueWordsA
    while (inputA >> word && uniqueWordsA <= 1000)
    {
        addUniqueWord(word, wordListA, uniqueWordsA);
    }
    cout << endl
         << "Parole univoche nel primo file: " << endl;
    printStringArray(wordListA, uniqueWordsA);
    // read file B and store unique words in uniqueWordsB
    while (inputB >> word && uniqueWordsB <= 1000)
    {
        addUniqueWord(word, wordListB, uniqueWordsB);
    }
    cout << endl
         << "Parole univoche nel secondo file: " << endl;
    printStringArray(wordListB, uniqueWordsB);
    // find common cwords between uniqueWordsA and uniqueWordsB
    for (int i = 0; i < uniqueWordsA; i++)
    {

        addCommonWord(wordListA[i], wordListB, uniqueWordsB, wordCommonList, commonWords);
    }
    cout << endl
         << "Parole comuni tra i file (intersezione): " << endl;
    printStringArray(wordCommonList, commonWords);
    inputB.close();
    inputA.close();
    return 0;
}
bool addUniqueWord(char word[WORD_LENGTH], char wordList[][WORD_LENGTH], int &insertedWords)
{
    bool found = false;
    int i = 0;
    while (i < insertedWords && !found)
    {
        if (strcmp(word, wordList[i]) == 0)
            found = true;
        i++;
    }
    if (!found)
    {
        strcpy(wordList[insertedWords], word);
        insertedWords++;
    }
    return !found;
}
bool addCommonWord(char word[WORD_LENGTH], char wordUniqeList[][WORD_LENGTH],
                   int uniqueWords, char wordCommonList[][WORD_LENGTH], int &commonWords)
{
    bool found = false;
    int i = 0;
    while (i < uniqueWords && !found)
    {
        if (strcmp(word, wordUniqeList[i]) == 0)
        {
            found = true;
            strcpy(wordCommonList[commonWords], word);
            commonWords++;
        }
        i++;
    }
    return found;
}
void printStringArray(char array[][WORD_LENGTH], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}