#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
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

int** leftShift(int** arr, int row, int col, int num)
{
    int** newArr = createArr(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (col - 1 < j + num)
                newArr[i][j] = arr[i][j + num - col];
            else
                newArr[i][j] = arr[i][j + num];
        }
    }
    deleteArr(arr, row, col);
    return newArr;
}

int** rightShift(int** arr, int row, int col, int num)
{
    int** newArr = createArr(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j - num < 0)
                newArr[i][j] = arr[i][j - num + col];
            else
                newArr[i][j] = arr[i][j - num];
        }
    }
    deleteArr(arr, row, col);
    return newArr;
}

int** upShift(int** arr, int row, int col, int num)
{
    int** newArr = createArr(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (row - 1 < i + num)
                newArr[i][j] = arr[i + num - row][j];
            else
                newArr[i][j] = arr[i + num][j];
        }
    }
    deleteArr(arr, row, col);
    return newArr;

}

int** downShift(int** arr, int row, int col, int num)
{
    int** newArr = createArr(row, col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i - num < 0)
                newArr[i][j] = arr[i - num + row][j];
            else
                newArr[i][j] = arr[i - num][j];
        }
    }
    deleteArr(arr, row, col);
    return newArr;

}


int main()
{
    setlocale(0, "");
    srand(time(0));
    int row, col, num;
    char way;
    cout << "Введите количество строк: ";
    cin >> row;
    cout << "количество колонок: ";
    cin >> col;
    int** array = createArr(row, col);
    fullArr(array, row, col);
    cout << "Массив до изменений:" << endl;
    printArr(array, row, col);
    cout << "Введите количество сдвигов: ";
    cin >> num;
    cout << "Введите направление сдвига:" << endl
        << "l - влево" << endl
        << "r - вправо" << endl
        << "u - вверх" << endl
        << "d - вниз" << endl;
    cin >> way;
    if (way == 'l' || way == 'r')
        while (num >= col) num -= col;
    else if (way == 'u' || way == 'd')
        while (num >= row) num -= row;
    switch (way)
    {
    case 'l':
        array = leftShift(array, row, col, num);
        break;
    case 'r':
        array = rightShift(array, row, col, num);
        break;
    case 'u':
        array = upShift(array, row, col, num);
        break;
    case 'd':
        array = downShift(array, row, col, num);
        break;
    default:
        cout << "Введено неверное значение" << endl;
        return 0;
    }
    cout << "Массив после:" << endl;
    printArr(array, row, col);
    deleteArr(array, row, col);
    return 0;
}