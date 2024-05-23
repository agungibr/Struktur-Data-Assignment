# <h1 align="center">Laporan Praktikum Modul Priority Queue & Heap</h1>
<p align="center">Agung Malik Ibrahim</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Dalam priority queue, setiap elemen memiliki nilai prioritas yang terkait dengannya. Ketika menambahkan elemen ke antrian, elemen tersebut dimasukkan ke dalam posisi berdasarkan nilai prioritasnya. Misalnya, jika menambahkan elemen dengan nilai prioritas tinggi ke priority queue, elemen tersebut mungkin dimasukkan di dekat bagian depan antrian, sementara elemen dengan nilai prioritas rendah mungkin dimasukkan di dekat bagian belakang.

![priority_queue](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/93aceba2-9923-45ba-a00e-71bfaeed9a1b)

Ada beberapa cara untuk mengimplementasikan priority queue, termasuk menggunakan array, linked list, heap, atau binary search tree. Setiap metode memiliki kelebihan dan kekurangannya sendiri, dan pilihan terbaik akan tergantung pada kebutuhan spesifik aplikasi. Priority queue sering digunakan dalam sistem real-time, di mana urutan pemrosesan elemen dapat memiliki konsekuensi yang signifikan. Selain itu, priority queue juga digunakan dalam algoritma untuk meningkatkan efisiensi, seperti algoritma Dijkstra untuk menemukan jalur terpendek dalam grafik dan algoritma pencarian A* untuk pencarian jalur.

![heap](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/acae01cc-d2d5-4444-b8fc-7c4bf1ffe1d1)

Heap dalam struktur data adalah struktur berbasis pohon biner (binary tree) dengan aturan tertentu. Heap memiliki beberapa ciri khas yang membedakannya dari pohon binary biasa, yaitu: 
- Complete Binary Tree: Heap harus berbentuk complete binary tree, di mana setiap levelnya terisi penuh kecuali level paling bawah. Level paling bawah pun harus terisi dari kiri ke kanan.
- Order Property: Heap bisa dibagi menjadi dua jenis, yaitu max-heap dan min-heap.
- Max-heap: pada setiap node, nilai orang tua (parent) harus lebih besar atau sama dengan nilai anaknya (children).
- Min-heap: pada setiap node, nilai orang tua harus lebih kecil atau sama dengan nilai anaknya.

Dengan aturan ini, nilai terbesar (max-heap) atau terkecil (min-heap) akan selalu berada di node paling atas (root). Heap sering digunakan untuk algoritma sorting seperti heap sort dan juga untuk priority queue. Heap memiliki kelebihan dalam hal kecepatan operasi. Menambah atau menghapus elemen dalam heap hanya membutuhkan waktu O(log N), sedangkan mencari elemen minimum/maksimum hanya membutuhkan waktu konstan O(1).


## Guided 

### 1. Guided

```C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    insert(45);
    insert(20);
    insert(14);
    insert(12);
    insert(31);
    insert(7);
    insert(11);
    insert(13);
    insert(7);

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }

    std::cout << "\n";

    std::cout << "Node with maximum priority : " << extractMax() << "\n";
    
    std::cout << "Priority queue after extracting maximum : ";

    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    changePriority(2, 49);
    std::cout << "Priority queue after priority change : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    remove(3);
    std::cout << "Priority queue after removing the element : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    
    return 0;
}
```
Kode di atas digunakan untuk mengimplementasikan heap dan priority queue. Fungsi `parent`, `leftChild`, dan `rightChild` bertugas menghitung indeks induk, anak kiri, dan anak kanan dari sebuah elemen dalam heap. Fungsi `shiftUp` dan `shiftDown` digunakan untuk menjaga properti heap. `shiftUp` menaikkan elemen dalam heap sampai menemukan posisi yang sesuai, sedangkan `shiftDown` menurunkan elemen ke bawah sampai posisinya sesuai dengan aturan heap. Fungsi `insert` menambahkan elemen baru ke dalam heap dan memastikan elemen tersebut berada pada posisi yang tepat menggunakan `shiftUp`. Fungsi `extractMax` mengambil elemen maksimum (root dari heap), menghapusnya dari heap, dan memperbaiki struktur heap dengan `shiftDown`.

Dalam fungsi `main`, beberapa operasi utama heap diimplementasikan. Elemen-elemen dimasukkan ke dalam heap menggunakan `insert`. Setelah itu, elemen dengan prioritas maksimum diambil menggunakan `extractMax`, dan hasilnya ditampilkan. Prioritas elemen pada indeks tertentu diubah menggunakan `changePriority`, dan satu elemen dihapus menggunakan `remove`.

## Unguided 

### 1. Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user

```C++
#include <iostream>
#include <algorithm>

using namespace std;

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return ((2 * i) + 1);
}

int rightChild(int i) {
    return ((2 * i) + 2);
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) { //insert
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() { //extract max
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) { //change priority
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() { //get max
    return H[0];
}

void remove(int i) { //remove
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

void display() { //menampilkan
    cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        cout << H[i] << " ";
    }
    cout << "\n";
}

int main() { //main program
    int choice, value, index;

    do { //menu
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Extract Max\n";
        cout << "3. Get Max\n";
        cout << "4. Change Priority\n";
        cout << "5. Remove\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1: //insert
                cout << "Masukkan angka: ";
                cin >> value;
                insert(value);
                break;

            case 2: //extract max
                if (heapSize >= 0) {
                    cout << "Extracted Max: " << extractMax() << "\n";
                } else {
                    cout << "Heap kosong\n";
                }
                break;

            case 3: //get max
                if (heapSize >= 0) {
                    cout << "Max value: " << getMax() << "\n";
                } else {
                    cout << "Heap kosong\n";
                }
                break;

            case 4: //change priority
                cout << "Masukkan index dan new priority: ";
                cin >> index >> value;
                if (index <= heapSize) {
                    changePriority(index, value);
                } else {
                    cout << "Invalid index\n";
                }
                break;

            case 5: //remove
                cout << "Masukkan index yang akan dihapus: ";
                cin >> index;
                if (index <= heapSize) {
                    remove(index);
                } else {
                    cout << "Invalid index\n";
                }
                break;

            case 6: //display
                display();
                break;

            case 0: //exit
                break;

            default:
                cout << "Input yang anda masukkan tidak sesuai\n";
        }
    } while (choice != 0);

    return 0;
}
```
#### Output:
- Insert
![insert](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/e4396b82-e4e8-4b9d-86cc-f7442829ea4d)

- Extract Max
![extractmax](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/8effb285-a31a-450b-a107-9e46d65d5b79)

- Get Max
![getmax](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/94f4e14a-0477-4dc4-8585-0fc164cb1aa0)

- Change priority
![changepriority](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/209d6a18-5ea3-43ab-ad33-d323adc0b23f)

- Remove
![remove](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/2d35b441-3622-4250-bec7-9c60f82ee63c)

- Display
![display](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/ad83ea84-e58b-4a59-85de-9fae33b44454)

Kode di atas digunakan untuk mengimplementasikan heap dan priority queue seperti pada guided. Fungsi `parent`, `leftChild`, dan `rightChild` digunakan untuk menghitung indeks dari elemen induk, anak kiri, dan anak kanan. Fungsi `shiftUp` dan `shiftDown` memastikan properti heap tetap terjaga dengan menggerakkan elemen ke atas atau ke bawah sampai posisinya sesuai. Fungsi `insert` menambahkan elemen baru ke dalam heap, sementara `extractMax` mengambil dan menghapus elemen maksimum dari heap, serta memperbaiki struktur heap. Fungsi `changePriority` mengubah prioritas elemen tertentu dan menyesuaikan posisinya dalam heap. Fungsi `getMax` mengembalikan elemen maksimum tanpa menghapusnya, dan `remove` menghapus elemen pada indeks tertentu. Fungsi `display` menampilkan seluruh elemen heap saat ini.

Dalam fungsi `main`, terdapat menu yang memungkinkan pengguna melakukan berbagai operasi pada heap seperti memasukkan elemen baru `insert`, mengambil elemen maksimum `extractMax`, mendapatkan elemen maksimum tanpa menghapusnya `getMax`, mengubah prioritas elemen `changePriority`, menghapus elemen `remove`, dan menampilkan isi heap `display`. Pengguna memilih operasi yang diinginkan melalui input, dan program akan menjalankan fungsi yang sesuai berdasarkan pilihan tersebut.

#### Full code Screenshot:
![fullcode](https://github.com/agungibr/Struktur-Data-Assignment/assets/91455543/a76c8c44-ccec-494e-bf5f-afb9ed3b32c4)


## Kesimpulan
Kesimpulan pada guided yaitu kita belajar mengenai priority queue dan heap. Priority queue adalah jenis queue yang mengatur elemen berdasarkan nilai prioritasnya. Elemen dengan nilai prioritas lebih tinggi umumnya akan diambil sebelum elemen dengan nilai prioritas lebih rendah. Lalu untuk heap dalam struktur data adalah struktur berbasis pohon biner (binary tree) dengan aturan tertentu. Heap memiliki kelebihan dalam hal kecepatan operasi. Menambah atau menghapus elemen dalam heap hanya membutuhkan waktu O(log N), sedangkan mencari elemen minimum/maksimum hanya membutuhkan waktu konstan O(1).

Lalu untuk unguided kita belajar untuk memodifikasi guided yang mana heap di konstruksikan secara manual oleh user.

## Referensi
[1] Goodrich, Tamassia, Mount. Data Structure and Algorithms in C++, Wiley, 2004.

[2] B. V. Cherkassky and A. V. Goldberg, Heap‐on‐Top Priority Queues, Tech. report 96‐4, NEC Research Institute, Princeton, NJ, 1996.