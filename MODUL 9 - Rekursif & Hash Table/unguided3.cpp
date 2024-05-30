#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

struct mahasiswa
{
    string nama;
    long long NIM;
    int nilai;
    mahasiswa *next;

    mahasiswa(string nama, long long NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai), next(nullptr) {}
};

class DataMahasiswa
{
private:
    mahasiswa **table;

    int hash_func(long long key)
    {
        return key % MAX_SIZE;
    }

public:
    DataMahasiswa()
    {
        table = new mahasiswa *[MAX_SIZE]();
    }

    ~DataMahasiswa()
    {
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i];
            while (current != nullptr)
            {
                mahasiswa *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void tambah(string nama, long long NIM, int nilai)
    {
        int index = hash_func(NIM);
        mahasiswa *baru = new mahasiswa(nama, NIM, nilai);
        baru->next = table[index];
        table[index] = baru;
    }

    void hapus(long long NIM)
    {
        int index = hash_func(NIM);
        mahasiswa *current = table[index];
        mahasiswa *prev = nullptr;
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    mahasiswa *cari_NIM(long long NIM)
    {
        long long index = hash_func(NIM);
        mahasiswa *current = table[index];
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void cari_nilai(int awal, int akhir)
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i];
            while (current != nullptr)
            {
                if (current->nilai >= awal && current->nilai <= akhir)
                {
                    cout << "| " << setw(19) << left << current->nama
                         << "| " << setw(17) << current->NIM
                         << "| " << setw(15) << current->nilai << " |" << endl;
                }
                current = current->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    void tampilkan_semua()
    {
        cout << "-----------------------------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i];
            while (current != nullptr)
            {
                cout << "| " << setw(19) << left << current->nama
                     << "| " << setw(17) << current->NIM
                     << "| " << setw(15) << current->nilai << " |" << endl;
                current = current->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};

int main()
{
    DataMahasiswa dm;

    int pilih, nilai, awal, akhir;
    string nama;
    long long NIM;

    do
    {
        cout << "\nData Mahasiswa:" << endl;
        cout << "\n1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Cari berdasarkan NIM" << endl;
        cout << "4. Cari berdasarkan Rentang Nilai" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            cout << "Masukan nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukan NIM : ";
            cin >> NIM;
            cout << "Masukan nilai : ";
            cin >> nilai;
            dm.tambah(nama, NIM, nilai);
            cout<<"Data berhasil ditambahkan"<<endl;
            break;
        case 2:
            cout << "Masukan NIM yang ingin dihapus : ";
            cin >> NIM;
            dm.hapus(NIM);
            break;
        case 3:
            cout << "Masukan NIM yang ingin dicari : ";
            cin >> NIM;
            {
                mahasiswa *mahasiswa_ptr = dm.cari_NIM(NIM);
                if (mahasiswa_ptr)
                {
                    cout << "Mahasiswa dengan NIM " << NIM << " bernama " << mahasiswa_ptr->nama << " yang memiliki nilai " << mahasiswa_ptr->nilai << endl;
                }
                else
                {
                    cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
                }
            }
            break;
        case 4:
            cout << "Masukan rentang nilai awal : ";
            cin >> awal;
            cout << "Masukan rentang nilai akhir : ";
            cin >> akhir;
            dm.cari_nilai(awal, akhir);
            break;
        case 5:
            dm.tampilkan_semua();
            break;
        case 0:
            break;
        default:
            cout << "Pilihan invalid!" << endl;
        }
    } while (pilih != 0);

    return 0;
}
