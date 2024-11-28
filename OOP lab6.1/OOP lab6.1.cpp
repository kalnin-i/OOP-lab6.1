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
    cout << "������ �������� ������ " << typeName << " (" << size << " ��������): ";
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
    cout << "������ ����� ������ int: ";
    cin >> intSize;
    int* intArr = new int[intSize];
    inputArray(intArr, intSize, "int");

    int floatSize;
    cout << "������ ����� ������ float: ";
    cin >> floatSize;
    float* floatArr = new float[floatSize];
    inputArray(floatArr, floatSize, "float");

    printArray(intArr, intSize, "�������������� ����� int: ");
    printArray(floatArr, floatSize, "�������������� ����� float: ");

    bubbleSort(intArr, intSize);
    bubbleSort(floatArr, floatSize);

    printArray(intArr, intSize, "³����������� ����� int: ");
    printArray(floatArr, floatSize, "³����������� ����� float: ");

    delete[] intArr;
    delete[] floatArr;

    return 0;
}