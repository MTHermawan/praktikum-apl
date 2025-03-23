#include <iostream>
#include <iomanip>
using namespace std;

#define MAX_DATA 100
#define SMOL_DATA 16

struct User
{
    int id;
    string username;
    string password;
    string level;
};

struct Game
{
    string nama;
    string genre[SMOL_DATA];
    int genreCount = 0;
};

struct Mod
{
    int id;
    Game game;
    string nama;
    string creator;
    User uploader;
    string deskripsi;
};

struct GabunganArray
{
    string genre;
    string platform;
    char riwayatHalaman;
};

int main()
{
    // Temp
    string _temp = "";

    // Database
    GabunganArray dataArray[MAX_DATA] = {
        {"Action", "Windows"},
        {"Adventure", "MacOS"},
        {"RPG", "Linux"},
        {"Simulation", "Android"},
        {"Indie", "IOS"}};
    int genreCount = 4;
    int platformCount = 5;
    int riwayatHalamanCount = 0;

    Game games[MAX_DATA] = {
        {"Stardew Valley", {"Simulation", "RPG", "Indie"}, 3},
        {"Undertale", {"RPG", "Indie"}, 2},
        {"Terraria", {"Action", "RPG"}, 2},
        {"Fallout 4", {"RPG"}, 1},
        {"Skyrim", {"RPG"}, 1}};
    int gameCount = 5;

    Mod mods[MAX_DATA] = {
        {1, {"Stardew Valley", {"Simulation", "RPG"}}, "Stardew Valley Expanded", "FlashShifter", {2, "user"}, "Stardew Valley Expanded is a fanmade expansion for ConcernedApe's Stardew Valley. This mod adds 28 new NPCs, 58 locations, 278 character events, 43 fish, reimagined vanilla areas, three farm maps, a reimagined world map reflecting all changes, new music, questlines, objects, crops, festivals, and many miscellaneous additions!"},
        {2, {"Undertale", {"RPG", "Indie"}}, "Undertale Bed Lump", "TheMaxine", {1, "Hermawan"}, "Based on that one 20-second gag from Undertale... the BED LUMP finally gets their own adventure.\n\nNo fighting. No thinking. No worrying. Only dancing. Get to the Barrier."},
        {3, {"Terraria", {"Action", "RPG"}}, "Calamity Mod", "Fabsol", {2, "user"}, "The Calamity Mod is a large content mod for Terraria which adds many hours of endgame content and dozens of enemies and bosses dispersed throughout the vanilla game's progression."}};
    int modCount = 3;

    User users[MAX_DATA] = {
        {1, "Hermawan", "2409106060", "admin"},
        {2, "user", "user123", "user"}};
    int userCount = 2;
    User emptyUser;
    User currentUser;

    // Data Login
    string inputUsername = "";
    string inputPassword = "";
    int batasPercobaan = 3;
    int percobaanGagal = 0;

    // Data Menu
    char halaman_menu = '0';
    string pilihan_menu = "";
    int i = 0;

    string selectedGenres[SMOL_DATA];
    int selectedGenreCount = 0;

    Game emptyGame;
    Game selectedGame;
    Game gameListMenu[MAX_DATA];
    int gameListMenuCount = 0;

    Mod emptyMod;
    Mod selectedMod;
    Mod modListMenu[MAX_DATA];
    int modListMenuCount = 0;

    while (_temp != "Q" && _temp != "q")
    {
        pilihan_menu = "";

        if (percobaanGagal >= batasPercobaan)
        {
            // Menghentikan user ketika mencapai batas percobaan login
            cout << "Anda melampaui batas percobaan login!" << endl;
            break;
        }

        // Border atas menu
        cout << endl
             << endl
             << endl;
        cout << "==========================================================================================================" << endl;

        if (currentUser.id <= 0)
        {
            // Sistem Login
            cout << "Sistem Pengelolaan Mod" << endl;
            cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
            cout << "1 > Login" << endl;
            cout << "2 > Register" << endl;
            cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
            cout << "Q > Keluar" << endl;
            cout << endl;
            cout << "Pilih Menu\t: ";
            getline(cin, _temp);
            cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
            if (_temp == "1")
            {
                // Login
                cout << "Login" << endl;
                cout << endl;
                do
                {
                    cout << "Username\t: ";
                    getline(cin, inputUsername);
                    if (inputUsername == "")
                        break;

                    cout << "Password\t: ";
                    getline(cin, inputPassword);
                    if (inputPassword == "")
                        break;

                    // Proses validasi login
                    for (int i = 0; i < userCount; i++)
                    {
                        if (inputUsername == users[i].username && inputPassword == users[i].password)
                        {
                            currentUser = users[i];
                            break;
                        }
                    }

                    if (currentUser.id > 0)
                    {
                        cout << "Login berhasil!" << endl;
                    }
                    else
                    {
                        percobaanGagal++;
                        cout << "Username atau Password salah!" << endl;
                    }
                    getline(cin, _temp);
                } while (percobaanGagal < batasPercobaan && currentUser.id <= 0);
            }
            else if (_temp == "2")
            {
                // Registrasi
                if (userCount < MAX_DATA)
                {
                    // Proses registrasi dapat berjalan selama user belum mencapai maks
                    User newUser;

                    cout << "Registrasi" << endl;
                    cout << endl;
                    cout << "Username\t: ";
                    getline(cin, newUser.username);

                    for (int i = 0; i < userCount; i++)
                    {
                        if (newUser.username != "" && newUser.username == users[i].username)
                        {
                            newUser.username = "";
                            cout << "Username sudah ada!";
                            getline(cin, _temp);
                            break;
                        }
                    }

                    if (newUser.username == "")
                        break;

                    cout << "Password\t: ";
                    getline(cin, newUser.password);

                    if (newUser.password == "")
                        break;

                    // Menambahkan user baru
                    newUser.id = userCount + 1;
                    newUser.level = "user";
                    users[userCount] = newUser;
                    userCount++;

                    cout << "Registrasi berhasil!";
                    getline(cin, _temp);
                    cout << endl;
                }
                else
                {
                    cout << "Registrasi gagal! Coba dalam beberapa saat lagi.";
                    getline(cin, _temp);
                }
            }
            else if (_temp == "Q" && _temp == "q")
            {
                pilihan_menu = _temp;
            }
            else
            {
                cout << "Menu tidak ditemukan!";
                getline(cin, _temp);
            }
        }
        else
        {
            // Setup sistem riwayat halaman
            if (riwayatHalamanCount < 1)
            {
                dataArray[0].riwayatHalaman = '0';
                riwayatHalamanCount = 1;
            }
            else if (dataArray[riwayatHalamanCount - 1].riwayatHalaman != halaman_menu)
            {
                dataArray[riwayatHalamanCount].riwayatHalaman = halaman_menu;
                riwayatHalamanCount++;
            }

            // Menu Setelah Login
            switch (halaman_menu)
            {
            case '0':
                // Menu Utama
                cout << "Menu Utama" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Selamat datang, " << currentUser.username << "!" << endl;
                cout << endl;
                cout << "1 > Games" << endl;
                cout << "2 > Mods" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | L > Logout" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);

                if (_temp == "1")
                {
                    // Pindah ke Menu Games
                    halaman_menu = '1';
                }
                else if (_temp == "2")
                {
                    // Pindah ke Menu Mods
                    halaman_menu = '2';
                }
                else if ((_temp == "Q" || _temp == "q") || (_temp == "L" || _temp == "l"))
                {
                    pilihan_menu = _temp;
                }
                else
                {
                    cout << "Menu tidak ditemukan!";
                    getline(cin, _temp);
                }
                break;
            case '1':
                // Menu Game
                selectedGame = emptyGame;
                gameListMenuCount = 0;

                // Menduplikat data game
                for (int i = 0; i < gameCount; i++)
                {
                    gameListMenu[gameListMenuCount] = games[i];
                    gameListMenuCount++;
                }

                // Proses pemfilteran game
                i = 0;
                while (i < gameListMenuCount && selectedGenreCount > 0)
                {
                    bool genreDitemukan = false;

                    // Mencocokkan Genre
                    for (int j = 0; j < gameListMenu[i].genreCount; j++)
                    {
                        for (int k = 0; k < selectedGenreCount; k++)
                        {
                            if (gameListMenu[i].genre[j] == selectedGenres[k])
                            {
                                genreDitemukan = true;
                                break;
                            }
                        }
                        if (genreDitemukan)
                            break;
                    }

                    // Mengeliminasi Game jika tidak memiliki Genre yang dicari
                    if (!genreDitemukan)
                    {
                        for (int l = i; l < MAX_DATA - 1; l++)
                        {
                            gameListMenu[l] = gameListMenu[l + 1];
                        }
                        gameListMenuCount--;
                    }
                    else
                        i++;
                }

                // Mengosongkan sisa data game
                for (int i = gameListMenuCount; i < sizeof(gameListMenu) / sizeof(Mod); i++)
                    gameListMenu[i] = emptyGame;

                // Menampilkan Menu Games
                cout << "Games" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                if (currentUser.level == "admin")
                {
                    cout << "C > Tambah Game | U > Edit Game | D > Hapus Game | ";
                }
                cout << "F > Filter Game" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                if (gameListMenuCount > 0)
                {
                    cout << left << setw(6) << "No."
                         << setw(40) << "Game"
                         << endl;
                    cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                    for (int i = 0; i < gameListMenuCount; i++)
                    {
                        cout << left << setw(4) << i + 1 << setw(2) << ">"
                             << setw(40) << gameListMenu[i].nama
                             << endl;
                    }
                }
                else
                {
                    cout << "Belum ada data game!" << endl;
                }
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | B > Kembali | L > Logout" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);

                // Mencari pilihan game
                for (int i = 0; i < gameCount; i++)
                {
                    if (to_string(i + 1) == _temp)
                    {
                        selectedGame = gameListMenu[i];
                        break;
                    }
                }

                if (selectedGame.nama != "")
                {
                    // Pindah ke Menu Mod yang terkait dengan game
                    halaman_menu = '2';
                    break;
                }

                // List Pilihan
                if (currentUser.level == "admin" && (_temp == "C" || _temp == "c"))
                {
                    // Tambah Game
                    Game gameBaru;

                    if (gameCount <= MAX_DATA)
                    {
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Tambah Game" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                        // Input Nama Game
                        cout << "Nama Game\t: ";
                        getline(cin, gameBaru.nama);

                        for (int i = 0; i < gameCount; i++)
                        {
                            if (gameBaru.nama != "" && games[i].nama == gameBaru.nama)
                            {
                                gameBaru.nama = "";
                                cout << "Game sudah ada!";
                                getline(cin, _temp);
                                break;
                            }
                        }

                        if (gameBaru.nama == "")
                            continue;

                        // Input Genre
                        while (true)
                        {
                            cout << "Genre" << endl;
                            for (int i = 0; i < genreCount; i++)
                            {
                                bool isSelected = false;
                                for (int j = 0; j < gameBaru.genreCount; j++)
                                {
                                    if (dataArray[i].genre == gameBaru.genre[j])
                                    {
                                        isSelected = true;
                                        break;
                                    }
                                }
                                cout << i + 1 << ". " << dataArray[i].genre << (isSelected ? " (Dipilih)" : "") << endl;
                            }

                            cout << endl;
                            cout << "(Kosongkan input untuk kembali.)" << endl;
                            cout << "Pilih Genre\t: ";
                            getline(cin, _temp);
                            cout << endl;

                            if (_temp == "")
                                break;

                            for (int i = 0; i < genreCount; i++)
                            {
                                bool isSelected = false;

                                if (to_string(i + 1) == _temp)
                                {
                                    for (int j = 0; j < gameBaru.genreCount; j++)
                                    {
                                        if (dataArray[i].genre == gameBaru.genre[j])
                                        {
                                            isSelected = true;
                                            for (int k = j; k < gameBaru.genreCount - 1; k++)
                                            {
                                                gameBaru.genre[k] = gameBaru.genre[k + 1];
                                            }
                                            gameBaru.genreCount--;
                                            break;
                                        }
                                    }

                                    if (isSelected)
                                        break;

                                    if (gameBaru.genreCount < SMOL_DATA)
                                    {
                                        gameBaru.genre[gameBaru.genreCount] = dataArray[i].genre;
                                        gameBaru.genreCount++;
                                    }
                                    else
                                    {
                                        cout << "Mencapai batas maksimum filter genre!";
                                        getline(cin, _temp);
                                    }
                                }
                            }
                        }

                        // Prsoses penambahan game
                        games[gameCount] = gameBaru;
                        gameCount++;
                        cout << "Game berhasil ditambahkan!";
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Game penuh! Tidak dapat menambah game lagi.";
                        getline(cin, _temp);
                    }
                }
                else if (currentUser.level == "admin" && _temp == "U" || _temp == "u")
                {
                    // Edit Game
                    int _selectedIndex = -1;

                    // Input pilihan game
                    cout << "Pilih Game\t: ";
                    getline(cin, _temp);

                    if (_temp == "")
                        continue;

                    for (int i = 0; i < gameListMenuCount; i++)
                    {
                        if (to_string(i + 1) == _temp)
                        {
                            for (int j = 0; j < gameCount; j++)
                            {
                                if (gameListMenu[i].nama == games[j].nama)
                                {
                                    _selectedIndex = j;
                                    break;
                                }
                            }
                            break;
                        }
                    }

                    if (gameCount > _selectedIndex >= 0)
                    {
                        // Lanjutkan proses edit game jika indeks valid
                        Game gameBaru = games[_selectedIndex];
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Edit Game \"" << games[_selectedIndex].nama << "\"" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                        // Input Nama Game
                        cout << "Nama Game Baru\t: ";
                        getline(cin, _temp);
                        cout << endl;

                        // Validasi nama game
                        for (int i = 0; i < gameCount; i++)
                        {
                            if (_temp != "" && games[i].nama == _temp)
                            {
                                _temp = "";
                                cout << "Game sudah ada!";
                                getline(cin, _temp);
                                break;
                            }
                        }

                        if (_temp != "")
                            gameBaru.nama = _temp;

                        // Input Genre
                        while (true)
                        {
                            cout << "Genre" << endl;
                            for (int i = 0; i < genreCount; i++)
                            {
                                bool isSelected = false;
                                for (int j = 0; j < gameBaru.genreCount; j++)
                                {
                                    if (dataArray[i].genre == gameBaru.genre[j])
                                    {
                                        isSelected = true;
                                        break;
                                    }
                                }
                                cout << i + 1 << ". " << dataArray[i].genre << (isSelected ? " (Dipilih)" : "") << endl;
                            }

                            cout << endl;
                            cout << "(Kosongkan input untuk kembali.)" << endl;
                            cout << "Pilih Genre\t: ";
                            getline(cin, _temp);
                            cout << endl;

                            if (_temp == "")
                                break;

                            for (int i = 0; i < genreCount; i++)
                            {
                                bool isSelected = false;

                                if (to_string(i + 1) == _temp)
                                {
                                    for (int j = 0; j < gameBaru.genreCount; j++)
                                    {
                                        if (dataArray[i].genre == gameBaru.genre[j])
                                        {
                                            isSelected = true;
                                            for (int k = j; k < gameBaru.genreCount - 1; k++)
                                            {
                                                gameBaru.genre[k] = gameBaru.genre[k + 1];
                                            }
                                            gameBaru.genreCount--;
                                            break;
                                        }
                                    }

                                    if (isSelected)
                                        break;

                                    if (gameBaru.genreCount < SMOL_DATA)
                                    {
                                        gameBaru.genre[gameBaru.genreCount] = dataArray[i].genre;
                                        gameBaru.genreCount++;
                                    }
                                    else
                                    {
                                        cout << "Mencapai batas maksimum filter genre!";
                                        getline(cin, _temp);
                                    }
                                }
                            }
                        }

                        // Proses perubahan data game
                        games[_selectedIndex] = gameBaru;
                        cout << "Game berhasil diperbarui!";
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Game tidak ditemukan!";
                        getline(cin, _temp);
                    }
                }
                else if (currentUser.level == "admin" && _temp == "D" || _temp == "d")
                {
                    // Hapus Game
                    int _selectedIndex = -1;

                    // Input pilihan game
                    cout << "Pilih Game\t: ";
                    getline(cin, _temp);

                    if (_temp == "")
                        continue;

                    for (int i = 0; i < gameListMenuCount; i++)
                    {
                        if (to_string(i + 1) == _temp)
                        {
                            for (int j = 0; j < gameCount; j++)
                            {
                                if (gameListMenu[i].nama == games[j].nama)
                                {
                                    _selectedIndex = j;
                                    break;
                                }
                            }
                            break;
                        }
                    }

                    if (gameCount > _selectedIndex >= 0)
                    {
                        // Lanjutkan proses penghapusan game jika indeks valid
                        cout << endl;
                        cout << "Apakah Anda yakin ingin menghapus \"" << games[_selectedIndex].nama << "\"? [Y/N]\t: ";
                        getline(cin, _temp);

                        if (_temp == "Y" || _temp == "y")
                        {
                            // Proses penghapusan game
                            for (int i = _selectedIndex; i < gameCount - 1; i++)
                            {
                                games[i] = games[i + 1];
                            }
                            gameCount--;
                            cout << "Game berhasil dihapus!";
                            getline(cin, _temp);
                        }
                        else
                        {
                            // Batalkan proses penghapusan game
                            cout << "Game dibatalkan dihapus!";
                            getline(cin, _temp);
                        }
                    }
                    else
                    {
                        cout << "Game tidak ditemukan!";
                        getline(cin, _temp);
                    }
                }
                else if (_temp == "F" || _temp == "f")
                {
                    // Pindah menu filter
                    halaman_menu = '3';
                    break;
                }
                else if ((_temp == "Q" || _temp == "q") || (_temp == "B" || _temp == "b") || (_temp == "L" || _temp == "l"))
                {
                    pilihan_menu = _temp;
                    break;
                }
                else
                {
                    cout << "Menu tidak ditemukan!";
                    getline(cin, _temp);
                }
                break;
            case '2':
                // Menu Mod
                selectedMod = emptyMod;
                modListMenuCount = 0;

                // Memfilter mod berdasarkan game yang dipilih
                for (int i = 0; i < modCount; i++)
                {
                    if (selectedGame.nama != "" && mods[i].game.nama != selectedGame.nama)
                        continue;

                    modListMenu[modListMenuCount] = mods[i];
                    modListMenuCount++;
                }

                // Mengosongkan sisa data mod
                for (int i = modListMenuCount; i < sizeof(modListMenu) / sizeof(Mod); i++)
                    modListMenu[i] = emptyMod;

                // Menampilkan Menu Mod
                if (selectedGame.nama != "")
                    cout << "Mod " << selectedGame.nama << endl;
                else
                    cout << "Semua Mod" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "C > Upload Mod" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                if (modListMenuCount > 0)
                {
                    // Daftar Mod
                    cout << left << setw(6) << "No."
                         << setw(40) << "Nama Mod"
                         << setw(40) << "Game"
                         << setw(20) << "Creator"
                         << endl;
                    cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                    for (int i = 0; i < modListMenuCount; i++)
                    {
                        cout << left << setw(4) << i + 1 << setw(2) << ">"
                             << setw(40) << modListMenu[i].nama
                             << setw(40) << modListMenu[i].game.nama
                             << setw(20) << modListMenu[i].creator
                             << endl;
                    }
                }
                else
                {
                    cout << "Belum ada data mod!" << endl;
                }
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | B > Kembali | L > Logout" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);

                // Pilih Mod
                for (int i = 0; i < modListMenuCount; i++)
                {
                    if (to_string(i + 1) == _temp)
                    {
                        selectedMod = modListMenu[i];
                    }
                }

                if (selectedMod.id > 0)
                {
                    halaman_menu = '4';
                    break;
                }

                // List Pilihan
                if (_temp == "C" || _temp == "c")
                {
                    // Upload Mod
                    if (modCount < MAX_DATA)
                    {
                        // Tambahkan mod jika belum penuh
                        Mod modBaru;

                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "Upload Mod" << endl;
                        cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                        cout << "(Kosongkan input untuk kembali.)" << endl;

                        // Input nama mod
                        cout << "Nama Mod\t: ";
                        getline(cin, modBaru.nama);
                        cout << endl;

                        // Validasi nama mod
                        for (int i = 0; i < modCount; i++)
                        {
                            if (modBaru.nama != "" && modBaru.nama == mods[i].nama)
                            {
                                modBaru.nama = "";
                                cout << "Nama mod sudah ada!";
                                getline(cin, _temp);
                                break;
                            }
                        }

                        if (modBaru.nama == "")
                            continue;

                        // Input creator
                        cout << "Creator\t\t: ";
                        getline(cin, modBaru.creator);
                        cout << endl;

                        if (modBaru.creator == "")
                            continue;

                        // Input pilihan game
                        cout << "Game" << endl;
                        for (int i = 0; i < gameCount; i++)
                            cout << i + 1 << ". " << games[i].nama << endl;
                        cout << "Pilih Game\t: ";
                        getline(cin, _temp);
                        cout << endl;

                        if (_temp == "")
                            continue;

                        // Mencari dan validasi game yang dipilih
                        for (int i = 0; i < gameCount; i++)
                        {
                            if (to_string(i + 1) == _temp)
                            {
                                modBaru.game = games[i];
                                break;
                            }
                        }

                        if (modBaru.game.nama == "")
                        {
                            cout << "Game tidak ditemukan!";
                            getline(cin, _temp);
                            continue;
                        }

                        // Input deskripsi
                        cout << "Deskripsi\t: ";
                        getline(cin, modBaru.deskripsi);
                        cout << endl;

                        if (modBaru.deskripsi == "")
                            continue;

                        // Proses penambahan mod
                        modBaru.id += 1;
                        modBaru.uploader = currentUser;
                        mods[modCount] = modBaru;
                        modCount++;
                        cout << "Mod berhasil diupload!";
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Mod penuh! Tidak dapat mengupload mod lagi.";
                        getline(cin, _temp);
                    }
                }
                else if ((_temp == "Q" || _temp == "q") || (_temp == "B" || _temp == "b") || (_temp == "L" || _temp == "l"))
                {
                    pilihan_menu = _temp;
                    break;
                }
                else
                {
                    cout << "Menu tidak ditemukan!";
                    getline(cin, _temp);
                }
                break;
            case '3':
                // Filter Game
                cout << "Filter Game" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "1. Genre" << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | B > Kembali | L > Logout" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                // List Pilihan
                if (_temp == "1")
                {
                    // Filter Genre
                    while (true)
                    {
                        // Menampilkan daftar genre
                        cout << "Genre" << endl;
                        for (int i = 0; i < genreCount; i++)
                        {
                            bool isSelected = false;
                            for (int j = 0; j < SMOL_DATA; j++)
                            {
                                if (dataArray[i].genre == selectedGenres[j])
                                {
                                    isSelected = true;
                                    break;
                                }
                            }
                            cout << i + 1 << ". " << dataArray[i].genre << (isSelected ? " (Dipilih)" : "") << endl;
                        }

                        cout << endl;
                        cout << "(Kosongkan input untuk kembali.)" << endl;
                        cout << "Pilih Genre\t: ";
                        getline(cin, _temp);

                        if (_temp == "")
                            break;

                        for (int i = 0; i < genreCount; i++)
                        {
                            bool isSelected = false;

                            if (to_string(i + 1) == _temp)
                            {
                                // Mengeliminasi genre jika sudah dipilih
                                for (int j = 0; j < SMOL_DATA; j++)
                                {
                                    if (dataArray[i].genre == selectedGenres[j])
                                    {
                                        isSelected = true;
                                        for (int k = j; k < SMOL_DATA - 1; k++)
                                        {
                                            selectedGenres[k] = selectedGenres[k + 1];
                                        }
                                        selectedGenreCount--;
                                        break;
                                    }
                                }

                                // Menambahkan genre jika belum dipilih
                                if (isSelected)
                                    break;

                                if (selectedGenreCount < SMOL_DATA)
                                {
                                    selectedGenres[selectedGenreCount] = dataArray[i].genre;
                                    selectedGenreCount++;
                                }
                                else
                                {
                                    cout << "Mencapai batas maksimum filter genre!";
                                    getline(cin, _temp);
                                }
                            }
                        }
                    }
                }
                else if ((_temp == "Q" || _temp == "q") || (_temp != "B" || _temp != "b") || (_temp == "L" || _temp == "l"))
                {
                    pilihan_menu = _temp;
                }
                else
                {
                    cout << "Menu tidak ditemukan!";
                    getline(cin, _temp);
                }
                break;
            case '4':
                // Detail Mod
                if (selectedMod.id < 1)
                {
                    halaman_menu = '2';
                    break;
                }

                // Menampilkan detail mod terpilih
                cout << selectedMod.nama << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                if (currentUser.id == selectedMod.uploader.id)
                {
                    cout << "U > Edit | D > Hapus" << endl;
                    cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                }
                else if (currentUser.level == "admin")
                {
                    cout << "D > Hapus" << endl;
                    cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                }
                cout << "Creator\t\t: " << selectedMod.creator << endl;
                cout << "Uploader\t: " << selectedMod.uploader.username << endl;
                cout << "Game\t\t: " << selectedMod.game.nama << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << selectedMod.deskripsi << endl;
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;
                cout << "Q > Keluar | B > Kembali | L > Logout" << endl;
                cout << endl;
                cout << "Pilih Menu\t: ";
                getline(cin, _temp);
                cout << "──────────────────────────────────────────────────────────────────────────────────────────────────────────" << endl;

                if (currentUser.id == selectedMod.uploader.id && (_temp == "U" || _temp == "u"))
                {
                    // Edit Mod terpilih
                    cout << "(Kosongkan untuk melewati salah satu pengeditan.)" << endl;
                    cout << "Nama Baru\t:";
                    getline(cin, _temp);

                    for (int i = 0; i < modCount; i++)
                    {
                        if (_temp != "" && mods[i].nama == _temp)
                        {
                            _temp = "";
                            cout << "Nama mod sudah ada!";
                            getline(cin, _temp);
                            break;
                        }
                    }

                    if (_temp != "")
                        selectedMod.nama = _temp;

                    cout << "Creator Baru\t:";
                    getline(cin, _temp);
                    
                    if (_temp != "")
                        selectedMod.creator = _temp;

                    cout << "Deskripsi Baru\t:";
                    getline(cin, _temp);
                    
                    if (_temp != "")
                        selectedMod.deskripsi = _temp;

                    for (int i = 0; i < modCount; i++)
                    {
                        if (mods[i].id == selectedMod.id)
                        {
                            mods[i] = selectedMod;
                        }
                    }

                    cout << "Mod berhasil diperbarui!";
                    getline(cin, _temp);
                }
                else if ((currentUser.id == selectedMod.uploader.id || currentUser.level == "admin") && (_temp == "D" || _temp == "d"))
                {
                    // Menghapus Mod saat ini
                    cout << "Apakah Anda yakin ingin menghapus mod \"" << selectedMod.nama << "\"? [Y/N] ";
                    getline(cin, _temp);

                    if (_temp == "")
                        break;
                    else if (_temp == "Y" || _temp == "y")
                    {
                        // Proses penghapusan mod
                        for (int i = 0; i < modCount; i++)
                        {
                            if (mods[i].id == selectedMod.id)
                            {
                                for (int j = i; j < modCount; j++)
                                {
                                    mods[j] = mods[j + 1];
                                }
                                modCount--;
                                break;
                            }
                        }
                        cout << "Mod berhasil dihapuskan!";
                        getline(cin, _temp);
                        selectedMod = emptyMod;
                        halaman_menu = '2';
                    }
                    else if (_temp == "N" || _temp == "n")
                    {
                        // Batalkan penghapusan mod
                        cout << "Mod batal dihapuskan!";
                        getline(cin, _temp);
                    }
                    else
                    {
                        cout << "Input tidak valid!";
                        getline(cin, _temp);
                    }
                }
                else if ((_temp == "Q" || _temp == "q") || (_temp == "B" || _temp == "b") || (_temp == "L" || _temp == "l"))
                {
                    pilihan_menu = _temp;
                    break;
                }
                else
                {
                    cout << "Menu tidak ditemukan!";
                    getline(cin, _temp);
                }
                break;
            default:
                halaman_menu = '0';
                break;
            }

            if (pilihan_menu == "Q" || pilihan_menu == "q")
            {
                currentUser = emptyUser;
            }
            else if (pilihan_menu == "B" || pilihan_menu == "b" && riwayatHalamanCount > 1)
            {
                riwayatHalamanCount--;
                halaman_menu = dataArray[riwayatHalamanCount - 1].riwayatHalaman;
            }
            else if (pilihan_menu == "L" || pilihan_menu == "l")
            {
                // Logout
                currentUser = emptyUser;
                percobaanGagal = 0;
                riwayatHalamanCount = 0;
                halaman_menu = '0';
            }
        }

        cout << "==========================================================================================================" << endl;
    }

    cout << endl;
    cout << "Program dihentikan...!" << endl;

    return 0;
}