# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Agung Malik Ibrahim</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Linked list adalah basic dan primitive data structure. Linked list ini banyak digunakan dalam pemrograman komputer. Linked list terdiri dari sebuah urutan node, di mana setiap node berisi data dan tautan ke node berikutnya. Linked list adalah struktur data berurutan dalam arti bahwa data muncul satu demi satu dalam urutan node. Datanya diakses dan dilalui dari awal hingga akhir. Linked list dapat di double, yang berarti bahwa setiap node memiliki pointer ke dua yang menunjuk ke node sebelumnya. Linked list dapat dilalui di kedua arah dengan mengikuti dua pointers [1]. 

Di sisi lain, sebuah linked list menyimpan elemen dalam simpul - satu simpul untuk setiap elemen.  Sebuah simpul berisi sebuah elemen dan juga sebuah tautan ke simpul berikutnya (dan sebuah tautan lain ke simpul sebelumnya jika senarai berantai tersebut merupakan senarai berantai ganda). Memori untuk setiap simpul dialokasikan secara dinamis selama program dijalankan. Oleh karena itu, memori yang dialokasikan oleh sebuah senarai berantai tidak bersebelahan [2]. 

### A. Single Linked List
Linked List merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Pointer adalah alamat elemen. Setiap simpul pada dasarnya dibagi atas  dua bagian pertama disebut bagian isi atau informasi atau data yang berisi nilai yang disimpan oleh simpul. Bagian kedua disebut bagian pointer yang berisi alamat dari node berikutnya atau sebelumnya. Dengan menggunakan struktur seperti ini, linked list dibentuk dengan cara menunjuk pointer next suatu elemen ke elemen yang mengikutinya. Pointer next pada elemen terakhir merupakan NULL, yang menunjukkan akhir dari suatu list. Elemen pada awal suatu list disebut head dan elemen terakhir dari suatu list disebut tail.  
![1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/687eea6d-7142-4923-81ee-79323721177a)

#### Linked List Circular
Linked list circular merupakan linked list yang tidak memiliki akhir karena node  terakhir (tail) tidak bernilai ‘NULL’, tetapi terhubung dengan node pertama (head).  Saat menggunakan linked list circular kita membutuhkan dummy node atau node  pengecoh yang biasanya dinamakan dengan node current supaya program dapat  berhenti menghitung data ketika node current mencapai node pertama (head). 

Linked list circular dapat digunakan untuk menyimpan data yang perlu diakses  secara berulang, seperti daftar putar lagu, daftar pesan dalam antrian, atau  penggunaan memori berulang dalam suatu aplikasi. Linked list circular dapat  digambarkan sebagai berikut. 
![2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/08efed40-d83b-4def-b7a2-758fe52e0ab6)

### B. Double Linked List
Double Linked List adalah struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya. Dengan adanya pointer prev, Double Linked List memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul mana saja secara efisien. Setiap simpul pada Double Linked List memiliki tiga elemen penting, yaitu elemen data (biasanya berupa nilai), pointer next yang menunjuk ke simpul berikutnya, dan pointer prev yang menunjuk ke simpul sebelumnya.

Keuntungan dari Double Linked List adalah memungkinkan untuk melakukan operasi penghapusan dan penambahan pada simpul dimana saja dengan efisien, sehingga sangat berguna dalam implementasi beberapa algoritma yang membutuhkan operasi tersebut. Selain itu, Double Linked List juga memungkinkan kita untuk melakukan traversal pada list baik dari depan (head) maupun dari belakang (tail) dengan mudah. Namun, kekurangan dari Double Linked List adalah penggunaan memori yang lebih besar dibandingkan dengan Single Linked List, karena setiap simpul membutuhkan satu pointer tambahan. Selain itu, Double Linked List juga membutuhkan waktu eksekusi yang lebih lama dalam operasi penambahan dan penghapusan jika dibandingkan dengan Single Linked List. Representasi sebuah double linked list dapat dilihat pada gambar berikut ini:
![3](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/0ae3cc2b-eb95-4de6-a4ee-b1340c4d755f)

Di dalam sebuah linked list, ada 2 pointer yang menjadi penunjuk utama, yakni pointer HEAD yang menunjuk pada node pertama di dalam linked list itu sendiri dan pointer TAIL yang menunjuk pada node paling akhir di dalam linked list. Sebuah linked list dikatakan kosong apabila isi pointer head adalah NULL. Selain itu, nilai pointer prev dari HEAD selalu NULL, karena merupakan data pertama. Begitu pula dengan pointer next dari TAIL yang selalu bernilai NULL sebagai penanda data terakhir. 

## Guided 

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
    return true;
    else
    return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
Kode di atas digunakan untuk mencetak single linked list pada C++. Fungsi-fungsi yang didefinisikan dalam program tersebut memungkinkan pengguna untuk melakukan operasi dasar pada linked list, seperti menambahkan node di depan, di belakang, atau di tengah, menghapus node, mengubah nilai data pada node tertentu, menghitung jumlah node dalam linked list, dan menampilkan isi linked list. 

Program dimulai dengan deklarasi struktur Node yang berisi dua bagian, yaitu data dan pointer ke node selanjutnya. Kemudian, beberapa fungsi diinisialisasi untuk mengatur linked list, termasuk inisialisasi linked list, pengecekan apakah linked list kosong, penambahan node di depan, di belakang, atau di tengah, penghapusan node, pengubahan nilai data pada node tertentu, menghitung jumlah node, menghapus semua node, dan menampilkan isi linked list. Di dalam fungsi main, beberapa operasi ditampilkan untuk menguji fungsionalitas linked list, seperti menambahkan node, menghapus node, mengubah nilai data pada node tertentu, dan menampilkan isi linked list setelah setiap operasi.

### 2. Latihan Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) { //tambahdepan
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
Kode di atas digunakan untuk mencetak double linked list pada C++. Kelas `Node` didefinisikan dengan tiga member yaitu `data` untuk menyimpan nilai data, `prev` untuk menunjukkan node sebelumnya, dan `next` untuk menunjukkan node selanjutnya. Kelas `DoublyLinkedList` memiliki dua pointer `head` dan `tail` yang menunjukkan ke node pertama dan terakhir dalam linked list. Beberapa fungsi yang diimplementasikan dalam kelas `DoublyLinkedList` antara lain `push(int data)` yang digunakan untuk menambahkan node baru di depan linked list, `pop()` yang digunakan untuk menghapus node dari depan linked list, `update(int oldData, int newData)` untuk mengupdate nilai data pada node yang memiliki nilai data tertentu, `deleteAll()` untuk menghapus semua node dari linked list, dan `display()` untuk menampilkan isi dari linked list. 

Di dalam fungsi main, pengguna diberi menu untuk memilih operasi yang ingin dilakukan pada linked list, seperti menambah data, menghapus data, mengupdate data, membersihkan data, menampilkan isi data, dan keluar dari program. Program akan terus berjalan hingga pengguna memilih untuk keluar dengan memasukkan angka 6.

## Unguided 

### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user

```C++
#include <iostream>
#include <iomanip>

using namespace std;

struct Node { //membuat struct node
	string name;
	int age;
	Node* next;
};

Node* head;
Node* tail;

void init() { //inisialisasi node
	head = NULL;
	tail = NULL;
}

bool isEmpty(){ //pengecekan
    if (head == NULL)
    	return true;
    else
    	return false;
}

void insertDepan(string name, int age) { //tambah depan
	Node* baru = new Node;
	baru->name = name;
	baru->age = age;
	baru->next = NULL;

	if (isEmpty() == true) {
		head = tail = baru;
		tail->next = NULL;
	} else {
		baru->next = head;
		head = baru;
	}
}

void insertBelakang(string name, int age) { //tambah belakang
	Node* baru = new Node;
	baru->name = name;
	baru->age = age;
	baru->next = NULL;

	if (isEmpty() == true) {
		head = tail = baru;
		tail->next = NULL;
	} else {
		tail->next = baru;
		tail = baru;
	}
}

int hitungList() { //hitung jumlah list
	Node* hitung;
	hitung = head;
	int jumlah = 0;

	while (hitung != NULL) {
		jumlah++;
		hitung = hitung->next;
	}
	return jumlah;
}

void insertTengah(string name, int age, int posisi) { //tambah tengah
	if (posisi < 1 || posisi > hitungList()) {
		cout << "Posisi diluar jangkauan" << endl;
	} else if (posisi == 1) {
		cout << "Posisi bukan posisi tengah" << endl;
	} else {
		Node* baru, *bantu;
		baru = new Node();
		baru->name = name;
		baru->age = age;

		bantu = head;
		int nomor = 1;

		while (nomor < posisi - 1) {
			bantu = bantu->next;
			nomor++;
		}

		baru->next = bantu->next;
		bantu->next = baru;
	}
}

void hapusDepan() { //menghapus depan
	Node* hapus;

	if (isEmpty() == false) {
		if (head->next != NULL) {
			hapus = head;
			head = head->next;
			delete hapus;
		} else {
			head = tail = NULL;
		}
	} else {
		cout << "List kosong!" << endl;
	}
}

void hapusBelakang() { //menghapus belakang
	Node* hapus;
	Node* bantu;

	if (isEmpty() == false) {
		if (head != tail) {
			hapus = tail;
			bantu = head;

			while (bantu->next != tail) {
				bantu = bantu->next;
			}

			tail = bantu;
			tail->next = NULL;
			delete hapus;
		} else {
			head = tail = NULL;
		}
	} else {
		cout << "List kosong!" << endl;
	}
}

void hapusTengah(int posisi) { //menghapus tengah
	Node* hapus, *bantu, *bantu2;

	if (posisi < 1 || posisi > hitungList()) {
		cout << "Posisi di luar jangkauan" << endl;
	} else if (posisi == 1) {
		cout << "Posisi bukan posisi tengah" << endl;
	} else {
		int nomor = 1;
		bantu = head;

		while (nomor <= posisi) {
			if (nomor == posisi - 1) {
				bantu2 = bantu;
			}

			if (nomor == posisi) {
				hapus = bantu;
			}

			bantu = bantu->next;
			nomor++;
		}
		bantu2->next = bantu;
		delete hapus;
	}
}

void ubahDepan(string name, int age) { //mengubah depan
	if (isEmpty() == false) {
		head->name = name;
		head->age = age;
	} else {
		cout << "List masih kosong!" << endl;
	}
}

void ubahTengah(string name, int age, int posisi) { //mengubah tengah
    Node* bantu;

    if (isEmpty() == false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            bantu = head;
            int nomor = 1;

            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }

            bantu->name = name;
            bantu->age = age;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

void ubahBelakang (string name, int age) { //mengubah belakang
	if (isEmpty() == false) {
		tail->name = name;
		tail->age = age;
	} else {
		cout << "List masih kosong!" << endl;
	}
}

void clearList() { //hapus list
	Node* bantu, *hapus;
	bantu = head;

	while (bantu != NULL) {
		hapus = bantu;
		bantu = bantu->next;
		delete hapus;
	}

	head = tail = NULL;
	cout << "List berhasil terhapus!" << endl;
}

void tampil() { //menampilkan list
	Node* bantu;
	bantu = head;

	cout << left << setw(15) << "Nama" << right << setw(4) << "Usia" << endl;

	if (isEmpty() == false) {
		while (bantu != NULL) {
			cout << left << setw(15) << bantu->name << right << setw(4) << bantu->age << endl;
			bantu = bantu->next;
		}
		cout << endl;

	} else {
		cout << "List masih kosong!" << endl;
	}
}

int main() { //main program
	init();

	//menambahkan data
	insertBelakang("Agung", 19);
	insertBelakang("John", 19);
    insertBelakang("Jane", 20);
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20); 
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);
    tampil();

	//menampilkan menu
    while (true) {
    	cout << "\n1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Hapus Depan" << endl;
        cout << "5. Hapus Belakang" << endl;
        cout << "6. Hapus Tengah" << endl;
        cout << "7. Ubah Tengah" << endl;
        cout << "8. Hapus Semua" << endl;
        cout << "9. Tampilkan Data" << endl;
        cout << "0. Exit" << endl;

        int pilihan;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        	case 1: //tambah depan
        	{
        		string name;
        		int age;

        		cout << "Masukkan nama: ";
        		cin >> name;

        		cout << "Masukkan umur: ";
        		cin >> age;

        		insertDepan(name, age);
        		cout << "Data berhasil ditambahkan!" << endl;
        		break;
        	}
        	case 2: //tambah belakang
        	{
        		string name;
        		int age;

        		cout << "Masukkan nama: ";
        		cin >> name;

        		cout << "Masukkan umur: ";
        		cin >> age;

        		insertBelakang(name, age);
        		cout << "Data berhasil ditambahkan!" << endl;
        		break;
        	}
        	case 3: //tambah tengah
        	{
        		string name;
        		int age, posisi;

        		cout << "Masukkan nama: ";
        		cin >> name;

        		cout << "Masukkan umur: ";
        		cin >> age;

        		cout << "Masukkan posisi: ";
        		cin >> posisi;

        		insertTengah(name, age, posisi);
        		cout << "Data berhasil ditambahkan!" << endl;
        		break;
        	}
        	case 4: //hapus depan
        	{
        		hapusDepan();
        		cout << "Data berhasil dihapus" << endl;
        		break;
        	}
        	case 5: //hapus belakang
        	{
        		hapusBelakang();
        		cout << "Data berhasil dihapus" << endl;
        		break;
        	}
        	case 6: //hapus tengah
        	{
        		int posisi;

        		cout << "Masukkan posisi: ";
        		cin >> posisi;

        		hapusTengah(posisi);
        		cout << "Data berhasil dihapus" << endl;
        		break;
        	}
        	case 7: //ubah tengah
        	{
        		string name;
        		int age, posisi;

        		cout << "Masukkan nama: ";
        		cin >> name;

        		cout << "Masukkan umur: ";
        		cin >> age;

        		cout << "Masukkan posisi: ";
        		cin >> posisi;

        		ubahTengah(name, age, posisi);
        		cout << "Data berhasil diubah!" << endl;
        		break;
        	}
        	case 8: //hapus semua
        	{
        		hapusDepan();
        		break;
        	}
        	case 9: //tampilkan data
        	{
        		tampil();
        		break;
        	}
        	case 0:
        	{
        		return 0;
        	}
        	default:
        	{
        		cout << "Input yang anda masukkan tidak sesuai";
        		break;
        	}
        }
    }
}
```
#### Output:
a. Masukkan data sesuai urutan berikut. Data pertama yang dimasukkan adalah nama dan usia anda.
![1a](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/13973833-7861-422b-889e-3fb321e476bc)

b. Hapus data Akechi
![1b](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/c08821e2-bfbc-4417-8346-ff6b3fcfa4db)

c. Tambahkan data berikut diantara John dan Jane : Futaba  18
![1c](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a49e7d26-70a9-4dbc-b55f-a6e444fd3bd2)

d. Tambahkan data berikut diawal : Igor    20
![1d](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/15270d1e-56a0-4fa7-a331-afe5914ea131)

e. Ubah data Michael menjadi : Reyn    18
![1e](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/9bd741a2-4c5f-4c89-91db-85d79ee7c54f)

f. Tampilkan seluruh data
![1f](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/c5c354e0-7b59-48d8-8265-a640987855e9)

Kode di atas digunakan untuk mencetak Single linked list pada C++. Pada program ini, struktur Node didefinisikan untuk menyimpan data dan pointer ke node berikutnya. Terdapat fungsi-fungsi untuk menginisialisasi linked list, menambahkan node di depan, di belakang, atau di tengah, menghapus node, mengubah nilai data pada node tertentu, menghitung jumlah node dalam linked list, dan menampilkan isi linked list. Fungsi main berfungsi sebagai antarmuka pengguna, di mana pengguna diberi pilihan untuk melakukan berbagai operasi pada linked list, seperti menambahkan data di depan, belakang, atau tengah, menghapus data, mengubah data, menghapus semua data, dan menampilkan isi data. Program akan terus berjalan hingga pengguna memilih untuk keluar dengan memasukkan angka 0.

#### Full code Screenshot:
![fullcode1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/48408b58-5170-4a6a-b055-ee1e6d9c7bc9)

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

```C++
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

        cout << "\nMasukan pilihan [1-7]: ";
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
```
#### Output:
a. Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific
![2a](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/6f1fdbb4-ce87-4838-9cbc-56c1107fe240)

b. Hapus produk wardah
![2b](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a5f417ce-b255-4f4e-9512-0af113f9e0a9)

c. Update produk Hanasui menjadi Cleora dengan harga 55.000
![2c](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/03330de2-7518-4a56-b82f-25ea2fb57ea7)

d. Tampilkan menu
![2d](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/56a6d60e-9003-4b2f-936c-0873dab4f08f)

Kode di atas digunakan untuk mencetak Double linked list pada C++. Kelas Node digunakan untuk merepresentasikan setiap produk skincare, yang menyimpan informasi seperti nama produk dan harganya. Setiap node memiliki pointer yang menunjuk ke node sebelumnya dan node berikutnya. Kelas DoublyLinkedList berfungsi untuk menyimpan daftar produk skincare dalam bentuk Doubly Linked List. 

Beberapa operasi yang dapat dilakukan dalam aplikasi ini antara lain yaitu menambahkan produk baru ke dalam daftar, menghapus produk dari daftar berdasarkan nama produk, mengupdate informasi produk, menambahkan produk baru setelah produk tertentu, menghapus seluruh daftar produk, dan menampilkan daftar produk yang tersimpan. Dalam fungsi main, pengguna diberikan pilihan untuk melakukan operasi-operasi tersebut melalui menu. Pengguna dapat menambahkan produk baru, menghapus produk, mengupdate informasi produk, menambahkan produk baru setelah produk tertentu, menghapus seluruh daftar produk, dan menampilkan daftar produk yang tersimpan. Program akan berjalan hingga pengguna memilih untuk keluar dari aplikasi.

#### Full code Screenshot:
![fullcode2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/22d8e59a-8eab-4613-a3c0-6764587134b3)

## Kesimpulan
Kesimpulan pada guided yaitu kita belajar mengenai linked list yang merupakan suatu bentuk struktur data yang berisi kumpulan data yang disebut sebagai node yang tersusun secara sekuensial, saling sambung menyambung, dinamis, dan terbatas. Setiap elemen dalam linked list dihubungkan ke elemen lain melalui pointer. Masing-masing komponen sering disebut dengan simpul atau node atau verteks. Lalu ada linked list circular yang merupakan linked list yang tidak memiliki akhir karena node  terakhir (tail) tidak bernilai ‘NULL’, tetapi terhubung dengan node pertama (head) dan ada double linked List yang merupakan struktur data Linked List yang mirip dengan Single Linked List, namun dengan tambahan satu pointer tambahan pada setiap simpul yaitu pointer prev yang menunjuk ke simpul sebelumnya.

Lalu pada unguided kita belajar untuk mengimplementasikan bagaimana single linked list non-circular bekerja untuk menyimpan nama dan usia mahasiswa dengan menggunakan inputan dari user dan mengimplementasikan double linked list dengan menambahkan CRUD dan memperbaiki tampilan hasilnya.

## Referensi
[1] M. R. Abu Sara, “Balanced Linked List (BaLL): A Modified Linked List for Efficiently Maintaining a Sorted Sequence of Data,” vol. 6, Apr. 2021, doi: https://doi.org/10.15282/ijsecs.6.1.2020.6.0069.

[2] Carraway, J. (1996). Doubly-Linked Opportunities. ACM SIG3C 3C ONLINE, Vol. 3, No. 1, pp.9-12. 