#include <iostream>
using namespace std;

int arr[4] = {44, 27, 21, 1};
int n = sizeof(arr) / sizeof(arr[0]);

void bubbleSort()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Menukar elemen jika elemen sebelumnya lebih besar
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Menampilkan proses sorting pada setiap iterasi
        cout << endl
             << endl;
        cout << "Proses [" << i + 1 << "] :";
        for (int k = 0; k < n; k++)
        {
            cout << " " << arr[k];
        }
    }
}

int main()
{
    // Menampilkan data sebelum dilakukan sorting
    cout << "Data sebelum diurutkan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    bubbleSort();
    // Menampilkan data setelah dilakukan sorting
    cout << endl
         << "Data sesudah diurutkan: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}