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

User users[MAX_DATA] = {
    {1, "Hermawan", "2409106060", "admin"},
    {2, "user", "user123", "user"}};
int userCount = 2;
User currentUser = User();

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

// -- Fungsi dan Prosedur --

// Rekursif
void Border(string lineType, int length, int count = 0)
{
    if (length < 1)
    {
        return;
    }
    else
    {
        Border("─", length-1, count+1);
        cout << lineType;
    }
    
    if (count == 0)
        cout << endl;
}

// Overloading
void Border(string title)
{
    cout << title << endl;
    Border("─", 106);
}

User GetUserLogin(User users[], int userCount, string username, string password)
{
    for (int i = 0; i < userCount; i++)
    {
        if (users[i].username == username && users[i].password == password)
            return users[i];
    }
    return User();
}

void PilihanCheckbox(string selectedData[], int &selectedDataCount, string options[], int optionCount, string title) {
    string _temp;
    int selectedIndex = -1;

    while (true)
    {
        cout << title << endl;
        for (int i = 0; i < optionCount; i++)
        {
            bool isSelected = false;
            
            for (int j = 0; j < selectedDataCount; j++)
            {
                if (options[i] == selectedData[j])
                {
                    isSelected = true;
                    break;
                }
            }
            cout << i + 1 << ". " << options[i] << (isSelected ? " (Dipilih)" : "") << endl;
        }

        cout << endl;
        cout << "(Kosongkan input untuk mengakhiri pilihan.)" << endl;
        cout << "Pilih pilihan: ";
        getline(cin, _temp);

        if (_temp == "")
            break;

        for (int i = 0; i < optionCount; i++)
        {
            if (to_string(i + 1) == _temp)
            {
                selectedIndex = i;
                break;
            }
        }

        if (selectedIndex >= 0 && selectedIndex < optionCount)
        {
            bool alreadySelected = false;

            for (int i = 0; i < selectedDataCount; i++)
            {
                if (selectedData[i] == options[selectedIndex])
                {
                    for (int j = i; j < selectedDataCount - 1; j++)
                    {
                        selectedData[j] = selectedData[j + 1];
                    }

                    selectedDataCount--;
                    alreadySelected = true;
                    break;
                }
            }

            if (!alreadySelected && selectedDataCount < SMOL_DATA)
            {
                selectedData[selectedDataCount] = options[selectedIndex];
                selectedDataCount++;
            }
        } 
        else
        {
            cout << "Pilihan tidak valid!" << endl;
        }
    }
}

// -- Prosedur Menu --
void Login(int &batasPercobaan, int &percobaanGagal)
{
    string inputUsername = "";
    string inputPassword = "";

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
        currentUser = GetUserLogin(users, userCount, inputUsername, inputPassword);

        if (currentUser.id > 0)
        {
            cout << "Login berhasil!" << endl;
        }
        else
        {
            percobaanGagal++;
            cout << "Username atau Password salah!" << endl;
        }
    } while (percobaanGagal < batasPercobaan && currentUser.id <= 0);
}

void Register()
{
    User newUser;
    string _temp = "";

    if (userCount < MAX_DATA)
    {
        // Proses registrasi dapat berjalan jika user belum mencapai maks
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
                return;
            }
        }

        if (newUser.username == "")
            return;

        cout << "Password\t: ";
        getline(cin, newUser.password);

        if (newUser.password == "")
            return;

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

// Sistem Login
void MenuSistemLogin(int &batasPercobaan, int &percobaanGagal)
{
    string _temp;

    // Sistem Login
    Border("Sistem Pengelolaan Mod");
    
    cout << "1 > Login" << endl;
    cout << "2 > Register" << endl;
    Border("─", 106);
    cout << "Q > Keluar" << endl;
    cout << endl;
    cout << "Pilih Menu\t: ";
    getline(cin, _temp);
    Border("─", 106);
    if (_temp == "1")
    {
        Login(batasPercobaan, percobaanGagal);
    }
    else if (_temp == "2")
    {
        Register();
    }
    else if (_temp != "Q" && _temp != "q")
    {
        cout << "Menu tidak ditemukan!";
        getline(cin, _temp);
    }
}

void MenuUtama(char &halaman, string &pilihan_menu)
{
    string _temp = "";

    // Menu Utama
    cout << "Menu Utama" << endl;
    Border("─", 106);
    cout << "Selamat datang, " << currentUser.username << "!" << endl;
    cout << endl;
    cout << "1 > Games" << endl;
    cout << "2 > Mods" << endl;
    Border("─", 106);
    cout << "Q > Keluar | L > Logout" << endl;
    cout << endl;
    cout << "Pilih Menu\t: ";
    getline(cin, _temp);

    if (_temp == "1")
    {
        halaman = '1';
    }
    else if (_temp == "2")
    {
        halaman = '2';
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
}

void TambahGame()
{
    string _temp = "";
    Game gameBaru;

    if (gameCount <= MAX_DATA)
    {
        Border("─", 106);
        cout << "Tambah Game" << endl;
        Border("─", 106);

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
            return;

        // Input Genre
        string genres[SMOL_DATA];
        for (int i = 0; i < genreCount; i++)
        {
            genres[i] = dataArray[i].genre;
        }
        PilihanCheckbox(gameBaru.genre, gameBaru.genreCount, genres, genreCount, "Genre");
        cout << endl;

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

void EditGame(Game gameListMenu[], int gameListMenuCount)
{
    string _temp = "";
    int _selectedIndex = -1;

    // Input pilihan game
    cout << "Pilih Game\t: ";
    getline(cin, _temp);

    if (_temp == "")
        return;

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
        Border("─", 106);
        cout << "Edit Game \"" << games[_selectedIndex].nama << "\"" << endl;
        Border("─", 106);

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
        string genres[SMOL_DATA];
        for (int i = 0; i < genreCount; i++)
        {
            genres[i] = dataArray[i].genre;
        }
        PilihanCheckbox(gameBaru.genre, gameBaru.genreCount, genres, genreCount, "Genre");
        cout << endl;

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

void HapusGame(Game gameListMenu[], int gameListMenuCount)
{
    string _temp = "";
    int _selectedIndex = -1;

    // Input pilihan game
    cout << "Pilih Game\t: ";
    getline(cin, _temp);

    if (_temp == "")
        return;

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

void MenuGame(char &halaman, string &pilihan_menu, Game &selectedGame, string selectedGenres[], int &selectedGenreCount)
{
    string _temp;
    int i;

    Game gameListMenu[MAX_DATA];
    int gameListMenuCount = 0;

    selectedGame = Game();

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
        gameListMenu[i] = Game();

    // Menampilkan Menu Games
    cout << "Games" << endl;
    Border("─", 106);
    if (currentUser.level == "admin")
    {
        cout << "C > Tambah Game | U > Edit Game | D > Hapus Game | ";
    }
    cout << "F > Filter Game" << endl;
    Border("─", 106);
    if (gameListMenuCount > 0)
    {
        cout << left << setw(6) << "No."
             << setw(40) << "Game"
             << endl;
        Border("─", 106);

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
    Border("─", 106);
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
        halaman = '2';
        return;
    }

    // List Pilihan
    if (currentUser.level == "admin" && (_temp == "C" || _temp == "c"))
    {
        // Tambah Game
        TambahGame();
    }
    else if (currentUser.level == "admin" && _temp == "U" || _temp == "u")
    {
        // Edit Game
        EditGame(gameListMenu, gameListMenuCount);
    }
    else if (currentUser.level == "admin" && _temp == "D" || _temp == "d")
    {
        // Hapus Game
        HapusGame(gameListMenu, gameListMenuCount);
    }
    else if (_temp == "F" || _temp == "f")
    {
        // Pindah menu filter
        halaman = '3';
        return;
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
}

void MenuFilterGame(char &halaman, string &pilihan_menu, string selectedGenres[], int &selectedGenreCount)
{
    string _temp = "";

    cout << "Filter Game" << endl;
    Border("─", 106);
    cout << "1. Genre" << endl;
    Border("─", 106);
    cout << "Q > Keluar | B > Kembali | L > Logout" << endl;
    cout << endl;
    cout << "Pilih Menu\t: ";
    getline(cin, _temp);
    Border("─", 106);

    // List Pilihan
    if (_temp == "1")
    {
        // Filter Genre
        string genres[SMOL_DATA];
        for (int i = 0; i < genreCount; i++)
        {
            genres[i] = dataArray[i].genre;
        }
        PilihanCheckbox(selectedGenres, selectedGenreCount, genres, genreCount, "Genre");
        cout << endl;
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
}

void UploadMod()
{
    string _temp = "";

    if (modCount < MAX_DATA)
    {
        // Tambahkan mod jika belum penuh
        Mod modBaru;

        Border("─", 106);
        cout << "Upload Mod" << endl;
        Border("─", 106);
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
            return;

        // Input creator
        cout << "Creator\t\t: ";
        getline(cin, modBaru.creator);
        cout << endl;

        if (modBaru.creator == "")
            return;

        // Input pilihan game
        cout << "Game" << endl;
        for (int i = 0; i < gameCount; i++)
            cout << i + 1 << ". " << games[i].nama << endl;
        cout << "Pilih Game\t: ";
        getline(cin, _temp);
        cout << endl;

        if (_temp == "")
            return;

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
            return;
        }

        // Input deskripsi
        cout << "Deskripsi\t: ";
        getline(cin, modBaru.deskripsi);
        cout << endl;

        if (modBaru.deskripsi == "")
            return;

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

void EditMod(Mod &selectedMod)
{
    string _temp = "";

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

void HapusMod(char &halaman, Mod &selectedMod)
{
    string _temp = "";
    // Menghapus Mod saat ini
    cout << "Apakah Anda yakin ingin menghapus mod \"" << selectedMod.nama << "\"? [Y/N] ";
    getline(cin, _temp);

    if (_temp == "")
        return;

    if (_temp == "Y" || _temp == "y")
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
        selectedMod = Mod();
        halaman = '2';
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

void MenuMod(char &halaman, string &pilihan_menu, Game selectedGame, Mod &selectedMod)
{
    string _temp = "";
    Mod modListMenu[MAX_DATA];
    int modListMenuCount = 0;

    selectedMod = Mod();

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
        modListMenu[i] = Mod();

    // Menampilkan Menu Mod
    if (selectedGame.nama != "")
        cout << "Mod " << selectedGame.nama << endl;
    else
        cout << "Semua Mod" << endl;
    Border("─", 106);
    cout << "C > Upload Mod" << endl;
    Border("─", 106);
    if (modListMenuCount > 0)
    {
        // Daftar Mod
        cout << left << setw(6) << "No."
             << setw(40) << "Nama Mod"
             << setw(40) << "Game"
             << setw(20) << "Creator"
             << endl;
        Border("─", 106);

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
    Border("─", 106);
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
        halaman = '4';
        return;
    }

    // List Pilihan
    if (_temp == "C" || _temp == "c")
    {
        // Upload Mod
        UploadMod();
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
}

void DetailMod(char &halaman, Mod &selectedMod)
{
    string _temp = "";

    if (selectedMod.id < 1)
    {
        halaman = '2';
        return;
    }

    // Menampilkan detail mod terpilih
    cout << selectedMod.nama << endl;
    Border("─", 106);
    if (currentUser.id == selectedMod.uploader.id)
    {
        cout << "U > Edit | D > Hapus" << endl;
        Border("─", 106);
    }
    else if (currentUser.level == "admin")
    {
        cout << "D > Hapus" << endl;
        Border("─", 106);
    }
    cout << "Creator\t\t: " << selectedMod.creator << endl;
    cout << "Uploader\t: " << selectedMod.uploader.username << endl;
    cout << "Game\t\t: " << selectedMod.game.nama << endl;
    Border("─", 106);
    cout << selectedMod.deskripsi << endl;
    Border("─", 106);
    cout << "Q > Keluar | B > Kembali | L > Logout" << endl;
    cout << endl;
    cout << "Pilih Menu\t: ";
    getline(cin, _temp);
    Border("─", 106);

    if (currentUser.id == selectedMod.uploader.id && (_temp == "U" || _temp == "u"))
    {
        // Edit Mod terpilih
        EditMod(selectedMod);
    }
    else if ((currentUser.id == selectedMod.uploader.id || currentUser.level == "admin") && (_temp == "D" || _temp == "d"))
    {
        // Hapus Mod terpilih
        HapusMod(halaman, selectedMod);
    }
    else if ((_temp != "Q" && _temp != "q") && (_temp != "B" && _temp != "b") && (_temp != "L" && _temp != "l"))
    {
        cout << "Menu tidak ditemukan!";
        getline(cin, _temp);
    }
}

int main()
{
    // Temp
    string _temp = "";
    
    // Data Login
    int batasPercobaan = 3;
    int percobaanGagal = 0;

    // Data Menu
    char halaman = '0';
    string pilihan_menu = "";

    string selectedGenres[SMOL_DATA];
    int selectedGenreCount = 0;

    Game selectedGame;
    Mod selectedMod;

    while (pilihan_menu != "Q" && pilihan_menu != "q")
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
            MenuSistemLogin(userCount, percobaanGagal);
        }
        else
        {
            // Setup sistem riwayat halaman
            if (riwayatHalamanCount < 1)
            {
                dataArray[0].riwayatHalaman = '0';
                riwayatHalamanCount = 1;
            }
            else if (dataArray[riwayatHalamanCount - 1].riwayatHalaman != halaman)
            {
                dataArray[riwayatHalamanCount].riwayatHalaman = halaman;
                riwayatHalamanCount++;
            }

            // Menu Setelah Login
            switch (halaman)
            {
            case '0':
                // Menu Utama
                MenuUtama(halaman, pilihan_menu);
                break;
            case '1':
                // Menu Game
                MenuGame(halaman, pilihan_menu, selectedGame, selectedGenres, selectedGenreCount);
                break;
            case '2':
                // Menu Mod
                MenuMod(halaman, pilihan_menu, selectedGame, selectedMod);
                break;
            case '3':
                // Filter Game
                MenuFilterGame(halaman, pilihan_menu, selectedGenres, selectedGenreCount);
                break;
            case '4':
                // Detail Mod
                DetailMod(halaman, selectedMod);
                break;
            default:
                halaman = '0';
                break;
            }

            if (pilihan_menu == "Q" || pilihan_menu == "q")
            {
                // Keluar dari program
                currentUser = User();
            }
            else if (pilihan_menu == "B" || pilihan_menu == "b" && riwayatHalamanCount > 1)
            {
                // Kembali ke halaman sebelumnya
                riwayatHalamanCount--;
                halaman = dataArray[riwayatHalamanCount - 1].riwayatHalaman;
            }
            else if (pilihan_menu == "L" || pilihan_menu == "l")
            {
                // Logout
                currentUser = User();
                percobaanGagal = 0;
                riwayatHalamanCount = 0;
                halaman = '0';
            }
        }

        cout << "==========================================================================================================" << endl;
    }

    cout << endl;
    cout << "Program dihentikan...!" << endl;

    return 0;
}