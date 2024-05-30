# <h1 align="center">Laporan Praktikum Modul Rekursif & Hashtable</h1>
<p align="center">Agung Malik Ibrahim</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### Rekursif
Rekursif merupakan salah satu proses pengulangan fungsi atau prosedur yang memanggil dirinya sendiri. Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Karena ada proses yang berulang-ulang maka harus ada suatu kondisi yang mengakhiri prosesnya. Jika tidak, maka proses tidak akan pernah berhenti sampai memori yang digunakan tidak dapat menampung lagi. Kode rekursif cenderung lebih singkat dan lebih mudah dibuat dibandingkan dengan kode iteratif. Biasanya, perulangan dapat diubah menjadi fungsi rekursif saat proses kompilasi atau interpretasi. Rekursi sangat efektif untuk menangani tugas yang dapat diuraikan menjadi sub tugas yang serupa. Sebagai contoh, masalah pengurutan, pencarian, dan penjelajahan sering kali dapat diselesaikan dengan solusi rekursif yang sederhana.

Terdapat dua jenis fungsi rekursi yaitu:
- Rekursi langsung : Dalam rekursi langsung, fungsi memanggil dirinya sendiri secara langsung.
- Rekursi tidak langsung : Jika sebuah fungsi memanggil dirinya sendiri secara tidak langsung dari fungsi lain.

### Hashtable
Hash Table adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Hash table biasanya terdiri dari dua komponen utama: array (atau vektor) dan fungsi hash. Hashing adalah teknik untuk mengubah rentang nilai kunci menjadi rentang indeks array. Array menyimpan data dalam slot-slot yang disebut bucket. Setiap bucket dapat menampung satu atau beberapa item data. Fungsi hash digunakan untuk menghasilkan nilai unik dari setiap item data, yang digunakan sebagai indeks array. Dengan cara ini, hash table memungkinkan pencarian data dalam waktu yang konstan (O(1)) dalam kasus terbaik. Sistem hash table bekerja dengan cara mengambil input kunci dan memetakkannya ke nilai indeks array menggunakan fungsi hash. Kemudian, data disimpan pada posisi indeks array yang dihasilkan oleh fungsi hash. Ketika data perlu dicari, input kunci dijadikan sebagai parameter untuk fungsi hash, dan posisi indeks array yang dihasilkan digunakan untuk mencari data. Dalam kasus hash collision, di mana dua atau lebih data memiliki nilai hash yang sama, hash table menyimpan data tersebut dalam slot yang sama dengan Teknik yang disebut chaining.

Fungsi hashtable untuk membuat pemetaan antara kunci dan nilai, hal ini dilakukan melalui penggunaan rumus matematika yang dikenal sebagai fungsi hash. Hasil dari fungsi hash disebut sebagai nilai hash atau hash. Nilai hash adalah representasi dari string karakter asli tetapi biasanya lebih kecil dari aslinya. Kemudian operasi hashtable yaitu :
- Insertion: Memasukkan data baru ke dalam hash table dengan memanggil fungsi hash untuk menentukan posisi bucket yang tepat, dan kemudian menambahkan data ke bucket tersebut.
- Deletion: Menghapus data dari hash table dengan mencari data menggunakan fungsi hash, dan kemudian menghapusnya dari bucket yang sesuai.
- Searching: Mencari data dalam hash table dengan memasukkan input kunci ke fungsi hash untuk menentukan posisi bucket, dan kemudian mencari data di dalam bucket yang sesuai.
- Update: Memperbarui data dalam hash table dengan mencari data menggunakan fungsi hash, dan kemudian memperbarui data yang ditemukan.
- Traversal: Melalui seluruh hash table untuk memproses semua data yang ada dalam tabel. 

## Guided 

### 1. Guided 1

```C++
#include <iostream>
using namespace std;

// Fungsi ini melakukan hitung mundur dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << " ";
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan inputnya
    cout << endl;
    return 0;
}
```
Kode di atas merupakan implementasi rekursif langsung. Program ini memiliki sebuah fungsi bernama `countdown`, yang bertugas untuk melakukan hitung mundur dari angka yang diinputkan. Saat fungsi `countdown` dipanggil dengan suatu nilai n, program akan mencetak nilai n tersebut, kemudian memanggil kembali fungsi `countdown` dengan nilai n - 1. Proses ini akan terus berlanjut hingga n mencapai nilai 0. Ketika n mencapai nilai 0, proses rekursi akan berhenti, dan program akan keluar dari fungsi `countdown`. Selanjutnya, program akan mencetak baris baru dan kembali ke fungsi `main`. Pada fungsi `main`, terdapat pemanggilan `countdown(5)`, yang menyebabkan program akan melakukan hitung mundur dari angka 5.

### 2. Guided 2

```C++
#include <iostream>
using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() {
    int num = 5;
    cout << "Rekursif Tidak Langsung: ";
    functionA(num);
    return 0;
}
```
Kode di atas adalah implementasi rekursif tidak langsung. Pada program ini, terdapat dua fungsi, yaitu `functionA` dan `functionB`, yang saling memanggil secara bergantian dengan panggilan rekursif tidak langsung. Fungsi `functionA` menerima sebuah parameter n, dan jika nilai n lebih besar dari 0, fungsi akan mencetak nilai n, kemudian memanggil fungsi `functionB` dengan parameter n - 1. Di sisi lain, fungsi `functionB` juga menerima parameter n, dan jika n lebih besar dari 0, fungsi akan mencetak nilai n, dan kemudian memanggil fungsi `functionA` dengan parameter n / 2. Dalam main, program memanggil fungsi `functionA` dengan parameter 5. Sehingga, secara berulang, fungsi-fungsi `functionA` dan `functionB` saling memanggil satu sama lain hingga kondisi berhenti dari rekursi terpenuhi.

### 3. Guided 3

```C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;
    employee_map.print();

    return 0;
}
```
Kode di atas digunakan mengimplementasikan hashtable. Dalam program ini, terdapat kelas `HashNode` yang mewakili simpul dalam tabel hash. Setiap simpul memiliki dua atribut: `name` untuk menyimpan nama dan `phone_number` untuk menyimpan nomor telepon. Kelas `HashMap` bertanggung jawab untuk mengelola tabel hash. Pada implementasi ini, digunakan pendekatan chaining dengan vektor untuk menangani tabrakan. Setiap elemen dalam array `table` adalah sebuah vektor yang menyimpan simpul-simpul dengan nilai hash yang sama. Metode `hashFunc` digunakan untuk menghasilkan nilai hash dari sebuah nama. Nilai hash dihitung dengan menjumlahkan kode ASCII dari setiap karakter dalam nama dan kemudian diambil modulus terhadap ukuran tabel hash untuk memastikan nilai hash berada dalam rentang yang valid.

Fungsi `insert` digunakan untuk menambahkan sebuah entri ke dalam tabel hash. Jika terjadi tabrakan (simpul dengan nilai hash yang sama), nilai baru akan ditambahkan ke dalam vektor yang sudah ada. Jika tidak ada tabrakan, simpul baru akan ditambahkan ke dalam vektor. Fungsi `remove` digunakan untuk menghapus sebuah entri dari tabel hash berdasarkan nama. Fungsi ini mencari simpul dengan nama yang sesuai dalam vektor yang memiliki nilai hash yang sama, lalu menghapusnya. Fungsi `searchByName` digunakan untuk mencari nomor telepon berdasarkan nama. Fungsi ini mencari simpul dengan nama yang sesuai dalam vektor yang memiliki nilai hash yang sama, lalu mengembalikan nomor teleponnya jika ditemukan. Fungsi `print` digunakan untuk mencetak seluruh isi tabel hash, termasuk vektor-vektor yang mungkin memiliki lebih dari satu simpul. Dalam `main`, terdapat contoh penggunaan dari kelas `HashMap`. Empat nama dan nomor telepon ditambahkan ke dalam tabel hash, kemudian dicari dan dihapus. Hasil akhir dari program adalah mencetak tabel hash yang telah dimodifikasi sesuai dengan operasi yang dilakukan.

## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>
using namespace std;

//menghitung faktorial
long int faktorial(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1; //faktorial dari 0 atau 1 adalah 1
    } else {
        return n * faktorial(n - 1); //n * faktorial(n-1)
    }
}

int main() {
    int n;
    long int hasil;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Bilangan yang anda masukan salah" << endl;
    } else {
        hasil = faktorial(n);
        cout << "Faktorial dari " << n << " adalah: " << hasil << endl;
    }

    return 0;
}
```
#### Output:
![unguided1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/d3d9e411-a524-48f7-8365-83f31a770ff9)

Kode di atas digunakan untuk menghitung nilai faktorial dari sebuah inputan bilangan bulat positif menggunakan rekursif langsung. Fungsi `faktorial` menerima sebuah bilangan bulat positif `n` sebagai argumen dan mengembalikan faktorial dari `n`. Jika `n` adalah 0 atau 1, fungsi mengembalikan 1 karena faktorial dari 0 atau 1 adalah 1. Untuk nilai `n` yang lebih besar, fungsi memanggil dirinya sendiri dengan `n` - 1 dan mengalikan hasilnya dengan `n`, sehingga menerapkan prinsip rekursi. Fungsi `main` bertanggung jawab untuk interaksi dengan pengguna. Program meminta pengguna untuk memasukkan sebuah bilangan bulat positif. Jika pengguna memasukkan bilangan negatif, program akan menampilkan pesan kesalahan. Jika bilangan yang dimasukkan adalah positif, program akan memanggil fungsi faktorial untuk menghitung faktorial dari bilangan tersebut dan menampilkan hasilnya.

#### Full code Screenshot:
![fullcode1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/f9b8188d-8d16-45f1-a83e-fa2b97edbc57)


### 2. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>
using namespace std;

// Deklarasi fungsi
long int faktorialA(unsigned int n);
long int faktorialB(unsigned int n);

// Fungsi faktorialA yang memanggil faktorialB
long int faktorialA(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1; //faktorial dari 0 atau 1 adalah 1
    } else {
        return n * faktorialB(n - 1); //n * faktorialB(n-1)
    }
}

// Fungsi faktorialB yang memanggil faktorialA
long int faktorialB(unsigned int n) {
    if (n == 0 || n == 1) {
        return 1; //faktorial dari 0 atau 1 adalah 1
    } else {
        return n * faktorialA(n - 1); //n * faktorialA(n-1)
    }
}

int main() {
    int n;
    long int hasil;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> n;

    if (n < 0) {
        cout << "Bilangan yang anda masukan salah" << endl;
    } else {
        hasil = faktorialA(n);
        cout << "Faktorial dari " << n << " adalah: " << hasil << endl;
    }

    return 0;
}
```
#### Output:
![unguided2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/aa38c116-b899-4506-8abf-46c7113a889e)

Kode di atas digunakan untuk menghitung nilai faktorial dari sebuah inputan bilangan bulat positif menggunakan rekursif tidak langsung. Fungsi `faktorialA` menerima sebuah bilangan bulat positif `n` sebagai argumen. Jika `n` adalah 0 atau 1, fungsi mengembalikan 1, karena faktorial dari 0 atau 1 adalah 1. Untuk nilai `n` yang lebih besar, fungsi memanggil `faktorialB` dengan `n - 1` dan mengalikan hasilnya dengan `n`. Fungsi `faktorialB` juga menerima sebuah bilangan bulat positif `n` sebagai argumen. Sama seperti `faktorialA`, jika `n` adalah 0 atau 1, fungsi mengembalikan 1. Untuk nilai `n` yang lebih besar, fungsi memanggil `faktorialA` dengan `n - 1` dan mengalikan hasilnya dengan `n`. Dalam fungsi `main`, program meminta pengguna untuk memasukkan sebuah bilangan bulat positif. Jika pengguna memasukkan bilangan negatif, program akan menampilkan pesan kesalahan. Jika bilangan yang dimasukkan adalah positif, program akan memanggil fungsi `faktorialA` untuk menghitung faktorial dari bilangan tersebut dan menampilkan hasilnya.

#### Full code Screenshot:
![fullcode2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/3981f855-a949-4471-b86d-1d7f47fa7a68)

### 3. Nomor 3
Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
- Setiap mahasiswa memiliki NIM dan nilai.
- Program memiliki tampilan pilihan menu berisi poin C.
- Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90)

```C++
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
```
#### Output:
- Tambah
![tambah](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/30dfa2cd-8c08-4493-ab14-cf67332aff0e)

- Hapus
![hapus](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/98f4bd68-4910-460f-ac36-c63c2f2782fe)

- Cari NIM
![cari NIM](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a1ed03ad-99dd-4668-81a4-7beee9abfae7)

- Cari Nilai
![cari nilai](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a6a11e49-ccd0-4f65-8aff-cbf158d6245d)

- Tampil
![tampil](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/12720c9c-b434-4d60-b1b8-8c84b5e6c8e2)


Kode di atas digunakan untuk mengimplementasikan hashtable untuk menyimpan data mahasiswa. Struktur `mahasiswa` menyimpan informasi tentang nama, NIM, nilai, dan pointer ke node berikutnya dalam bucket yang sama. Kelas `DataMahasiswa` berfungsi sebagai hash table yang menyimpan pointer-pointer ke elemen-elemen `mahasiswa`. Kelas ini memiliki beberapa metode: `tambah` untuk menambahkan data mahasiswa, `hapus` untuk menghapus data berdasarkan NIM, `cari_NIM` untuk mencari mahasiswa berdasarkan NIM, `cari_nilai` untuk mencari mahasiswa dalam rentang nilai tertentu, dan `tampilkan_semua` untuk menampilkan semua data yang tersimpan dalam hash table. Fungsi hash sederhana `hash_func` digunakan untuk menentukan indeks penyimpanan berdasarkan NIM. Fungsi `main` menyediakan menu interaktif untuk pengguna, memungkinkan mereka untuk menambah, menghapus, mencari, dan menampilkan data mahasiswa. Program terus berjalan hingga pengguna memilih opsi untuk keluar.

#### Full code Screenshot:
![fullcode3](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/fa1494e8-ed49-4baa-bcc2-0c6f26ed0000)

## Kesimpulan
Kesimpulan pada guided kita belajar mengenai rekursif dan hashtable. Rekursif merupakan salah satu proses pengulangan fungsi atau prosedur yang memanggil dirinya sendiri. Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Terdapat dua jenis fungsi rekursi yaitu rekursi langsung dan rekursi tidak langsung. Lalu hashtable adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Hash table biasanya terdiri dari dua komponen utama: array (atau vektor) dan fungsi hash. Hashing adalah teknik untuk mengubah rentang nilai kunci menjadi rentang indeks array.

Lalu untuk unguided kita belajar mengenai membuat program rekursif langsung dan tidak langsung serta mengimplementasikan hashtable untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.

## Referensi
[1] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.