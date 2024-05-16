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
