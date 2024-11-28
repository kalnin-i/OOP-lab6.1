#include <iostream>
#include <Windows.h>

using namespace std;

template <typename T>
void bubbleSort(T arr[], int size) 
{
    bool swapped;
    for (int i = 0; i < size - 1; ++i) 
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

template <typename T>
void printArray(const T arr[], int size, const string& message)
{
    cout << message;
    for (int i = 0; i < size; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void inputArray(T arr[], int size, const string& typeName)
{
    cout << "Введіть елементи масиву " << typeName << " (" << size << " елементів): ";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int intSize;
    cout << "Введіть розмір масиву int: ";
    cin >> intSize;
    int* intArr = new int[intSize];
    inputArray(intArr, intSize, "int");

    int floatSize;
    cout << "Введіть розмір масиву float: ";
    cin >> floatSize;
    float* floatArr = new float[floatSize];
    inputArray(floatArr, floatSize, "float");

    printArray(intArr, intSize, "Невідсортований масив int: ");
    printArray(floatArr, floatSize, "Невідсортований масив float: ");

    bubbleSort(intArr, intSize);
    bubbleSort(floatArr, floatSize);

    printArray(intArr, intSize, "Відсортований масив int: ");
    printArray(floatArr, floatSize, "Відсортований масив float: ");

    delete[] intArr;
    delete[] floatArr;

    return 0;
}