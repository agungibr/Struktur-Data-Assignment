#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

void ASCSort (char arr[], int n) { //function ascending sort
  char key;
  int j;

  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    //compare elemen satu sama lain
    while (j >= 0 && arr[j] > key) { //">" for ascending
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void DESCSort (char arr[], int n) { //function descending sort
  char key;
  int j;

  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    //compare elemen satu sama lain
    while (j >= 0 && arr[j] < key) { //"<" for descending
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray (char arr[], int size) { //function untuk print array
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() { //main program
  int n;

  cout << "Input (n): "; //input panjang array
  cin >> n;
  char data[n];

  for (int i = 0; i < n; i++) { //input karakter sesuai panjang array
    cout << "Karakter ke-" << i + 1 << ": ";
    cin >> data[i];
  }

  //menampilkan karakter sebelum sorting
  cout << "\nUrutan karakter sebelum sorting: " << endl;
  printArray (data, n);

  //sorting data ascending menggunakan intersection sort
  ASCSort (data, n);

  //menampilkan karakter setelah ascending sort
  cout << "\nUrutan karakter setelah ascending sort: " << endl;
  printArray (data, n);

  //sorting data descending menggunakan intersection sort
  DESCSort (data, n);

  //menampilkan karakter setelah descending sort
  cout << "\nUrutan karakter setelah descending sort: " << endl;
  printArray (data, n);  
}