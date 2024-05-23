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