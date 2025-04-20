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

void tampilkanData(Mahasiswa *mhs[], int &panjang)
{
    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < panjang; i++)
    {
        cout << (i + 1) << ".\t" << "Nama\t: " << mhs[i]->nama << endl;
        cout << "\tNIM\t: " << mhs[i]->nim << endl;
        cout << "\tIPK\t: " << mhs[i]->ipk << endl;
        cout << "\tJalan\t: " << mhs[i]->alamat.jalan << endl;
        cout << "\tKota\t: " << mhs[i]->alamat.kota << endl
             << endl;
    }
}

void tambahkanData(Mahasiswa *mhs[], int &panjang)
{
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, mhs[panjang]->nama);

    cout << "Masukkan NIM: ";
    cin.ignore();
    getline(cin, mhs[panjang]->nim);

    cout << "Masukkan ipk: ";
    cin >> mhs[panjang]->ipk;

    cout << "Masukkan jalan: ";
    cin.ignore();
    getline(cin, mhs[panjang]->alamat.jalan);

    cout << "Masukkan kota: ";
    // cin.ignore();
    getline(cin, mhs[panjang]->alamat.kota);

    panjang++;
    cout << "Mahasiswa berhasil ditambahkan" << endl;
}

void ubahData(Mahasiswa *mhs[], int &panjang)
{
    int index;
    cout << "Masukkan nomor mahasiswa yang ingin diubah: ";
    cin >> index;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, mhs[index - 1]->nama);

    cout << "Masukkan NIM: ";
    cin.ignore();
    getline(cin, mhs[index - 1]->nim);

    cout << "Masukkan ipk: ";
    cin >> mhs[index - 1]->ipk;

    cout << "Masukkan jalan: ";
    cin.ignore();
    getline(cin, mhs[index - 1]->alamat.jalan);

    cout << "Masukkan kota: ";
    // cin.ignore();
    getline(cin, mhs[index - 1]->alamat.kota);
}

void hapusData(Mahasiswa *mhs[], int &panjang)
{
    int index;
    cout << "Masukkan nomor mahasiswa yang ingin dihapus: ";
    cin >> index;

    for (int i = index - 1; i < panjang - 1; i++)
    {
        mhs[i] = mhs[i + 1];
    }
    panjang--;
}

int main()
{
    int pilihan;

    int panjang = 0;
    Mahasiswa mhs[MAX_MAHASISWA];
    Mahasiswa *mhsPtr = mhs;
    for (int i = 0; i < MAX_MAHASISWA; i++)
    {
        mhsPtr[i] = mhs[i];
    }

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
            if (panjang == 0)
                cout << "Belum ada datang bang" << endl;
            else
            {
                tampilkanData(&mhsPtr, panjang);
            }
            break;
        case 2:
            if (panjang < MAX_MAHASISWA)
            {
                tambahkanData(&mhsPtr, panjang);
            }
            else
            {
                cout << "Penuh sudah bang" << endl;
            }
            break;
        case 3:
            if (panjang == 0)
            {
                cout << "Belum ada datang bang" << endl;
            }
            else
            {
                tampilkanData(&mhsPtr, panjang);
                ubahData(&mhsPtr, panjang);
            }
            break;
        case 4:
            if (panjang == 0)
                cout << "Belum ada datang bang" << endl;
            else
            {
                tampilkanData(&mhsPtr, panjang);
                hapusData(&mhsPtr, panjang);
            }
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