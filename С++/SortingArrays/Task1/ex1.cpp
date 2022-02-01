#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void bubbleSort(int arr[], int N)
{
    int temp;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
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
    bubbleSort(array, size);
    cout << "After: " << endl;
    for (int k = 0; k < size; k++)
        cout << array[k] << " ";
    cout << endl;
    return 0;
}