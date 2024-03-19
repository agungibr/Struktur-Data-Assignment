# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Agung Malik Ibrahim</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. Tipe Data Primitif

```C++
#include <iostream>

using namespace std;

// Main program
int main() 
{
    char op;
    float num1, num2;

    //It allows user to enter operator i.e. +, -, *, /
    cout << "Enter a Operator: " << endl;
    cin >> op;

    //It allows user to enter the operations
    cout << "Enter Number 1 & 2: " << endl;
    cin >> num1 >> num2;

    //Switch statement begins
    switch (op)
    {
    //If user enter +
    case '+':
        cout << num1 + num2;
        break;

    //If user enter -
    case '-':
        cout << num1 - num2;
        break;

    //If user enter *
    case '*':
        cout << num1 * num2;
        break;

    //If user enter /
    case '/':
        cout << num1 / num2;
        break;

    //If the operatior is other that +, -, * or /,
    //error message will display
    default:
        cout << "Error! operator is not correct";
    }//switch statement ends
    return 0;
}
```
Kode diatas merupakan program untuk menampilkan aritmatika dasar (penjumlahan, pengurangan, perkalian, dan pembagian) untuk dua bilangan. Pada awal program user diminta untuk menginputkan operator yang akan dipilih untuk melakukan operasi aritmatika dasar. Setelah menginputkan operator, user diminta untuk menginputkan angka pertama dan angka kedua. Lalu program akan menjalankannya sesuai dengan inputan dari user. Program ini menggunakan `switch-case` untuk menjalankan operasinya. Kemudian jika user menginputkan tidak sesuai dengan operator yang sudah ditentukan, maka program akan menampilkan pesan error.

### 2. Tipe Data Abstrak

```C++
#include <iostream>
using namespace std;

//struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    //menggunakan struct
    struct Mahasiswa mhs1, mhs2;

    //mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    //mencetak isi struct
    cout << "-----Mahasiswa 1-----" << endl;
    cout << "Nama: " << mhs1.name <<endl;
    cout << "Alamat: " << mhs1.address <<endl;
    cout << "Umur: " << mhs1.age <<endl;
    cout << "-----Mahasiswa 2-----" << endl;
    cout << "Nama: " << mhs2.name <<endl;
    cout << "Alamat: " << mhs2.address <<endl;
    cout << "Umur: " << mhs2.age <<endl;

    return 0;
}
```
Kode diatas merupakan contoh program yang menggunakan tipe data abstrak, yaitu struct. Program diatas menggunakan struct `Mahasiswa` yang memuat tiga nilai yaitu name dan address yang sama-sama bertipe data character, dan ada age yang bertipe data integer. Lalu terdapat `const` pada nilai name dan adsress yang berfungsi supaya object atau variabel tidak dapat dimodifikasi. Setelah itu kita bisa mengisi data dengan membuat dua variabel yang bertipe data struct `Mahasiswa`, yaitu `mhs1` dan `mhs2`. Setelah itu kita tinggal mengisi data tersebut ke masing-masing variabel dan menampilkannya menggunakan fungsi `cout`.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;

int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
}
```
Kode diatas adalah contoh program yang menggunakan tipe data koleksi. Pertama kita mendeklarasikan dan menginialiasikan array `nilai` yang mempunyai tipe data integer. Untuk `[5]` adalah merupakan ukuran panjang array yang akan kita gunakan. Lalu kita bisa mengisikan data ke dalam variabel `nilai`, seperti `nilai[0]` atau elemen pertama dalam array kita isi dengan angka 23, lalu untuk elemen ke dua kita isi dengan angka 50, untuk elemen ketiga kita isi dengan angka 34, untuk elemen keempat kita isi dengan angka 78, dan elemen ke lima kita isi dengan angka 90. Setelah kita selesai mengisikan nilai ke setiap elemen dalam array kita bisa menampilkan setiap nilai dalam array menggunakan fungsi `cout`.

## Unguided 

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

char menu; //mendeklarasikan variabel menu dengan type data character
float fahrenheit,kelvin,one; //mendeklarasikan variabel dengan type data float

void choice() { //variable choice untuk memilih menu yang ingin digunakan
    cout <<"\n=====Temperature Converter Celsius====="<< endl; //menu
    cout << "A. Celsius to Fahrenheit" << endl;
    cout << "B. Celsius to Kelvin" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> menu;
}

float fahr() { //variable untuk menghitung celcius ke fahrenheit dengan type data float
    cout << "Input temperature in Celsius: "; //menginputkan suhu dalam celsius
    cin >> one;

    fahrenheit = (1.8 * one) + 32.0; //rumus menghitung celsius ke fahrenheit

    cout << "Temperature in degree Fahrenheit: " << fahrenheit << " F" << endl;
    return fahrenheit = (1.8 * one) + 32.0;
}

float kelv() { //variable untuk menghitung celcius ke kelvin dengan type data float
    cout << "Input temperature in Celsius: "; //menginputkan suhu dalam celcius
    cin >> one;

    kelvin = 273.15 + one; //rumus menghitung celsius ke kelvin

    cout << "Temperature in degree Kelvin: " << kelvin << " K" << endl; //menampilkan hasil
    return kelvin = 273.15 + one;
}

int main() { //menu utama
    do { //menggunakan looping do - while
        choice(); //memanggil variable choice
        switch (menu) {
            case 'A': //jika memilih A/a maka akan menghitung fahrenheit
            case 'a':
                fahr(); //menampilkan variable celcius ke fahrenheit
                break;

            case 'B': //jika memilih B/b maka akan menghitung kelvin
            case 'b':
                kelv(); //menampilkan variable celsius ke kelvin
                break;
                
            case '0': //jika ingin keluar dari looping maka bisa menginputkan angka 0
                cout << "Thank you for using this program. Goodbye!" << endl;
                break;

            default: //error message jika menginputkan selain huruf a, b, dan angka 0
                cout << "Invalid input. Please enter either 'A', 'B', or '0'." << endl;
                break;
        }
    } while (menu != '0'); /*jika user menginputkan angka selain 0 maka program otomatis 
    akan mengulang hingga user menginputkan angka 0 untuk mengakhiri loop*/
    return 0;
}
```
#### Output:
![unguided1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/4984c2f4-62fe-41ae-87e8-f1af69f4dade)

Kode diatas merupakan program yang digunakan untuk mengonversikan suhu dari celcius ke fahrenheit dan celcius ke kelvin. Pertama kita mendeklarasikan variabel yang akan digunakan untuk memilih menu, menginputkan suhu dalam celcius, dan menampilkan suhu dalam fahrenheit dan kelvin. untuk variabel `menu` kita menggunakan tipe data character, `fahrenheit`, `kelvin`, dan `one` yang digunakan untuk menginputkan suhu dalam celcius dengan tipe data float. Langkah selanjutnya kita membuat variabel `choice` yang berfungsi untuk menampilkan menu. Selanjutnya kita membuat variabel `fahr` yang berfungsi untuk mengonversikan nilai celcius ke fahrenheit. Kemudian kita membuat variabel `kelv` yang berfungsi untuk mengonversikan nilai celcius ke kelvin.

Setelah selesai membuat variabel yang akan digunakan untuk mengonversikan suhu, lalu kita akan menggunakan looping `do-while`. Looping ini berfungsi supaya jika user menginputkan angka atau huruf selain 0 atau `menu != 0`, maka program akan terus berjalan menampilkan menu. Lalu kita menggunakan `switch-case` supaya jika user menginputkan huruf `a` maka akan mengonversi suhu ke fahrenheit dan jika menginputkan huruf `b` maka akan mengonversi suhu ke kelvin. Lalu jika menginputkan angka `0` maka program otomatis akan berhenti dan menampilkan pesan, namun jika user menginputkan selain ketiga huruf dan angka diatas, maka akan muncul pesan error yang membuat program akan terus berjalan sehingga user harus memasukan operator yang tepat untuk menggunakan program diatas ataupun untuk menghentikan program.

Kesimpulan dari materi tipe data primitif ini adalah tipe data ini merupakan tipe data yang sederhana, karena tipe data ini merupakan tipe data bawaan dari bahasa pemrograman. Tipe data ini bisa menyimpan niali seperti digit, byte, ataupun karakter. Namun, tipe data primitif tidak bisa menjangkau data kompleks yang memiliki tingkat kerumitan tinggi.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

```C++
#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

struct figure { //membuat struct figure
    string name; //berisi variable name yang bertipe data string
    int age; //dan variable age yang bertipe data int

};

class character { //membuat class character
    public:
        string species; //berisi variable species yang bertipe data string
        string citizenship; //variable citizenship yang bertipe data string
        string pets; //variable pets yang bertipe data string
};

int main() { //program utama atau main program
    struct figure one; //memanggil struct figure yang sudah dibuat diatas

    //memasukan data ke dalam struct
    one.name = "Patrick Star"; 
    one.age = 18;

    //menampilkan data struct yang sudah masukan tadi
    cout << "=====STRUCT=====" << endl;
    cout << "Name: " << one.name << endl;
    cout << "Age: " << one.age << endl;

    //memanggil class character
    character two;

    //memasukan data ke dalam class
    two.species = "Starfish";
    two.citizenship = "Bikini Bottom";
    two.pets = "Rocky, Ouchie, Tinkle, Fabio";

    //menampilkan data class yang sudah dimasukkan
    cout << "=====CLASS=====" << endl;
    cout << "Species: " << two.species << endl;
    cout << "Citizenship: " << two.citizenship << endl;
    cout << "Pets: " << two.pets << endl;

    return 0;
}
```
#### Output:
![unguided2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/97e4321a-800b-4c50-aa12-e5cced21af15)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map

```C++
#include <iostream> //input preprocessor directive
#include <map> //input map
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main() { //main program 
    map <int, string> character; //membuat map dengan key int dan bertipe data string

    //menginputkan karakter
    character[0] = "Spongebob Squarepants";
    character[1] = "Patrick Star";
    character[2] = "Sandy Cheeks";
    character[3] = "Squidward Tentacles";
    character[4] = "Mr. Krabs";

    //menampilkan karakter yang sudah dibuat
    cout << "==========CHARACTER LIST==========" << endl;
    cout << "Karakter pertama : " << character[0] << endl;
    cout << "Karakter kedua : " << character[1] << endl;
    cout << "Karakter ketiga : " << character[2] << endl;
    cout << "Karakter keempat : " << character[3] << endl;
    cout << "Karakter kelima : " << character[4] << endl;

    return 0;
}
```
#### Output:
![unguided3](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/15d570e5-931f-4ec8-848d-3a3c189af3c3)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.