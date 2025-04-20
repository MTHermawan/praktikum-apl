#include <iostream>
using namespace std;

struct Address
{
    string kota;
    string provinsi;
    string negara;
};

int ubahNilai(int *, int b);

int ubahNilai(int &, int b);

int main()
{
    Address address1, *address2;
    int a = 5;
    int *b = &a;

    // b = 10;
    // ubahNilai(a, b);
    cout << "Nilai a: " << a << endl;
    cout << "Nilai a: " << &a << endl;
    // cout << "Kota a: " << &address1.kota << endl;
    cout << "Nilai b: " << b << endl;
    cout << "Nilai b: " << &b << endl;
    // cout << "Kota b: " << &address2.kota << endl;
    
    // address1.kota = "Samarinda";
    // address1.provinsi = "Kalimantan Timur";
    // address1.negara = "Indonesia";
    
    // address2 = &address1;
    
    
    // address2->kota = "Tenggarong";
    // cout << "Kota a: " << address1.kota << endl;
    // cout << "Kota b: " << address2->kota << endl;    

    return 0;
}

int ubahNilai(int *a, int b)
{
    cout << "Alamat a Fungsi: " << &a << endl;
    return *a = b;
}

int ubahNilai(int &a, int b)
{
    cout << "Alamat a Fungsi: " << &a << endl;
    return a = b;
}