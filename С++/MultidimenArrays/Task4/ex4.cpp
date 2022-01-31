#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;


int** createArr(int row, int col)
{
    int** arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[col];
    return arr;
}

void fullArr(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}

void printArr(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void deleteArr(int** arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

int** tranpose(int** arr, int* row, int* col)
{
    int** newArr = createArr(*col, *row);
    for (int i = 0; i < *col; i++)
    {
        for (int j = 0; j < *row; j++)
        {
            newArr[i][j] = arr[j][i];
        }
    }
    deleteArr(arr, *row, *col);
    int t = *row;
    *row = *col;
    *col = t;
    return newArr;
}

int main()
{
    setlocale(0, "");
    srand(time(0));
    int row, col;
    cout << "Введите количество строк: ";
    cin >> row;
    cout << "количество колонок: ";
    cin >> col;
    int** array = createArr(row, col);
    fullArr(array, row, col);
    cout << "Массив до изменений:" << endl;
    printArr(array, row, col);
    array = tranpose(array, &row, &col);
    cout << "Массив после:" << endl;
    printArr(array, row, col);
    deleteArr(array, row, col);
    return 0;
}