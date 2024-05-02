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
