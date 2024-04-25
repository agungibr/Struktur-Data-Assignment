#include <iostream> //input preprocessor directive

using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main(){ //main program
    int n = 10; //panjang array
    int data[n] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}; //isi array
    int cari = 4; //angka yang dicari
    int count = 0; //menyimpan jumlah angka 4
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++){
        if(data[i] == cari){
            count++;
        }
    }
    cout << "\n\t Program Menghitung Angka 4\n" << endl;
    cout << " data: {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}" << endl;

    if (count > 0){
        cout << "\n angka "<< cari << " ditemukan sebanyak " << count << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;

}