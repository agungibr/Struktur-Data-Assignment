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
