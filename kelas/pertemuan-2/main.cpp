#include <iostream>
using namespace std;

int main()
{
    // Array
    string nama[5] = {"Dimas", "Harahap", "Kalingga", "Ucup"};

    int angka[3];
    angka[0] = 1;
    angka[1] = 2;
    angka[2] = 3;

    cout << "Nama\t: " << nama[1] << endl;
    cout << "Angka\t: " << angka[1] << endl;
    cout << endl;

    // Mendapatkan panjang array
    int angka2[5] = {1, 2, 3, 4, 5};
    cout << "Ukuran Array: " << sizeof(angka2) << endl; // Ukuran byte array (banyakElemen * ukuranTipeData)

    // Rumus mendapatkan panjang array
    int panjangArray1 = sizeof(angka2) / sizeof(angka2[0]);
    int panjangArray2 = sizeof(angka2) / sizeof(int);

    cout << "Panjang 1\t:" << panjangArray1 << endl;
    cout << "Panjang 2\t:" << panjangArray1 << endl;

    // Looping Array
    for (int i = 0; i < panjangArray1; i++)
    {
        cout << angka2[i] << endl;
    }

    for (int item : angka2)
    {
        cout << item << endl;
    }
    cout << endl;

    // Output array tanpa indeks adalah alamat memorinya
    cout << "Alamat memori array\t:" << angka2 << endl;
    for (int i = 0; i < panjangArray1; i++)
    {
        // Mengakses alamat memori masing-masing elemen dengan prefix "&"
        cout << "Alamat memori indeks ke-" << i << "\t: " << &angka2[i] << endl;
    }
    cout << endl;

    // Ilustrasi Array Create
    int angka3[5] = {1, 2, 3, 4};
    for (int item : angka3)
    {
        // Elemen terakhir 0
        cout << item << endl;
    }
    cout << endl;

    // Array 2 Dimensi
    int matriks[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    cout << matriks[0][0] << endl;

    // Array 3 Dimensi
    int arr[2][3][2] = {
        {
            {1, 2},
            {3, 4},
            {5, 6}
        },
        {
            {7, 8},
            {9, 10},
            {11, 12}
        }
    };
    
    cout << arr[1][2][1] << endl;

    return 0;
}
