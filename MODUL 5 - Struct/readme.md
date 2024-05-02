# <h1 align="center">Laporan Praktikum Modul Struct</h1>
<p align="center">Agung Malik Ibrahim</p>

## Dasar Teori

Struct adalah tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Berbeda dengan array hanya berupa kumpulan variabel yang bertipe data sama, struct bisa memiliki variabel-variabel yang bertipe data sama atau berbeda, bahkan bisa menyimpan variabel yang bertipe data array atau struct itu sendiri. Variabel-variabel yang menjadi anggota struct disebut dengan elemen struct[1].

Penggunaan/pemakaian tipe data struct dilakukan dengan membuat suatu variabel yang bertipe data struct tersebut. Pengaksesan elemen struct dilakukan secara individual dengan menyebutkan nama variabel struct diikuti dengan operator titik (.). Terdapat banyak format penulisan struct diantaranya :

### 1.
```
struct { 
    string namaDepan; 
    string namaBelakang;
    int usia;
    char jenis_kelamin;
}namaVariabelStrukA, namaVariabelStrukB 
```

### 2. 
```
struct namaTipe{
    string namaDepan;
    string namaTengah;
    string namaBelakang;
}; struct namaTipe namaVariabelStrukA, namaVariabelStrukB;
```

### 3. 
```
typedef struct {
    string namaDepan;
    string namaTengah;
    string namaBelakang;
}namaTipe;
namaTipe namaVariabelStrukA, namaVariabelStrukB
```

## Guided 

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>
#include <string>

using namespace std;

struct buku { 
    string judul_buku;
    string pengarang;
    string penerbit; 
    int tebal_halaman;
    int harga_buku; 

};

int main() {
    struct buku book, book2; 

    book.judul_buku = "The Great Gatsby"; 
    book.pengarang = "F. Scott Fitzgerald";
    book.penerbit = "Charles Scribner's Sons";
    book.tebal_halaman = 180;
    book.harga_buku = 250000;

    book2.judul_buku = "Death Comes for the Archbishop"; 
    book2.pengarang = "Willa Cather";
    book2.penerbit = "Alfred A. Knopf";
    book2.tebal_halaman = 297;
    book2.harga_buku = 300000;

    cout << "=====STRUCT I=====" << endl;
    cout << "Judul Buku: " << book.judul_buku << endl;
    cout << "Pengarang: " << book.pengarang << endl;
    cout << "Penerbit: " << book.penerbit << endl;
    cout << "Tebal Halaman: " << book.tebal_halaman << endl;
    cout << "Harga Buku: " << book.harga_buku << endl;

    cout << "\n=====STRUCT II=====" << endl;
    cout << "Judul Buku: " << book2.judul_buku << endl;
    cout << "Pengarang: " << book2.pengarang << endl;
    cout << "Penerbit: " << book2.penerbit << endl;
    cout << "Tebal Halaman: " << book2.tebal_halaman << endl;
    cout << "Harga Buku: " << book2.harga_buku << endl;

}
```
Kode di atas digunakan untuk mencetak struct `buku`. Pertama kita membuat dahulu struct `buku` yang berisi `judul_buku`, `pengarang`, `penerbit`, `tebal_halaman`, dan `harga_buku`. Lalu pada main program kita panggil struct `buku` tersebut lalu isikan dengan variabel yang sesuai. Lalu setelah diisi kita bisa menampilkan struct `buku` yang telah kita buat dan isikan.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.
![nomer2](https://github.com/dwisulis25/Struktur-Data-Assignment/assets/162300904/a5249cd7-e906-431d-b972-d97c1fc3a2fb)

```C++
#include <iostream>
#include <string>

using namespace std;

struct hewan { 
    string nama_hewan;
    string jenis_kelamin;
    string cara_berkembangbiak;
    string alat_pernapasan;
    string tempat_hidup;
    bool apakah_karnivora;   
};
hewan info_hewan;

struct hewan_darat { 
    int jumlah_kaki;
    bool apakah_menyusui; 
    string suara;
    hewan info_hewan;
};
hewan_darat hewan1;

struct hewan_laut {
    string bentuk_sirip;
    string bentuk_pertahanan;
    hewan info_hewan;
};
hewan_laut hewan2;

int main () {
    //struct hewan1, hewan2;

    hewan1.info_hewan.nama_hewan = "Kambing";
    hewan1.info_hewan.jenis_kelamin = "Jantan";
    hewan1.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan1.info_hewan.alat_pernapasan = "Paru-paru";
    hewan1.info_hewan.tempat_hidup = "Darat";
    hewan1.info_hewan.apakah_karnivora = false;
    hewan1.jumlah_kaki = 4;
    hewan1.apakah_menyusui = true;
    hewan1.suara = "play";

    hewan2.info_hewan.nama_hewan = "Paus";
    hewan2.info_hewan.jenis_kelamin = "Betina";
    hewan2.info_hewan.cara_berkembangbiak = "Melahirkan";
    hewan2.info_hewan.alat_pernapasan = "Paru-paru";
    hewan2.info_hewan.tempat_hidup = "laut";
    hewan2.info_hewan.apakah_karnivora = false;
    hewan2.bentuk_sirip = "segitiga";
    hewan2.bentuk_pertahanan = "melawan";

    cout << "=====HEWAN DARAT=====" << endl;
    cout << "Nama Hewan :" << hewan1.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin :" << hewan1.info_hewan.jenis_kelamin << endl;
    cout << "Cara Berkembangbiak :" << hewan1.info_hewan.cara_berkembangbiak << endl;
    cout << "ALat Pernapasan :" << hewan1.info_hewan.alat_pernapasan << endl;
    cout << "Tempat Hidup :" << hewan1.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora :" << hewan1.info_hewan.apakah_karnivora << endl;
    cout << "Jumlah Kaki :" << hewan1.jumlah_kaki << endl;
    cout << "Apakah Menyusui :" << hewan1.apakah_menyusui << endl;
    cout << "Suara :" << hewan1.suara << endl;

    cout << "\n=====HEWAN LAUT=====" << endl;
    cout << "Nama Hewan :" << hewan2.info_hewan.nama_hewan << endl;
    cout << "Jenis Kelamin :" << hewan2.info_hewan.jenis_kelamin << endl;
    cout << "Cara Berkembangbiak :" << hewan2.info_hewan.cara_berkembangbiak << endl;
    cout << "ALat Pernapasan :" << hewan2.info_hewan.alat_pernapasan << endl;
    cout << "Tempat Hidup :" << hewan2.info_hewan.tempat_hidup << endl;
    cout << "Apakah Karnivora :" << hewan2.info_hewan.apakah_karnivora << endl;
    cout << "Bentuk Sirip :" << hewan2.bentuk_sirip << endl;
    cout << "Bentuk Pertahanan :" << hewan2.bentuk_pertahanan << endl;
}
```
Kode di atas digunakan untuk mencetak struct `hewan`. Pertama kita buat dahulu struct `hewan` yang berisikan `nama_hewan`, `jenis_kelamin`, `cara_berkembangbiak`, `alat_pernapasan`, `tempat_hidup`, dan `apakah_karnivora`. Lalu kita membuat struct `hewan_darat` yang berisikan variable dari struct `hewan` dan ada `jumlah_kaki`, `apakah_menyusui`, dan `suara`. Kemudian kita membuat struct `hewan_laut` yang berisikan variable dari struct `hewan` dan ditambah `bentuk_sirip` dan `bentuk_pertahanan_diri`. Setelah selesai membuat struct kita bisa memanggil ketiga struct tersebut dan mengisikan data sesuai dengan variable. Setelah itu, kita bisa menampilkan hasil struct yang sudah kita isikan.

## Unguided 

### 1. Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan

```C++
#include <iostream> //input preprocessor directive
#include <string>

using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

struct buku { //buat struct buku
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() { //main program
    const int ukuran = 5; //ukuran 5 
    struct buku books[ukuran]; //memanggil struct

    for (int i = 0; i < ukuran; i++) { //looping untuk input buku
        cout << "\n===== Buku " << i + 1 << " =====" << endl;

        cout << "Masukkan informasi buku:" << endl;
        cout << "Judul Buku: ";
        getline(cin, books[i].judul_buku);

        cout << "Pengarang: ";
        getline(cin, books[i].pengarang);

        cout << "Penerbit: ";
        getline(cin, books[i].penerbit);

        cout << "Tebal Halaman: ";
        cin >> books[i].tebal_halaman;

        cout << "Harga Buku: ";
        cin >> books[i].harga_buku;

        cin.ignore(); 
    }

    cout << "\n\n===== Daftar Buku =====\n" << endl; 
    for (int i = 0; i < ukuran; i++) { //looping untuk menampilkan buku
        cout << "Buku " << i + 1 << ":" << endl;
        cout << "Judul Buku: " << books[i].judul_buku << endl;
        cout << "Pengarang: " << books[i].pengarang << endl;
        cout << "Penerbit: " << books[i].penerbit << endl;
        cout << "Tebal Halaman: " << books[i].tebal_halaman << endl;
        cout << "Harga Buku: " << books[i].harga_buku << endl;
        cout << endl;
    }

    return 0;
}
```
#### Output:
![1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/ce61cb5e-42f9-4a4b-b270-b3494e7287cd)
![2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/c1a85555-bdd1-4a5f-88eb-50a8edb7128e)

Kode di atas digunakan untuk mencetak teks struct `buku`. Pertama kita membuat dahulu struct `buku` yang berisi `judul_buku`, `pengarang`, `penerbit`, `tebal_halaman`, dan `harga_buku`. Lalu pada main program kita membuat variable `ukuran` yang bertipe data `const` supaya tidak bisa diubah nilainya. Lalu kita membuat looping yang berguna untuk menginputkan informasi buku sehingga kita tidak perlu mengcopy struct sampai 5 kali. Lalu setelah membuat looping untuk menginputkan kita perlu membuat looping untuk menampilkan setiap daftar buku yang sudah kita inputkan.

#### Full code Screenshot:
![fullcode1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/66e53760-640e-49d2-b566-b308b2ede25b)

### 2. Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I, berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?

```C++
#include <iostream> //input preprocessor directive
#include <string> 

using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

struct buku { //buat struct buku
    string judul_buku;
    string pengarang;
    string penerbit;
    int tebal_halaman;
    int harga_buku;
};

int main() { //main program
    struct buku books[5]; //dibuat aray ukuran 5

    for (int i = 0; i < 5; i++) { //looping untuk menginputkan buku
        cout << "\n===== Buku " << i + 1 << " =====" << endl;

        cout << "Masukkan informasi buku:" << endl;
        cout << "Judul Buku: ";
        getline(cin, books[i].judul_buku);

        cout << "Pengarang: ";
        getline(cin, books[i].pengarang);

        cout << "Penerbit: ";
        getline(cin, books[i].penerbit);

        cout << "Tebal Halaman: ";
        cin >> books[i].tebal_halaman;

        cout << "Harga Buku: ";
        cin >> books[i].harga_buku;

        cin.ignore(); 
    }

    cout << "\n\n===== Daftar Buku =====\n" << endl;
    for (int i = 0; i < 5; i++) { //looping untuk menampilkan buku
        cout << "Buku " << i + 1 << ":" << endl;
        cout << "Judul Buku: " << books[i].judul_buku << endl;
        cout << "Pengarang: " << books[i].pengarang << endl;
        cout << "Penerbit: " << books[i].penerbit << endl;
        cout << "Tebal Halaman: " << books[i].tebal_halaman << endl;
        cout << "Harga Buku: " << books[i].harga_buku << endl;
        cout << endl;
    }
    return 0;
}
```
#### Output:
![1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/ce61cb5e-42f9-4a4b-b270-b3494e7287cd)
![2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/c1a85555-bdd1-4a5f-88eb-50a8edb7128e)

Kode di atas digunakan untuk mencetak teks struct `buku`. Pertama kita membuat dahulu struct `buku` yang berisi `judul_buku`, `pengarang`, `penerbit`, `tebal_halaman`, dan `harga_buku`. Lalu pada main program kita menambahkan ukuran `[5]` pada variable memanggil struct supaya panjang struct menjadi 5 tanpa perlu membuat variable dan dibuat berjenis array. Lalu kita membuat looping yang berguna untuk menginputkan informasi buku sehingga kita tidak perlu mengcopy struct sampai 5 kali. Lalu setelah membuat looping untuk menginputkan kita perlu membuat looping untuk menampilkan setiap daftar buku yang sudah kita inputkan.

#### Full code Screenshot:
![fullcode2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/e549d765-038a-4697-ac82-f5bc29cef2d0)

## Kesimpulan
Kesimpulan pada guided kita belajar mengenai struct yang merupakan tipe data bentukan yang berisi kumpulan variabel-variabel yang bernaung dalam satu nama yang sama dan memiliki kaitan satu sama lain. Penggunaan/pemakaian tipe data struct dilakukan dengan membuat suatu variabel yang bertipe data struct tersebut. Pengaksesan elemen struct dilakukan secara individual dengan menyebutkan nama variabel struct diikuti dengan operator titik (.). Terdapat 3 contoh cara penggunaan struct diatas.

Lalu untuk unguided kita belajar mengenai memodifikasi kode pada guided, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan dan mengubah deklarasi variable struct menjadi berjenis array

## Referensi
[1]Hariyanto, Bambang, 2000, Struktur Data, Bandung.
