#include <iostream>
using namespace std;

void selectionSort(int a[], int panjang)
{
    for (int i = 0; i < panjang - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < panjang; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        cout << "Tahap ke-" << i + 1 << ": ";
        for (int k = 0; k < panjang; k++)
        {
            cout << a[k] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int arr[6] = {8, 45, 6, 12, 81, 32};
    int panjang = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, panjang);
    return 0;
}