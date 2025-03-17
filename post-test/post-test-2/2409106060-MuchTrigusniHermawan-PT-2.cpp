#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_DATA 100
#define SMOL_DATA 10

int main()
{
    // Temp
    string _temp = "";
    

    // Database
    string games[MAX_DATA][2] = {
        {"1", "Stardew Valley"},
        {"2", "Undertale"},
        {"3", "Terraria"},
        {"4", "Fallout 4"},
        {"5", "Skyrim"}};
    int gameCount = 5;

    string mods[MAX_DATA][4] = {
        // id, idGame, nama, creator
        {"1", "2", "Undertale Bed Lump", "TheMaxine"},
        {"2", "3", "Calamity Mod", "Fabsol"},
        {"3", "1", "Stardew Valley Expanded", "FlashShifter"}};
    int modCount = 3;

    // Data Pengguna
    string username = "Hermawan";
    string password = "2409106060";
    bool isLogin = false;

    // Data Login
    string inputUsername = "";
    string inputPassword = "";
    int batasPercobaan = 3;
    int percobaan = 0;
    do
    {
        percobaan++;
        cout << endl;
        cout << "Username\t: ";
        getline(cin, inputUsername);
        cout << "Password\t: ";
        getline(cin, inputPassword);

        if (inputPassword != password || inputUsername != username)
        {
            cout << "Username atau Password salah!" << endl;
            getline(cin, _temp);
        }
        else
        {
            cout << "Login berhasil!" << endl;
            isLogin = true;
            getline(cin, _temp);
        }
    } while (percobaan < batasPercobaan && !isLogin);

    if (isLogin)
    {
        // Sistem Pengelolaan Video Game Modding
        string menu = "0";
        string selectedGame = "";
        string selectedMod = "";

        while (isLogin)
        {
            _temp = "";
            cout << endl
                 << endl
                 << endl;
            cout << "==========================================================================================================" << endl;

            if (menu == "0")
            {
                // Menu Utama
                cout << "Menu Utama" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "1 > Games" << endl;
                cout << "2 > Mods" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);

                if (_temp == "1")
                {
                    menu = "1";
                }
                else if (_temp == "2")
                {
                    menu = "2";
                }
                else if (_temp == "Q" || _temp == "q")
                {
                    isLogin = false;
                }
                else
                {
                    cout << "Menu tidak ditemukan!" << endl;
                    getline(cin, _temp);
                }
            }
            else if (menu == "1")
            {
                // Games
                cout << "Games" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "C > Tambah Game | U > Edit Game | D > Hapus Game" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                if (gameCount > 0)
                {
                    cout << left << setw(6) << "No."
                         << setw(40) << "Game"
                         << endl;
                    cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                    for (int i = 0; i < gameCount; i++)
                    {
                        cout << left << setw(4) << i + 1 << setw(2) << ">"
                             << setw(40) << games[i][1]
                             << endl;
                    }
                }
                else
                {
                    cout << "Belum ada data game!" << endl;
                }
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | B > Kembali" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);

                if (_temp == "C" || _temp == "c")
                {
                    // Tambah Game
                    if (gameCount <= MAX_DATA)
                    {
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Tambah Game" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Nama Game\t: ";
                        getline(cin, _temp);
                        games[gameCount][0] = to_string(gameCount + 1);
                        games[gameCount][1] = _temp;
                        gameCount++;
                        cout << "Game berhasil ditambahkan!" << endl;
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Game penuh! Tidak dapat menambah game lagi." << endl;
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "U" || _temp == "u")
                {
                    // Edit Game
                    int _selectedIndex = -1;

                    cout << "Pilih Game\t: ";
                    getline(cin, _temp);
                    for (int i = 0; i < gameCount; i++)
                    {
                        if (to_string(i + 1) == _temp)
                        {
                            _selectedIndex = i;
                            break;
                        }
                    }

                    if (_selectedIndex >= 0)
                    {
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Edit Game \"" << games[_selectedIndex][1] << "\"" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Nama Game Baru\t: ";
                        getline(cin, _temp);
                        games[_selectedIndex][1] = _temp != "" ? _temp : games[_selectedIndex][1];
                        cout << "Game berhasil diperbarui!" << endl;
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Game tidak ditemukan!" << endl;
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "D" || _temp == "d")
                {
                    // Hapus Game
                    int _selectedIndex = -1;

                    cout << "Pilih Game\t: ";
                    getline(cin, _temp);
                    for (int i = 0; i < gameCount; i++)
                    {
                        if (to_string(i + 1) == _temp)
                        {
                            _selectedIndex = i;
                            break;
                        }
                    }

                    if (_selectedIndex >= 0)
                    {
                        cout << endl;
                        cout << "Apakah Anda yakin ingin menghapus \"" << games[_selectedIndex][1] << "\"? (Y/N)\t: ";
                        getline(cin, _temp);

                        if (_temp == "Y" || _temp == "y")
                        {
                            for (int i = _selectedIndex; i < gameCount - 1; i++)
                            {
                                games[i][0] = games[i + 1][0];
                                games[i][1] = games[i + 1][1];
                            }
                            gameCount--;
                            cout << "Game berhasil dihapus!" << endl;
                            getline(cin, _temp);
                        }
                        else
                        {
                            cout << "Game dibatalkan dihapus!" << endl;
                            getline(cin, _temp);
                        }
                    }
                    else
                    {
                        cout << "Game tidak ditemukan!" << endl;
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "B" || _temp == "b")
                {
                    menu = "0";
                }
                else if (_temp == "Q" || _temp == "q")
                {
                    isLogin = false;
                }
                else
                {
                    cout << "Menu tidak ditemukan!" << endl;
                    getline(cin, _temp);
                }
            }
            else if (menu == "2")
            {
                // Mods
                cout << "Mods" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "C > Upload Mod | U > Edit Mod | D > Hapus Mod" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                if (modCount > 0)
                {
                    cout << left << setw(6) << "No."
                         << setw(40) << "Nama Mod"
                         << setw(40) << "Game"
                         << setw(20) << "Creator"
                         << endl;
                    cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                    for (int i = 0; i < modCount; i++)
                    {
                        string game = "";
                        for (int j = 0; j < gameCount; j++)
                        {
                            if (mods[i][1] == games[j][0])
                            {
                                game = games[j][1];
                                break;
                            }
                        }

                        cout << left << setw(4) << i + 1 << setw(2) << ">"
                             << setw(40) << mods[i][2]
                             << setw(40) << game
                             << setw(20) << mods[i][3]
                             << endl;
                    }
                }
                else
                {
                    cout << "Belum ada data mod!" << endl;
                }
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | B > Kembali" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);

                if (_temp == "C" || _temp == "c")
                {
                    // Upload Mod
                    if (modCount < MAX_DATA)
                    {
                        string tempName = "";
                        int tempIndexGame = -1;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Upload Mod" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Nama Mod\t: ";
                        getline(cin, tempName);
                        cout << endl;
                        for (int i = 0; i < gameCount; i++)
                        {
                            cout << i + 1 << ". " << games[i][1] << endl;
                        }
                        cout << "Pilih Game\t: ";
                        getline(cin, _temp);
                        cout << endl;

                        if (_temp == "")
                            continue;

                        for (int i = 0; i < gameCount; i++)
                        {
                            if (to_string(i + 1) == _temp)
                            {
                                tempIndexGame = i;
                                break;
                            }
                        }

                        if (tempIndexGame >= 0)
                        {
                            mods[modCount][0] = to_string(modCount + 1);
                            mods[modCount][1] = games[tempIndexGame][0];
                            mods[modCount][2] = tempName;
                            mods[modCount][3] = username;
                            modCount++;
                            cout << "Mod berhasil diupload!" << endl;
                            getline(cin, _temp);
                        }
                        else
                        {
                            cout << "Game tidak ditemukan!" << endl;
                            getline(cin, _temp);
                        }
                    }
                    else
                    {
                        cout << "Mod penuh! Tidak dapat mengupload mod lagi." << endl;
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "U" || _temp == "u")
                {
                    // Edit Mod
                    int _selectedIndex = -1;

                    cout << "Pilih Mod\t: ";
                    getline(cin, _temp);
                    for (int i = 0; i < modCount; i++)
                    {
                        if (to_string(i + 1) == _temp)
                        {
                            _selectedIndex = i;
                            break;
                        }
                    }

                    if (_selectedIndex >= 0)
                    {
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Edit Mod \"" << mods[_selectedIndex][2] << "\"" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Nama Mod Baru\t: ";
                        getline(cin, _temp);
                        if (sizeof(_temp) > 37)
                        {
                            cout << "Nama Mod terlalu panjang!" << endl;
                            getline(cin, _temp);
                            continue;
                        }
                        cout << endl;

                        mods[_selectedIndex][2] = _temp != "" ? _temp : mods[_selectedIndex][2];
                        cout << "Game berhasil diperbarui!" << endl;
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Mod tidak ditemukan!" << endl;
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "D" || _temp == "d")
                {
                    // Hapus Mod
                    int _selectedIndex = -1;

                    cout << "Pilih Mod\t: ";
                    getline(cin, _temp);
                    for (int i = 0; i < modCount; i++)
                    {
                        if (to_string(i + 1) == _temp)
                        {
                            _selectedIndex = i;
                            break;
                        }
                    }

                    if (_selectedIndex >= 0)
                    {
                        cout << endl;
                        cout << "Apakah Anda yakin ingin menghapus \"" << mods[_selectedIndex][2] << "\"? (Y/N)\t: ";
                        getline(cin, _temp);

                        if (_temp == "Y" || _temp == "y")
                        {
                            for (int i = _selectedIndex; i < modCount - 1; i++)
                            {
                                mods[i][0] = mods[i + 1][0];
                                mods[i][1] = mods[i + 1][1];
                                mods[i][2] = mods[i + 1][2];
                                mods[i][3] = mods[i + 1][3];
                            }
                            modCount--;
                            cout << "Mod berhasil dihapus!" << endl;
                            getline(cin, _temp);
                        }
                        else
                        {
                            cout << "Mod dibatalkan dihapus!" << endl;
                            getline(cin, _temp);
                        }
                    }
                    else
                    {
                        cout << "Mod tidak ditemukan!" << endl;
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "B" || _temp == "b")
                {
                    menu = "0";
                }
                else if (_temp == "Q" || _temp == "q")
                {
                    isLogin = false;
                }
                else
                {
                    cout << "Menu tidak ditemukan!" << endl;
                    getline(cin, _temp);
                }
            }
            else
            {
                menu = "0";
            }
            cout << "==========================================================================================================" << endl;
        }
    }

    cout << endl;
    cout << "Program dihentikan...!" << endl;

    return 0;
}