# <h1 align="center">Laporan Praktikum Modul Graph & Tree</h1>
<p align="center">Agung Malik Ibrahim</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### Graf
Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Graf terdiri dari simpul dan busur yang secara matematis dinyatakan sebagai :

<p> G = (V, E)</p>

Dimana G adalah Graph, V adalah simpul atau vertex dan E sebagai sisi atau edge. Dapat digambarkan: 
![graf 1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/87b05b89-871e-4c70-a995-04384658c5a7)
<br>Graph dapat digunakan dalam berbagai aplikasi, seperti jaringan sosial, pemetaan jalan, dan pemodelan data.</br> 

#### Jenis-Jenis Graf
![graf2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/f8e8ecf3-1105-4146-b254-3501866b1fc1)
- Graph berarah (directed graph): Urutan simpul mempunyai arti. Misal busur AB adalah e1 sedangkan busur BA adalah e8.
- Graph tak berarah (undirected graph): Urutan simpul dalam sebuah busur tidak diperhatikan. Misal busur e1 dapat disebut busur AB atau BA.
- Weight Graph : Graph yang mempunyai nilai pada tiap edgenya.

#### Representasi Graph dengan Matriks
![graf 3](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/20820fa5-ee21-44f8-a25b-9768ffaaffc4)

#### Representasi dengan Linked List
![graf 4](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/b9be0c5d-bcec-4955-8ac9-b6f131843c2f)

Pentingnya untuk memahami perbedaan antara simpul vertex dan simpul edge saat membuat representasi graf dalam bentuk linked list. Simpul vertex mewakili titik atau simpul dalam graf, sementara simpul edge mewakili hubungan antara simpul-simpul tersebut. Struktur keduanya bisa sama atau berbeda tergantung pada kebutuhan, namun biasanya seragam. Perbedaan antara simpul vertex dan simpul edge adalah bagaimana kita memperlakukan dan menggunakan keduanya dalam representasi graf.

![graf 5](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/047b9ed1-5cc3-4ba3-89dd-f9cab557c971)

### Tree atau Pohon
Dalam ilmu komputer, pohon/tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi. Istilah dalam struktur data tree dapat dirangkum sebagai berikut :
![tree1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/8545402f-d578-4463-8a12-b489bbb37bc6)
![tree2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/adba7957-7213-4b1c-9749-e68e25b0523a)

Binary tree atau pohon biner merupakan struktur data pohon akan tetapi setiap simpul dalam pohon diprasyaratkan memiliki simpul satu level di bawahnya (child)tidak lebih dari 2 simpul, artinya jumlah child yang diperbolehkan yakni 0, 1, dan 2. Gambar 1, menunjukkan contoh dari struktur data binary tree.
![tree3](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/13662815-72ff-43b5-9fa6-f8b23e903e47)
<br>Membuat struktur data binary tree dalam suatu program (berbahasa C++) dapat menggunakan struct yang memiliki 2 buah pointer, seperti halnya double linked list.</br>
![tree4](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/79c9e48c-7244-489e-a753-196483b504e6)

#### Operasi pada Tree
- Create: digunakan untuk membentuk binary tree baru yang masih kosong.
- Clear: digunakan untuk mengosongkan binary tree yang sudah ada atau menghapus semua node pada binary tree.
- isEmpty: digunakan untuk memeriksa apakah binary tree masih kosong atau tidak.
- Insert: digunakan untuk memasukkan sebuah node kedalam tree.
- Find: digunakan untuk mencari root, parent, left child, atau right child dari suatu node dengan syarat tree tidak boleh kosong.
- Update: digunakan untuk mengubah isi dari node yang ditunjuk oleh pointer current dengan syarat tree tidak boleh kosong.
- Retrive: digunakan untuk mengetahui isi dari node yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
- Delete Sub: digunakan untuk menghapus sebuah subtree (node beserta seluruh descendant-nya) yang ditunjuk pointer current dengan syarat tree tidak boleh kosong.
- Characteristic: digunakan untuk mengetahui karakteristik dari suatu tree. Yakni size, height, serta average lenght-nya.
- Traverse: digunakan untuk mengunjungi seluruh node-node pada tree dengan cara traversal. Terdapat 3 metode traversal yang dibahas dalam modul ini yakni Pre-Order, In-Order, dan Post-Order.

#### 1. Pre-Order
Penelusuran secara pre-order memiliki alur:
- Cetak data pada simpul root
- Secara rekursif mencetak seluruh data pada subpohon kiri
- Secara  rekursif mencetak seluruh data pada subpohon kanan dapat kita turunkan rumus penelusuran menjadi:
![tree5](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/6ff06411-5d3c-4525-b002-4974dc2c9fb8)
##### Alur Pre-Order
![tree6](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/feeb8f2e-6088-4c7e-8842-503b407d8cf1)
![tree7](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/cde5b0c5-136a-427e-b867-06d9399fbf28)

#### 2. In-Order
Penelusuran secara in-order memiliki alur:
- Secara rekursif mencetak seluruh data pada subpohon kiri
- Cetak data pada root
- Secara  rekursif mencetak seluruh data pada subpohon kanan dapat kita turunkan rumus penelusuran menjadi:
![tree8](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/fe6c0003-a361-424e-af95-6f5a16a78238)

#### 3. Post-Order
Penelusuran secara in-order memiliki alur:
- Secara rekursif mencetak seluruh data pada subpohon kiri
- Secara rekursif mencetak seluruh data pada subpohon kanan
- Cetak data pada root
Dapat kita turunkan rumus penelusuran menjadi:
<br>![tree9](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/3ed0ca7e-a186-41a6-a7df-d16f4fec9f05)</br>


## Guided 

### 1. Program Graph

```C++
#include <iostream>
#include <iomanip>
using namespace std;

string simpul[7] = {"Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 9, 15, 0},
    {0, 5, 0, 9, 5, 0, 0},
    {0, 0, 0, 2, 4, 0, 8},
    {3, 0, 0, 1, 0, 0, 0},
    {0, 0, 7, 0, 0, 9, 4},
    {0, 0, 0, 0, 8, 0, 0}
};

void tampilGraph() {
    for (int baris = 0; baris < 7; baris++) {
        cout << simpul[baris] << ": ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0)
                cout << " -> " << simpul[kolom] << "(" << busur[baris][kolom] << ")";
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
```
Kode di atas digunakan untuk mencetak program graf. Program ini mendefinisikan sebuah array string bernama simpul yang berisi nama tujuh kota: Ciamis, Bandung, Bekasi, Tasikmalaya, Cianjur, Purwokerto, dan Yogyakarta. Kota-kota ini mewakili simpul dari graf tersebut. Matriks ketetanggaan graf direpresentasikan oleh array 2D `busur`, di mana setiap elemen `busur[i][j]` menunjukkan bobot dari busur yang menghubungkan simpul `i` ke simpul `j`. Jika `busur[i][j]` bernilai nol, itu berarti tidak ada busur langsung dari simpul `i` ke simpul `j`. 

Fungsi `tampilGraph` melakukan iterasi melalui setiap simpul dan mencetak busur keluar beserta bobotnya. Untuk setiap simpul, fungsi ini memeriksa setiap simpul lainnya untuk melihat apakah terdapat busur (yaitu, bobotnya tidak nol). Jika busur ada, fungsi ini mencetak simpul tujuan dan bobot busur tersebut dalam format tertentu. Dalam fungsi `main`, program hanya memanggil fungsi `tampilGraph` untuk menampilkan graf. Outputnya menunjukkan setiap kota diikuti dengan koneksi langsungnya ke kota lain, termasuk bobot dari koneksi-koneksi tersebut.

### 2. Program Tree

```C++
#include <iostream>
using namespace std;

//Definisi struktur pohon
struct pohon {
    pohon* kanan;
    char data;
    pohon* kiri;
};

//Deklarasi variable global
pohon* simpul;
pohon* root;
pohon* saatIni;
pohon* helperA;
pohon* helperB;
pohon* alamat[256];

//fungsi unutuk inisialisasi root
void inisialisasi() {
    root = NULL;
}

//fungsi untuk memmbuat simpul baru
void simpulBaru(char dataMasukkan) {
    simpul = new pohon;
    simpul-> data = dataMasukkan;
    simpul->kanan = NULL;
    simpul->kiri = NULL;
}

//fungsi untuk membuat simpul akar
void simpulAkar() {
    if (root == NULL) {
        char dataAnda;
        cout << "Silakan masukkan data: ";
        cin >> dataAnda;
        simpulBaru(dataAnda);
        root = simpul;
        cout << "Root terbentuk..." << endl;
    } else {
        cout << "Root sudah ada..." << endl;
    }
}

//fungsi untk menambah simpul
void tambahSimpul() {
    if (root != NULL) {
        int i = 1, j = 1, penanda = 0;
        char dataUser;
        alamat[i] = root;

        while (penanda == 0 && j < 256) {
            cout << "Masukkan data kiri: ";
            cin >> dataUser;
            if (dataUser != '0') {
                simpulBaru(dataUser);
                saatIni = alamat[i];
                saatIni->kiri = simpul;
                j++;
                alamat[j] = simpul;
            } else {
                penanda = 1;
                j++;
                alamat[j] = NULL;
            }
            if (penanda == 0) {
                cout << "Masukkan data kanan: ";
                cin >> dataUser;
                if (dataUser != '0') {
                    simpulBaru(dataUser);
                    saatIni = alamat[i];
                    saatIni->kanan = simpul;
                    j++;
                    alamat[j] = simpul;
                } else {
                    penanda = 1;
                    j++;
                    alamat[j] = NULL;
                }
            }
            i++;
        }
    }
}

//fungsi untuk membaca pohon
void bacaPohon() {
    if (root != NULL) {
        int i = 1, n = 1, pencacah = 0;
        cout << endl;
        while (alamat[i] != NULL) {
            saatIni = alamat[i];
            cout << saatIni->data <<" ";
            pencacah++;
            if (pencacah == n) {
                cout << endl;
                pencacah = 0;
                n = n * 2;
            }
            i++;
        }
    }
}

//fungsi utama
int main() {
    inisialisasi();
    simpulAkar();
    tambahSimpul();
    bacaPohon();
    return 0;
}
```
Kode di atas digunakan untuk mencetak program tree. Pada kode mendefinisikan struktur pohon biner dengan nama `pohon`, yang memiliki tiga atribut: pointer ke anak kiri `kiri`, data berupa karakter `data`, dan pointer ke anak kanan `kanan`. Kemudian, beberapa variabel global dideklarasikan, termasuk pointer ke simpul saat ini `simpul`, akar pohon `root`, dan beberapa variabel pembantu lainnya. Fungsi `inisialisasi` digunakan untuk menginisialisasi akar pohon dengan nilai `NULL`, menandakan bahwa pohon belum memiliki akar. Fungsi `simpulBaru` digunakan untuk membuat simpul baru dengan data yang dimasukkan oleh pengguna. Simpul baru ini diinisialisasi dengan data yang diberikan dan kedua anaknya diset `NULL`.

Fungsi `simpulAkar` bertanggung jawab untuk membuat simpul akar jika akar belum ada. Pengguna diminta memasukkan data untuk simpul akar, yang kemudian digunakan untuk membuat simpul baru yang menjadi akar pohon. Jika akar sudah ada, pengguna diberitahu bahwa akar sudah ada. Fungsi `tambahSimpul` memungkinkan pengguna untuk menambahkan simpul-simpul baru ke dalam pohon. Proses ini dilakukan dengan meminta pengguna memasukkan data untuk anak kiri dan anak kanan dari simpul saat ini. Jika pengguna memasukkan '0', proses penambahan anak dihentikan untuk simpul tersebut. Simpul baru yang dibuat akan dihubungkan ke simpul saat ini sebagai anak kiri atau anak kanan sesuai dengan input pengguna. Fungsi `bacaPohon` digunakan untuk membaca dan mencetak pohon secara level-order, yang berarti mencetak data dari setiap simpul sesuai dengan level atau tingkatan dalam pohon. Fungsi ini akan mencetak data dari setiap simpul, baris demi baris, sehingga struktur pohon dapat divisualisasikan dengan mudah. Dalam fungsi `main`, program dimulai dengan menginisialisasi pohon, kemudian membuat simpul akar, menambahkan simpul-simpul baru ke pohon, dan akhirnya membaca serta mencetak pohon yang telah dibangun.

## Unguided 

### 1. Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya.

```C++
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//function menampilkan simpul
void tampilGraph_2311110067(const vector<string>& simpul, const vector<vector<int>>& busur) {
    cout << setw(10) << " ";
    for (const auto& s : simpul) {
        cout << setw(10) << s;
    }
    cout << endl;

    // Print rows
    for (int i = 0; i < simpul.size(); i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < simpul.size(); j++) {
            cout << setw(10) << busur[i][j];
        }
        cout << endl;
    }
}

int main() {
    int jumlahSimpul; //tambah simpul
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    vector<vector<int>> busur(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silakan masukkan nama simpul:" << endl; //tambah nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    cout << "Silakan masukkan bobot antar simpul:" << endl; //tambah bobot antar simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    cout << endl << "Graf yang telah dimasukkan:" << endl;
    tampilGraph_2311110067(simpul, busur);

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk menampilkan program graf dengan menggunakan inputan dari user. Function `tampilGraph_2311110067` didefinisikan untuk menampilkan graf dalam format yang rapi. Fungsi ini menerima dua parameter: sebuah vektor `simpul` yang berisi nama-nama simpul dan sebuah matriks 2D `busur` yang berisi bobot antara simpul-simpul tersebut. Dalam fungsi ini, nama-nama simpul dicetak sebagai header kolom, diikuti oleh baris-baris yang menampilkan nama simpul serta bobot-bobot yang terhubung dengan simpul-simpul lainnya. Di dalam fungsi `main`, program dimulai dengan meminta pengguna untuk memasukkan jumlah simpul. Jumlah ini kemudian digunakan untuk menginisialisasi vektor `simpul` dan matriks 2D `busur` dengan ukuran yang sesuai. Pengguna kemudian diminta untuk memasukkan nama-nama simpul, yang disimpan dalam vektor `simpul`.

Selanjutnya, program meminta pengguna untuk memasukkan bobot antar simpul. Dalam proses ini, setiap pasangan simpul (i, j) diminta bobotnya, yang kemudian disimpan dalam matriks `busur`. Jika tidak ada busur antara dua simpul tertentu, pengguna dapat memasukkan nilai nol. Setelah semua data dimasukkan, program menampilkan graf yang telah dibuat dengan memanggil fungsi `tampilGraph_2311110067`.

#### Full code Screenshot:
![fullcode1](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/3a12eadd-57cc-49bb-843f-256eb6686229)

### 2. Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, inorder, dan post order!

```C++
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//ininsialisasi node
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};

//buat node baru
TreeNode* createNode(string value) {
    return new TreeNode(value);
}

//tambah node
TreeNode* insertNode(TreeNode* root, string value) {
    if (!root) {
        return createNode(value);
    }

    char direction;
    cout << "Masukkan 'L' untuk " << value << " subpohon kiri " << root->value << " atau 'R' untuk subpohon kanan: ";
    cin >> direction;

    if (direction == 'L' || direction == 'l') {
        root->left = insertNode(root->left, value);
    } else if (direction == 'R' || direction == 'r') {
        root->right = insertNode(root->right, value);
    } else {
        cout << "Node belum dimasukan.\n";
    }

    return root;
}

//pre order
void preOrder(TreeNode* node) {
    if (node) {
        cout << node->value << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

//in order
void inOrder(TreeNode* node) {
    if (node) {
        inOrder(node->left);
        cout << node->value << " ";
        inOrder(node->right);
    }
}

//post order
void postOrder(TreeNode* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->value << " ";
    }
}

int main() { //main program
    TreeNode* root = nullptr;
    int choice_2311110067;
    string value;

    while (true) { //menu
        cout << "\nMenu Data Tree:\n";
        cout << "1. Tambah simpul\n";
        cout << "2. Tampilkan pre-order\n";
        cout << "3. Tampilkan in-order\n";
        cout << "4. Tampilkan post-order\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice_2311110067;

        switch (choice_2311110067) {
            case 1: //tambah nilai simpul
                cout << "Masukkan nilai simpul: ";
                cin >> value;
                if (!root) {
                    root = createNode(value);
                } else {
                    root = insertNode(root, value);
                }
                break;
            case 2: //menampilkan pre order
                cout << "Pre-order: ";
                preOrder(root);
                cout << endl;
                break;
            case 3: //menampilkan in order
                cout << "In-order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4: //menampilkan post order
                cout << "Post-order: ";
                postOrder(root);
                cout << endl;
                break;
            case 5: //keluar
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
```
#### Output:
![240302_00h00m06s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak modifikasi dari program guided 2 mengenai tree. Struktur `TreeNode` didefinisikan untuk merepresentasikan setiap simpul dalam pohon, dengan atribut nilai `value`, serta pointer ke anak kiri `left` dan anak kanan `right`. Fungsi `createNode` digunakan untuk membuat simpul baru, sementara fungsi `insertNode` digunakan untuk menambahkan simpul baru ke pohon, berdasarkan arah yang dipilih pengguna (kiri atau kanan). Program utama dimulai dengan inisialisasi akar pohon sebagai `nullptr`. Dalam sebuah loop, pengguna disajikan dengan menu yang memungkinkan mereka untuk menambahkan simpul baru atau menampilkan pohon dalam berbagai urutan. Saat pengguna memilih untuk menambahkan simpul, program meminta mereka untuk menentukan arah (kiri atau kanan) untuk setiap simpul baru relatif terhadap simpul yang ada.

Fungsi-fungsi `preOrder`, `inOrder`, dan `postOrder` digunakan untuk menampilkan pohon dalam urutan pre-order, in-order, dan post-order, masing-masing. Dalam setiap urutan ini, simpul-simpul pohon dikunjungi dan nilainya dicetak sesuai dengan aturan traversal yang berlaku. Program berakhir ketika pengguna memilih angka 5 untuk keluar dari menu.

#### Full code Screenshot:
![fullcode2](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a302333e-3758-4adc-94e0-8aa5af62d059)


## Kesimpulan
Pada kesimpulan guided kita belajar mengenai graf dan tree. Graf atau graph adalah struktur data yang digunakan untuk merepresentasikan hubungan antara objek dalam bentuk node atau vertex dan sambungan antara node tersebut dalam bentuk sisi atau edge. Kemudian pohon/tree adalah struktur data yang sangat umum dan kuat yang menyerupai nyata pohon. Ini terdiri dari satu set node tertaut yang terurut dalam grafik yang terhubung, dimana setiap node memiliki paling banyak satu simpul induk, dan nol atau lebih simpul anak dengan urutan tertentu. Struktur data tree digunakan untuk menyimpan data-data hirarki seperti pohon keluarga, skema pertandingan, struktur organisasi.

Lalu pada unguided kita belajar mengenai membuat program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya dan memodifikasi guided tree dengan program menu menggunakan input data tree dari user dan tampilkan pada pre-order, in-order, dan post-order.

## Referensi
[1] Karumanchi, N. (2011). Data Structures and Algorithms Made Easy: 700 Data Structure and Algorithmic Puzzles. CreateSpace.

[2] Ashraf, Zeeshan. (2017). Data Structure in C++ Graphically. 
