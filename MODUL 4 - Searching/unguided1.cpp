#include <iostream> //input preprocessor directive
#include <string>  
#include <sstream> //untuk memanipulasi string data

using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

void selection_sort(string arr[], int n) { //fungsi selection sort
    for(int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int binarySearchString(string arr[], string x, int n) { //fungsi binary search
    int lower = 0;
    int upper = n - 1;
    while (lower <= upper) {
        int mid = lower + (upper - lower) / 2;
        if (x == arr[mid])
            return mid;
        if (x > arr[mid])
            lower = mid + 1;
        else
            upper = mid - 1;
    }
    return -1;
}

int main() { //main program
    string input; //input kalimat
    cout << "Masukkan kalimat: ";

    getline(cin, input); //membaca inputan dari user

    stringstream ss(input); //menggunakan stringstream untuk memisahkan kalimat ke kata
    string word;
    int n = 0;  //menghitung jumlah kata dalam kalimat
    while (ss >> word) {
        n++;
    }

    string arr[n]; //membuat array berdasarkan jumlah kata dalam kalimat

    ss.clear(); //reset stringstream
    ss.str(input);
    for (int i = 0; i < n; i++) {
        ss >> arr[i];
    }

    // Sort the array using selection sort
    selection_sort(arr, n); //sorting array menggunakan selection sort

    // Display the sorted array
    cout << "\nData diurutkan:" << endl; //menampilkan hasil sorting array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    string search_word; //mencari kata yang dalam kalimat yang sudah diinputkan
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> search_word;

    int result = binarySearchString(arr, search_word, n);
    if (result == -1) 
        cout << "\nData tidak ditemukan" << endl;
    else
        cout << "\nData ditemukan pada index ke " << result << endl;

    return 0;
}
