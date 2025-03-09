#include <iostream>
using namespace std;

int main()
{
    // Data Pengguna
    string pin = "6060";
    double saldo = 606060;
    bool isBlokir = false;
    bool isLogin = false;

    // Jangan menyimpan di variabel ini
    string temp = "";

    // Data Menu
    string menu = "";
    string _menuMessage = "";
    string _invalidMessage = "";
    bool isMenuMessage = false;
    bool isInvalid = false;

    // Data Login
    string inputPin = "";
    int batasPercobaan = 3;
    int percobaan = 0;

    do
    {
        percobaan++;
        cout << endl;
        cout << "Masukkan PIN: ";
        getline(cin, inputPin);

        if (inputPin != pin)
        {
            // PIN tidak cocok, tampilkan pesan dan cek kelayakan diblokir
            cout << "PIN salah!" << endl;
            isBlokir = percobaan >= batasPercobaan;
        }
        else
        {
            // PIN cocok, tampilkan pesan dan set login untuk ke Menu ATM
            _menuMessage = "Login berhasil!";
            isMenuMessage = true;
            isLogin = true;
        }
    } while (!isBlokir && !isLogin);

    if (isBlokir)
    {
        // Status akun diblokir, tampilkan pesan diblokir
        cout << "Akun Anda diblokir!" << endl;
    }
    else
    {
        // Status akun aktif dan berhasil Login, maka tampilkan menu ATM
        while (isLogin)
        {
            // Menu ATM
            menu = "";
            temp = "";
            
            cout << endl;
            cout << "========================" << endl;
            if (isMenuMessage)
                cout << _menuMessage << endl;
            cout << endl;
            cout << "1 > Setor Tunai" << endl;
            cout << "2 > Cek Saldo" << endl;
            cout << "3 > Tarik Tunai" << endl;
            cout << "0 > Keluar" << endl;
            cout << endl;
            cout << "Pilih menu: ";
            cin >> menu;
            cout << endl;

            isMenuMessage = false;
            isInvalid = false;

            if (menu == "1")
            {
                // 1. Menu Setor Tunai
                double nominalSetor;

                while (true)
                {
                    cout << "========================" << endl;
                    cout << "Setor Tunai" << endl;
                    cout << endl;
                    cout << "Masukkan jumlah nominal yang disetorkan (0 > Kembali): " << endl;
                    if (isInvalid)
                    {
                        // Jika sebelumnya melakukan input yang tidak valid, tampilkan pesan
                        cout << _invalidMessage << endl;
                    } 
                    cout << endl;
                    cout << "Rp";
                    cin >> nominalSetor;

                    if (nominalSetor == 0)
                    {
                        // Kembali ke Menu ATM
                        break;
                    }
                    else if (nominalSetor < 1000)
                    {
                        // Jika nominal kurang dari 1000, tampilkan pesan nominal tidak valid
                        _invalidMessage = "Minimal nominal yang bisa disetorkan adalah Rp1000!";
                        isInvalid = true;
                    }
                    else if (nominalSetor >= 1000)
                    {
                        // Jika nominal lebih dari atau sama dengan 1000, maka saldo ditambahkan
                        saldo += nominalSetor;
                        _menuMessage = "Saldo berhasil disetorkan!";
                        isMenuMessage = true;
                        break;
                    }
                    else
                    {
                        // Kondisi lainnya jika nominal tidak valid
                        _invalidMessage = "Nominal tidak valid!";
                        isInvalid = true;
                    }
                    cout << endl;
                }
            }
            else if (menu == "2")
            {
                // 2. Menu Cek Saldo
                while (temp != "0")
                {
                    cout << "========================" << endl;
                    cout << "Saldo Rekening Anda: " << endl;
                    cout << "Rp" << saldo << endl;
                    cout << endl;
                    cout << "0 > Kembali: " << endl;
                    cout << endl;
                    cout << "Pilih Menu: ";
                    cin >> temp;

                    if (temp != "0")
                        cout << "Menu tidak tersedia!" << endl;
                    cout << endl;
                }
            }
            else if (menu == "3")
            {
                // 3. Menu Tarik Tunai
                double nominalTarik;
                bool isInvalid = false;
                string _invalidMessage = "";

                while (true)
                {
                    cout << "========================" << endl;
                    cout << "Tarik Tunai" << endl;
                    cout << endl;
                    cout << "Masukkan jumlah nominal yang ditarik: " << endl;
                    if (isInvalid)
                    {
                        // Jika sebelumnya melakukan input yang tidak valid, tampilkan pesan
                        cout << _invalidMessage << endl;
                    }
                    cout << endl;
                    cout << "Saldo Rekening Anda: Rp" << saldo << endl;
                    cout << "Rp";
                    cin >> nominalTarik;

                    if (nominalTarik == 0)
                    {
                        // Kembali ke Menu ATM
                        break;
                    }
                    else if (nominalTarik < 1000)
                    {
                        // Jika nominal kurang dari 1000, tampilkan pesan nominal tidak valid
                        _invalidMessage = "Minimal nominal yang bisa ditarik adalah Rp1000!";
                        isInvalid = true;
                    }
                    else if (nominalTarik >= 1000)
                    {
                        // Jika nominal benar lebih atau sama dengan 1000
                        if (nominalTarik <= saldo)
                        {
                            // Jika saldo mencukupi, kurangi saldo akun dan tampilkan pesan
                            saldo -= nominalTarik;
                            _menuMessage = "Saldo berhasil ditarik!";
                            isMenuMessage = true;
                            break;
                        }
                        else
                        {
                            // Jika saldo tidak cukup, tampilkan pesan invalid
                            _invalidMessage = "Saldo tidak mencukupi!";
                            isInvalid = true;
                        }
                    }
                    else
                    {
                        // Kondisi lainnya jika nominal tidak valid
                        _invalidMessage = "Nominal tidak valid!";
                        isInvalid = true;
                    }
                    cout << endl;
                }
            }
            else if (menu == "0")
            {
                // 0. Menu Keluar
                isLogin = false;
                cout << "Keluar dari program..." << endl;
            }
            else
            {
                // Menu tidak ada di pilihan, tampilkan pesan menu tidak tersedia
                cout << "Menu tidak tersedia!" << endl;
                menu = "0";
            }
        }
    }

    return 0;
}