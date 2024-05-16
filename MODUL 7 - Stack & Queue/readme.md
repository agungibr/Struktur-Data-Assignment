# <h1 align="center">Laporan Praktikum Modul Stack & Queue</h1>
<p align="center">Agung Malik Ibrahim</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### Stack
Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting. Sebuah tumpukan piring di kafetaria adalah contoh bagus dari tumpukan. Piring ditambahkan ke tumpukan saat mereka dibersihkan dan ditempatkan di bagian atas. Ketika sebuah piring dibutuhkan, diambil dari bagian atas tumpukan. Piring pertama yang ditempatkan di tumpukan adalah yang terakhir digunakan. 

Definisi: Sebuah tumpukan adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut atas. Elemen terakhir yang dimasukkan adalah yang pertama dihapus. Oleh karena itu, disebut daftar Last in First out (LIFO). Operasi pada stack melibatkan beberapa fungsi dasar yang dapat dilakukan pada struktur data ini. Berikut adalah beberapa operasi umum pada stack:
- Push (Masukkan): Menambahkan elemen ke dalam tumpukan pada posisi paling atas atau ujung.
- Pop (Keluarkan): Menghapus elemen dari posisi paling atas atau ujung tumpukan.
- Top (Atas): Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.
- IsEmpty (Kosong): Memeriksa apakah tumpukan kosong atau tidak.
- IsFull (Penuh): Memeriksa apakah tumpukan penuh atau tidak (terutama pada implementasi tumpukan dengan kapasitas terbatas).
- Size (Ukuran): Mengembalikan jumlah elemen yang ada dalam tumpukan.
- Peek (Lihat): Melihat nilai atau elemen pada posisi tertentu dalam tumpukan tanpa menghapusnya.
- Clear (Hapus Semua): Mengosongkan atau menghapus semua elemen dari tumpukan.
- Search (Cari): Mencari keberadaan elemen tertentu dalam tumpukan.

### Queue
Queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). Data yang pertama dimasukkan ke dalam queue akan menjadi data yang pertama pula untuk dikeluarkan dari queue. Queue mirip dengan konsep antrian pada kehidupan sehari-hari, dimana konsumen yang datang lebih dulu akan dilayani terlebih dahulu. Implementasi queue dapat dilakukan dengan menggunakan array atau linked list. Struktur data queue terdiri dari dua pointer yaitu front dan rear. Front/head adalah pointer ke elemen pertama dalam queue dan rear/tail/back adalah pointer ke elemen terakhir dalam queue.

Perbedaan antara stack dan queue terdapat pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan dan penghapusan elemen dilakukan di satu ujung. Elemen yang terakhir diinputkan akan berada paling dengan dengan ujung atau dianggap paling atas sehingga pada operasi penghapusan, elemen teratas tersebut akan dihapus paling awal, sifat demikian dikenal dengan LIFO. Pada Queue, operasi tersebut dilakukan ditempat berbeda (melalui salah satu ujung) karena perubahan data selalu mengacu pada Head, maka hanya ada 1 jenis insert maupun delete. Prosedur ini sering disebut Enqueue dan Dequeue pada kasus Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.

Operasi pada Queue:
- enqueue() : menambahkan data ke dalam queue.
- dequeue() : mengeluarkan data dari queue.
- peek() : mengambil data dari queue tanpa menghapusnya.
- isEmpty() : mengecek apakah queue kosong atau tidak.
- isFull() : mengecek apakah queue penuh atau tidak.
- size() : menghitung jumlah elemen dalam queue.

## Guided 

### 1. Guided 1

```C++
#include <iostream>
using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArraybuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```
Code di atas merupakan program C++ yang menunjukkan implementasi dari struktur data stack menggunakan array.  Program ini dimulai dengan mendeklarasikan array `arrayBuku` berukuran 5 yang digunakan sebagai stack, serta variabel `maksimal` yang menentukan kapasitas maksimum stack dan `top` yang menyimpan indeks elemen teratas dalam stack.

Fungsi `isFull` dan `isEmpty` digunakan untuk mengecek apakah stack penuh atau kosong. Fungsi `pushArrayBuku` menambahkan elemen ke stack jika tidak penuh, dan `popArrayBuku` menghapus elemen teratas dari stack jika tidak kosong. Fungsi `peekArrayBuku` menampilkan elemen pada posisi tertentu dari atas stack, sementara `countStack` mengembalikan jumlah elemen dalam stack. Fungsi `changeArrayBuku` mengubah elemen pada posisi tertentu dalam stack jika posisi tersebut valid, dan `destroyArraybuku` menghapus semua elemen dalam stack dan mengatur `top` kembali ke 0. Fungsi `cetakArrayBuku` mencetak semua elemen dalam stack dari atas ke bawah.

Dalam fungsi `main`, beberapa operasi stack dilakukan, seperti menambahkan lima elemen ke stack menggunakan `pushArrayBuku`, mencetak isi stack dengan `cetakArrayBuku`, mengecek apakah stack penuh atau kosong dengan `isFull` dan `isEmpty`, melihat elemen pada posisi ke-2 dari atas dengan `peekArrayBuku`, menghapus elemen teratas dengan `popArrayBuku`, menampilkan jumlah elemen dalam stack dengan `countStack`, mengubah elemen pada posisi ke-2 dari atas dengan `changeArrayBuku`, mencetak ulang isi stack, menghapus semua elemen dalam stack dengan `destroyArraybuku`, mencetak jumlah data setelah dihapus, dan mencetak ulang isi stack. Dengan demikian, program ini memperlihatkan bagaimana mengelola stack dengan berbagai operasi yang sering digunakan dalam struktur data ini, serta memastikan integritas stack melalui pengecekan kondisi penuh atau kosong sebelum menambah atau menghapus elemen.

### 2. Guided 2

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[5]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antrian kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Jika antrian kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Jika antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Code di atas adalah program C++ yang mengimplementasikan struktur data queue menggunakan array. Program dimulai dengan mendeklarasikan array `queueTeller` dengan kapasitas maksimum 5 elemen. Variabel `front` dan `back` digunakan untuk melacak posisi elemen depan dan belakang dalam queue. Fungsi `isFull` memeriksa apakah queue penuh dengan membandingkan nilai `back` dengan kapasitas maksimum queue, sementara fungsi `isEmpty` memeriksa apakah queue kosong dengan memeriksa apakah `back` bernilai 0.

Fungsi `enqueueAntrian` menambahkan elemen baru ke dalam queue. Jika queue penuh, akan menampilkan pesan "Antrian penuh". Jika queue kosong, elemen pertama akan ditempatkan pada posisi awal. Jika queue sudah memiliki elemen, elemen baru ditambahkan ke posisi back. Fungsi `dequeueAntrian` menghapus elemen depan dari queue dan menggeser elemen-elemen yang tersisa ke depan. Jika queue kosong, akan menampilkan pesan "Antrian kosong". Fungsi `countQueue` mengembalikan jumlah elemen dalam queue dengan mengembalikan nilai back. Fungsi `clearQueue` menghapus semua elemen dalam queue dengan mengosongkan setiap elemen dan mengatur ulang nilai front dan back ke 0. Fungsi `viewQueue` menampilkan isi queue, menunjukkan elemen yang ada dan menandai posisi yang kosong.

Dalam fungsi `main`, beberapa operasi dilakukan untuk menguji fungsi-fungsi yang telah didefinisikan. Program menambahkan dua elemen ke queue menggunakan `enqueueAntrian`, kemudian menampilkan isi queue dengan `viewQueue`. Setelah itu, program menghapus satu elemen dari queue dengan `dequeueAntrian` dan kembali menampilkan isi queue. Program juga menghapus semua elemen dari queue dengan `clearQueue` dan menampilkan isi queue setelah penghapusan.

## Unguided 

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <stack>

using namespace std;

bool palindrome(string kalimat) {
  for (int i = 0; i < kalimat.length(); i++) { //konversi kalimat ke uppercase
    kalimat[i] = tolower(kalimat[i]);
  }

  stack<char> s; //stack buat nyimpen character

  for (int i = 0; i < kalimat.length(); i++) { //push kalimat ke stack
    s.push(kalimat[i]);
  }

  for (int i = 0; i < kalimat.length() / 2; i++) { //membandingkan kalimat
    if (kalimat[i] != s.top()) {
      return false;
    }
    s.pop();
  }
  return true;
}

int main() { //main program
  string kalimat;

  do {
    cout << "\nMasukkan kalimat: "; //input kalimat
    getline(cin, kalimat);

    if (palindrome(kalimat)) { //memeriksa
      cout << "Kalimat " << kalimat << " merupakan palindrom" << endl;
    } else {
      cout << "Kalimat " << kalimat << " bukan palindrom" << endl;
    }
  } while (kalimat != "0");

  return 0;
}
```
#### Output:
![unguided1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/9a2df66e-2d5f-4d21-b20a-50a259268e5d)

Code di atas adalah program C++ yang memeriksa apakah sebuah kalimat merupakan palindrom menggunakan struktur data stack. Program ini dimulai dengan mendefinisikan fungsi `palindrome` yang menerima sebuah string `kalimat` sebagai argumen. Di dalam fungsi ini, kalimat terlebih dahulu diubah menjadi huruf kecil menggunakan fungsi `tolower` agar pemeriksaan palindrom tidak bersifat case-sensitive. Kemudian, sebuah stack `s` dideklarasikan untuk menyimpan karakter-karakter dalam kalimat. Setiap karakter dalam kalimat di-push ke dalam stack. Setelah seluruh karakter masuk ke dalam stack, fungsi ini memulai pemeriksaan dengan membandingkan karakter awal kalimat dengan karakter yang di-pop dari stack. Karena stack bekerja dengan prinsip Last-In-First-Out (LIFO), karakter yang di-pop adalah karakter terakhir yang dimasukkan, yang seharusnya cocok dengan karakter awal jika kalimat tersebut adalah palindrom.

Jika ditemukan ketidaksesuaian antara karakter awal dan karakter yang di-pop, fungsi langsung mengembalikan nilai `false`, menandakan bahwa kalimat bukan palindrom. Jika semua karakter sesuai, fungsi mengembalikan `true`. Fungsi `main` bertanggung jawab untuk menerima input dari pengguna dalam bentuk kalimat. Program terus meminta input hingga pengguna memasukkan "0". Setiap kalimat yang dimasukkan diperiksa menggunakan fungsi `palindrome`. Jika kalimat tersebut adalah palindrom, program mencetak pesan bahwa kalimat tersebut adalah palindrom. Jika tidak, program mencetak pesan sebaliknya. Program berakhir ketika pengguna memasukkan "0", yang menandakan penghentian loop input.

#### Full code Screenshot:
![fullcode1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/7fdf4237-578f-4a7d-ac5c-a15a0693be1b)

### 2. Ubah guided queue diatas agar menjadi program inputan user dan program menu

```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda depan antrian
int back = 0; // Penanda belakang antrian
string queueTeller[maksimalQueue]; // Array untuk menyimpan antrian

bool isFull() { // Pengecekan antrian penuh atau tidak
    return back == maksimalQueue;
}

bool isEmpty() { // Antrian kosong atau tidak
    return back == 0;
}

void enqueueAntrian(string data) { // Menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        queueTeller[back++] = data;
    }
}

void dequeueAntrian() { // Mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        queueTeller[--back] = ""; // Clear last element
    }
}

int countQueue() { // Menghitung jumlah antrian
    return back;
}

void clearQueue() { // Menghapus semua antrian
    for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
    }
    back = 0;
}

void viewQueue() { // Melihat isi antrian
    cout << "Data antrian:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

void displayMenu() { //menu
    cout << "\n=== MENU ===" << endl;
    cout << "1. Tambah antrian" << endl;
    cout << "2. Hapus antrian" << endl;
    cout << "3. Lihat antrian" << endl;
    cout << "4. Hapus semua antrian" << endl;
    cout << "5. Jumlah antrian" << endl;
    cout << "0. Keluar" << endl;
    cout << "Pilih menu: ";
}

int main() { //program utama
    int pilihan;
    string nama;

    do { //looping untuk menu
        displayMenu();
        cin >> pilihan;
        cin.ignore(); 
        switch (pilihan) {
            case 1:
                cout << "Masukkan nama: ";
                getline(cin, nama);
                enqueueAntrian(nama);
                break;
            case 2:
                dequeueAntrian();
                break;
            case 3:
                viewQueue();
                break;
            case 4:
                clearQueue();
                break;
            case 5:
                cout << "Jumlah antrian = " << countQueue() << endl;
                break;
            case 0:
                cout << "Keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
```
#### Output:
- Menambahkan antrian
![tampil](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/bf91bc30-9548-44c0-b7d8-3971517ab16b)

- Menghapus antrian
![hapus](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/f9351933-49a3-4ebe-abb8-e52f70384b6b)

- Menghapus seluruh antrian
![hapus all](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/7c10952f-7eef-4924-b052-4a9ee5dc0d23)

- Menampilkan jumlah antrian
![jumlah ](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a0d43d4a-a2b3-4cd5-891e-68d30fcbc274)

Kode di atas adalah program C++ yang mengimplementasikan antrian (queue) menggunakan array dengan kapasitas maksimum lima elemen. Program ini menyediakan beberapa fungsi untuk mengelola antrian, termasuk menambahkan elemen ke antrian (`enqueueAntrian`), menghapus elemen dari antrian (`dequeueAntrian`), menghitung jumlah elemen dalam antrian (`countQueue`), menghapus semua elemen dari antrian (`clearQueue`), dan melihat isi antrian (`viewQueue`).

Fungsi `isFull` memeriksa apakah antrian penuh dengan membandingkan nilai `back` dengan kapasitas maksimum, sementara `isEmpty` memeriksa apakah antrian kosong dengan melihat apakah `back` bernilai nol. Fungsi `enqueueAntrian` menambahkan elemen baru ke antrian jika antrian tidak penuh, dan fungsi `dequeueAntrian` menghapus elemen depan dari antrian dengan menggeser elemen-elemen yang tersisa ke depan. Program juga mencakup fungsi `viewQueue` untuk menampilkan semua elemen dalam antrian, menunjukkan elemen yang ada dan menandai posisi yang kosong.

Dalam fungsi `main`, program menyediakan menu interaktif yang memungkinkan pengguna untuk memilih berbagai operasi pada antrian. Menu ini ditampilkan dalam loop yang terus berjalan hingga pengguna memilih untuk keluar (dengan memilih opsi 0). Pengguna dapat menambah antrian, menghapus antrian, melihat isi antrian, menghapus semua antrian, atau melihat jumlah elemen dalam antrian.

#### Full code Screenshot:
![fullcode2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/82b211af-7a5a-4d9b-9ec1-fb7ec7195463)

## Kesimpulan
Pada guided kita belajar mengenai stack dan queue. Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists). Dalam tumpukan, urutan kedatangan data penting, sedangkan queue adalah struktur data yang digunakan untuk menyimpan data dengan metode FIFO (First-In First-Out). Data yang pertama dimasukkan ke dalam queue akan menjadi data yang pertama pula untuk dikeluarkan dari queue. 
Perbedaan antara stack dan queue terdapat pada aturan penambahan dan penghapusan elemen. Pada stack, operasi penambahan dan penghapusan elemen dilakukan di satu ujung. Elemen yang terakhir diinputkan akan berada paling dengan dengan ujung atau dianggap paling atas sehingga pada operasi penghapusan, elemen teratas tersebut akan dihapus paling awal, sifat demikian dikenal dengan LIFO. Pada Queue, operasi tersebut dilakukan ditempat berbeda (melalui salah satu ujung) karena perubahan data selalu mengacu pada Head, maka hanya ada 1 jenis insert maupun delete. Prosedur ini sering disebut Enqueue dan Dequeue pada kasus Queue. Untuk Enqueue, cukup tambahkan elemen setelah elemen terakhir Queue, dan untuk Dequeue, cukup "geser"kan Head menjadi elemen selanjutnya.

Lalu pada unguided kita belajar mengenai membuat program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak dan mengubah guided queue agar menjadi program inputan user dan program menu.

## Referensi
[1] Karumanchi, N. (2016). Data Structures and algorithms made easy: Concepts, problems, Interview Questions. CareerMonk Publications.

[2] Stroustrup, B., A Tour of C++ Third Edition. United States: Pearson Education, Inc., 2023.

[3] Quinn, R., Advanced C++ Programming Cookbook. United Kingdoms: Packt Publishing Ltd., 2020.