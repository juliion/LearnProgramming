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

int** addColumn(int** arr, int row, int* col, int ind)
{
    *col += 1;
    int** newArr = createArr(row, *col);
    int k = 0;
    for (int i = 0; i < row; i++)
    {
        k = 0;
        for (int j = 0; j < *col - 1; j++)
        {
            if (k == ind)
            {
                newArr[i][k] = rand() % 10;
                j--;
            }
            else
            {
                newArr[i][k] = arr[i][j];
            }
            k++;
        }
    }
    deleteArr(arr, row, *col - 1);
    return newArr;
}

int main()
{
    setlocale(0, "");
    srand(time(0));
    int row, col, ind;
    cout << "Введите количество строк: ";
    cin >> row;
    cout << "количество колонок: ";
    cin >> col;
    int** array = createArr(row, col);
    fullArr(array, row, col);
    cout << "Массив до изменений:" << endl;
    printArr(array, row, col);
    cout << "Введите индекс добавляемого столбца: ";
    cin >> ind;
    array = addColumn(array, row, &col, ind);
    cout << "Массив после:" << endl;
    printArr(array, row, col);
    deleteArr(array, row, col);
    return 0;
}