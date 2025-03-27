#include <iostream>
using namespace std;

#define MAX_MAHASISWA 5

struct Alamat
{
    string jalan;
    string kota;
};

struct Mahasiswa
{
    string nama;
    string nim;
    float ipk;
    Alamat alamat;
};

Mahasiswa mahasiswa[MAX_MAHASISWA];
int panjang = 0;

void TampilkanData()
{

    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << (i + 1) << ". \tNama\t:" << mahasiswa[i].nama << endl;
        cout << "\tNIM\t:" << mahasiswa[i].nim << endl;
        cout << "\tIPK\t:" << mahasiswa[i].ipk << endl;
        cout << "\tJalan\t:" << mahasiswa[i].alamat.jalan << endl;
        cout << "\tKota\t:" << mahasiswa[i].alamat.kota << endl
             << endl;
    }
}

void TambahData()
{
    cout << "Masukkan Nama:";
    cin.ignore();
    getline(cin, mahasiswa[panjang].nama);

    cout << "Masukkan NIM:";
    getline(cin, mahasiswa[panjang].nim);

    cout << "Masukkan IPK:";
    cin >> mahasiswa[panjang].ipk;

    cout << "Masukkan Jalan:";
    cin.ignore();
    getline(cin, mahasiswa[panjang].alamat.jalan);

    cout << "Masukkan Kota:";
    getline(cin, mahasiswa[panjang].alamat.kota);

    panjang++;
}

void EditData()
{
    cout << "Daftar Mahasiswa" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << i + 1 << ". Nama\t: " << mahasiswa[i].nama << endl;
    }

    int index;
    cout << "Masukkan nomor maahsiswa yang ingin dihapus: ";
    cin >> index;

    cout << "Masukkan Nama:";
    cin.ignore();
    getline(cin, mahasiswa[index - 1].nama);

    cout << "Masukkan NIM:";
    getline(cin, mahasiswa[index - 1].nim);

    cout << "Masukkan IPK:";
    cin >> mahasiswa[index - 1].ipk;

    cout << "Masukkan Jalan:";
    cin.ignore();
    getline(cin, mahasiswa[index - 1].alamat.jalan);

    cout << "Masukkan Kota:";
    getline(cin, mahasiswa[index - 1].alamat.kota);
}

void HapusData()
{
    cout << "Daftar Mahasiswa" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << i + 1 << ". Nama\t: " << mahasiswa[i].nama << endl;
    }

    int index;
    cout << "Masukkan nomor maahsiswa yang ingin diedit: ";
    cin >> index;

    for (int i = index - 1; i < panjang - 1; i++)
    {
        mahasiswa[i] = mahasiswa[i + 1];
    }

    panjang--;
}

int main()
{
    int pilihan;

    do
    {
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Data" << endl;
        cout << "2. Tambah Data" << endl;
        cout << "3. Ubah Data" << endl;
        cout << "4. Hapus Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            if (panjang > 0)
            {
                TampilkanData();
            }
            else
            {
                cout << "Belum ada data bang" << endl;
            }
            break;
        case 2:
            if (panjang < MAX_MAHASISWA)
            {
                TambahData();
            }
            else
            {
                cout << "Penuh sudah bang" << endl;
            }
            break;
        case 3:
            TampilkanData();
            EditData();
            break;
        case 4:
            TampilkanData();
            HapusData();
            break;
        case 5:
            cout << "Program selesai" << endl;
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
    } while (pilihan != 5);
}