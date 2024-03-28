#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main() //main program
{
    int panjang; //mendeklarasikan variabel panjang dengan tipe data integer
    cout << "Masukkan panjang array: "; //input panjang array yang akan dibuat
    cin >> panjang;
    int arr[panjang]; //mendeklarasikan array sesuai dengan input panjang array dari user

    cout << "Masukkan " << panjang << " angka\n"; //menampilkan jumlah array yang sudah di inputkan
    for (int i = 0; i < panjang; i++)
    {
        cout << "Array ke - " << i << ": "; //input elemen array 
        cin >> arr[i];
    }
    cout << endl;

    cout << "Data Array : "; //output elemen array
    for (int i = 0; i < panjang; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Nomor Genap : "; //menampilkan angka genap
    for (int i = 0; i < panjang; i++)
    {
        if (arr[i] % 2 == 0)
        {
            cout << arr[i] << ", ";
        }
    }
    cout << endl;

    cout << "Nomor Ganjil : "; //menampilkan angka genap
    for (int i = 0; i < panjang; i++)
    {
        if (arr[i] % 2 != 0)
        {
            cout << arr[i] << ", ";
        }
    }
}
