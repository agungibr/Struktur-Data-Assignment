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

    book.judul_buku = "To Kill a Mockingbird"; 
    book.pengarang = "Harper Lee";
    book.penerbit = "Gramedia";
    book.tebal_halaman = 261;
    book.harga_buku = 700000;

    book2.judul_buku = "Pride and Prejudice "; 
    book2.pengarang = "Jane Austen";
    book2.penerbit = "Gramedia";
    book2.tebal_halaman = 350;
    book2.harga_buku = 650000;

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