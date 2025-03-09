#include <iostream>
using namespace std;

int main()
{
    // Single line comment
    /*
        Multi
        Line
        Comment
    */

    // cout << "Hello, world!" << endl;

    // cout << "Saya sedang belajar C++";
    // return 0;

    // string nama;

    // cout << "Masukkan nama: ";
    // cin >> nama;
    // getline(cin, nama);
    // cout << nama;

    // int umur = 18;
    // float beratBadan = 33.5;
    // double tinggiBadan = 170.3;
    // char jenisKelamin = 'L';
    // bool isMenikah = false;

    // int angka[5] = {1, 2, 3, 4, 5}

    struct Mahasiswa
    {
        string nama;
        int umur;
        float ipk;
    };

    Mahasiswa mhs = {"Hermawan", 18, 3.43}; // Gagal 3.5 :pensive:

    // string firstName; // camelCase
    // string last_name; // snake_case
    // string FullName;  // PascalCase

    // Struktur variabel
    // tipeData namaVariable; null
    // tipeData namaVariable = nilai;

    // Ternary Operator
    // kondisi ? kondisi_jika_benar : kondisi_jika_salah

    // Percabangan
    /*
    if (kondisi)
    {
        Kode yang akan dijalankan jika bernilai true
    }
    else if (kondisi)
    {
        Kode yang akan dijalankan jika kondisi baru bernilai true
    }
    else
    {
        Kode yang akan dijalankan jika bernilai false
    }
    */

    // bool malas = 0;
    // bool lapar = 1;
    // if (malas)
    // {
    //     cout << "Saya scroll fesbuk";
    // }
    // else if (lapar)
    // {
    //     cout << "Saya makan";
    // }
    // else
    // {
    //     cout << "Saya belajar";
    // }

    // int nilaiUjian = 100;

    // switch (nilaiUjian)
    // {
    // case 100:
    //     cout << "Nilai sempurna";
    //     break;
    // case 90:
    //     cout << "Nilai sangat baik";
    //     break;
    // default:
    //     cout << "Nilai tidak valid";
    //     break;
    // }

    // Nested If
    // bool malas = 0;
    // bool lapar = 1;
    // if (malas)
    // {
    //     cout << "Saya scroll fesbuk";
    //     if (lapar)
    //     {
    //         cout << "Saya makan";
    //     }
    // }
    // else
    // {
    //     cout << "Saya belajar";
    // }

    // Perulangan
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << i << endl;
    // }

    // int i = 0;
    // while (i < 5)
    // {
    //     cout << i << endl;
    //     i++;
    // }

    // int i = 0;
    // do {
    //     cout << i << endl;
    //     i++;
    // } while (i < 5);

    int arr[] = {1, 2, 3, 4, 5};
    for (int x:arr)
    {
        cout << x << endl;
    }

    return 0;
}

string Input(string &prompt)
{
    string output;
    cout << prompt;
    getline(cin, output);
    return output;
}