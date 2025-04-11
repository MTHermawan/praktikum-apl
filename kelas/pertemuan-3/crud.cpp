#include <iostream>
using namespace std;

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

#define MAX_MAHASISWA 5

int main()
{
    int panjang = 0;
    Mahasiswa mahasiswa[MAX_MAHASISWA];
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
                cout << "Data Mahasiswa" << endl;
                for (int i = 0; i < panjang; i++)
                {
                    cout << mahasiswa[i].nama << endl;
                    cout << mahasiswa[i].nim << endl;
                    cout << mahasiswa[i].ipk << endl;
                    cout << mahasiswa[i].alamat.jalan << endl;
                    cout << mahasiswa[i].alamat.kota << endl
                         << endl;
                }
            }
            else
            {
                cout << "Belum ada data bang" << endl;
            }
            break;
        case 2:
            if (panjang < MAX_MAHASISWA)
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
            else
            {
                cout << "Penuh sudah bang" << endl;
            }
            break;
        case 3:
            break;
        case 4:
            cout << "Daftar Mahasiswa" << endl;
            for (int i = 0; i < panjang; i++)
            {
                cout << i+1 << ". Nama\t: " << mahasiswa[i].nama << endl;
            }

            int index;
            cout << "Masukkan nomor maahsiswa yang ingin dihapus: ";
            cin >> index;

            for (int i = index-1; i < panjang-1; i++)
            {   
                mahasiswa[i] = mahasiswa[i+1];
            }

            panjang--;
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