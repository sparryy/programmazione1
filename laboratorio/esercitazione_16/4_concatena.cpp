#include <iostream>
using namespace std;
int *append(int *pa, int *pb, int na, int nb);
void bubbleSort(int array[], int);
void print(int *array, int length);
int main()
{
    int len1 = 0;
    cout << "Primo array: quanti elementi si vogliono inserire? ";
    cin >> len1;
    if (len1 <= 0)
        return -1;
    // esempio di gestione opzione “nothrow”
    // in caso di impossibilirà di allocazione della memoria richiesta
    // new non abortisce ma restituisce “NULL”
    int *array1 = new (nothrow) int[len1];
    if (array1 == NULL)
    {
        cout << "Failed";
        return -1;
    }
    for (int i = 0; i < len1; i++)
    {
        cout << "Inserire il " << i + 1 << ".o elemento del primo array: ";
        cin >> array1[i];
    }
    cout << "Primo array: ";
    print(array1, len1);

    int len2 = 0;
    cout << "Secondo array: quanti elementi si vogliono inserire? ";
    cin >> len2;
    if (len2 <= 0)
        return -1;
    int *array2 = new (nothrow) int[len2];
    if (array2 == NULL)
    {
        cout << "Failed";
        delete[] array1;
        return -2;
    }
    for (int j = 0; j < len2; j++)
    {
        cout << "Inserire il " << j + 1 << ".o elemento del secondo array: ";
        cin >> array2[j];
    }
    cout << "Secondo array: ";
    print(array2, len2);
    int lenC = len1 + len2;
    int *arrayC = append(array1, array2, len1, len2);
    if (arrayC != NULL)
    {
        bubbleSort(arrayC, lenC);
        cout << "Array concatenato e ordinato: " << endl;
        print(arrayC, lenC);
    }
    else
    {
        delete[] array1;
        delete[] array2;
        return -2;
    }
    cout << endl;
    delete[] array1;
    delete[] array2;
    delete[] arrayC;
    return 0;
}

int *append(int *array1, int *array2, int len1, int len2)
{
    int lenC = len1 + len2;
    int *arrayC = NULL;
    if (lenC > 0)
    {
        arrayC = new (nothrow) int[lenC];
        if (arrayC != NULL)
        {
            for (int i = 0; i < lenC; i++)
            {
                arrayC[i] = (i < len1) ? array1[i] : array2[i - len1];
            }
        }
        else
            cout << "Failed!";
    }
    return arrayC;
}

void bubbleSort(int array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                float tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

void print(int *array, int length)
{
    for (int *p = array; p < (array + length); p++)
        cout << *p << " ";
    cout << endl;
}