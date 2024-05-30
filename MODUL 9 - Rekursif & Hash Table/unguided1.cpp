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
