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