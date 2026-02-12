#include <iostream>
#include <fstream>
using namespace std;

void sort_array(float array[], int length);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cout << "Usage: exec <file> <nTemp> <max>" << endl;
        exit(0);
    }

    int nTemp = atof(argv[2]);
    int length = atof(argv[3]);

    fstream input;
    input.open(argv[1], ios::in);

    if (input.fail())
    {
        cout << "Il file dato in input " << argv[1] << " non esiste!" << endl;
        exit(0);
    }

    float *array = new float[length];

    int j = 0;
    char temperature[256];
    while (input >> temperature)
    {
        array[j++] = atof(temperature);
    }

    sort_array(array, length);

    cout << "Le " << nTemp << " temperature più alte:" << endl;
    for (int i = 0; i < nTemp; i++)
    {
        cout << array[i] << endl;
    }

    input.close();
    delete[] array;

    return 0;
}

void sort_array(float array[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                float tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}