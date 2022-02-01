#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void Sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
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
int Spliting(int arr[], int N)
{
    int res = 2 * N / 3;
    int sum = 0;
    for (int k = 0; k < N; k++)
        sum += arr[k];
    if ((double)sum / N < 0) res /= 2;
    return res;
}
void Reverse(int arr[], int beg, int end)
{
    int temp = 0;
    for (int i = 0; i < (end - beg) / 2; i++)
    {
        temp = arr[i + beg];
        arr[i + beg] = arr[end - 1 - i];
        arr[end - 1 - i] = temp;
    }
}
int main()
{
    srand(time(NULL));
    const int size = 9;
    int array[size];
    cout << "Array: " << endl;
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10 - 5;
        cout << array[i] << " ";
    }
    cout << endl;
    int  split = Spliting(array, size);
    Sort(array, split);
    Reverse(array, split, size);
    cout << "After sorting: " << endl;
    for (int k = 0; k < size; k++)
        cout << array[k] << " ";
    cout << endl;
    return 0;
}
