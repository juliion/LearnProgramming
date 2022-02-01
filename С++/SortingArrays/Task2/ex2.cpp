#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void insertSort(int arr[], int N)
{
    int temp, j;
    for (int i = 0; i < N; i++)
    {
        temp = arr[i];
        for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = temp;
    }
}
int main()
{
    srand(time(NULL));
    const int size = 5;
    int array[size];
    cout << "Before: " << endl;
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
        cout << array[i] << " ";
    }
    cout << endl;
    insertSort(array, size);
    cout << "After: " << endl;
    for (int k = 0; k < size; k++)
        cout << array[k] << " ";
    cout << endl;
    return 0;
}