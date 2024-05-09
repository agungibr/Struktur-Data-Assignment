#include <iostream>
#include <iomanip> 
#include <string>

using namespace std;

class Node { //menyimpan informasi product
public:
    string product;
    int harga;
    Node *prev;
    Node *next;
};

class DoublyLinkedList { //menyimpan daftar product
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string product, int harga) { //tambah product
        Node *newNode = new Node;
        newNode->product = product;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void hapusNode(string product) { //hapus product berdasarkan nama
        Node *current = head;

        while (current != nullptr) {
            if (current->product == product) {
                if (current->prev != nullptr) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }

                if (current->next != nullptr) {
                    current->next->prev = current->prev;
                } else {
                    tail = current->prev;
                }

                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Data dengan nama produk '" << product << "' tidak ditemukan" << endl;
    }

    void tambahAfter(string product, int harga, string afterProduk, int afterHarga) {  //tambah product setelah product
        Node *current = head;

        while (current != nullptr) {
            if (current->product == afterProduk && current->harga == afterHarga) {
                Node *newNode = new Node;
                newNode->product = product;
                newNode->harga = harga;
                newNode->prev = current;
                newNode->next = current->next;

                if (current->next != nullptr) {
                    current->next->prev = newNode;
                } else {
                    tail = newNode;
                }
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        cout << "Data not found" << endl;
    }

    bool update(string oldproduct, int oldHarga, string newproduct, int newHarga) { //update data
        Node *current = head;

        while (current != nullptr) {
            if (current->product == oldproduct && current->harga == oldHarga) {
                current->product = newproduct;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void hapus() { //hapus data
        Node *current = head;
        
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void tampil() { //menampilkan data
        Node *current = tail; 
        cout << "-----------------------------------------" << endl;
        cout << "|       Nama Produk     |     Harga     |" << endl;
        cout << "-----------------------------------------" << endl;

        while (current != nullptr) {
            cout << "|\t" << setw(12) << left << current->product << " \t| " << setw(6) << current->harga << " \t|" << endl;
            current = current->prev; 
        }
        cout << "-----------------------------------------" << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.push("Originote", 60000);
    list.push("Somethinc", 150000);
    list.push("Skintific", 100000);
    list.push("Wardah", 50000);
    list.push("Hanasui", 30000);

    int choice;
    do {
        cout << "\nToko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;

        cout << "\nMasukan pilihan [1-8]: ";
        cin >> choice;

        switch (choice) {
            case 1:
            {
                string product;
                int harga;
                cout << "Masukan nama product: ";
                cin >> product;
                cout << "Masukan harga: ";
                cin >> harga;
                list.push(product, harga);
                break;
            }
            case 2:
            {
                string product;
                cout << "Masukan nama product: ";
                cin >> product;
                list.hapusNode(product);
                break;
            }
            case 3:
            {
                string oldproduct, newproduct;
                int oldHarga, newHarga;
                cout << "Masukkan nama product lama: ";
                cin >> oldproduct;
                cout << "Masukkan harga product lama: ";
                cin >> oldHarga;
                cout << "Masukkan nama product baru: ";
                cin >> newproduct;
                cout << "Masukkan harga product baru: ";
                cin >> newHarga;
                bool updated = list.update(oldproduct, oldHarga, newproduct, newHarga);
                if (updated)
                {
                    cout << "Data berhasil diperbarui" << endl;
                }
                else
                {
                    cout << "Data tidak ditemukan" << endl;
                }
                break;
            }
            case 4:
            {
                string product, afterProduk;
                int harga, afterHarga;
                cout << "Masukkan nama product yang akan ditambahkan: ";
                cin >> product;
                cout << "Masukkan harga product yang akan ditambahkan: ";
                cin >> harga;
                cout << "Masukkan nama product setelah product baru: ";
                cin >> afterProduk;
                cout << "Masukkan harga product setelah product baru: ";
                cin >> afterHarga;
                list.tambahAfter(product, harga, afterProduk, afterHarga);
                break;
            }
            case 5:
            {
                string product;
                cout << "Masukkan nama product yang akan dihapus: ";
                cin >> product;
                list.hapusNode(product);
                break;
            }
            case 6:
            {
                list.hapus();
                cout << "Semua data berhasil dihapus" << endl;
                break;
            }
            case 7:
            {
                list.tampil();
                break;
            }
            case 8:
            {
                break;
            }
            default:
            {
                cout << "Input yang anda masukkan tidak sesuai" << endl;
                break;
            }
            }
        } while (choice != 8);

    return 8;
}