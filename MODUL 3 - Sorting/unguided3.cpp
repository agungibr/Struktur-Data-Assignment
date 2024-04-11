#include <iostream>
using namespace std;

void ASCSort (char arr[], int n) {
  char key;
  int j;

  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void DESCSort (char arr[], int n) {
  char key;
  int j;

  for (int i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] < key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

void printArray (char arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int n;

  cout << "Input (n): ";
  cin >> n;
  char data[n];

  for (int i = 0; i < n; i++) {
    cout << "Karakter ke-" << i + 1 << ": ";
    cin >> data[i];
  }

  cout << "\nUrutan karakter sebelum sorting: " << endl;
  printArray (data, n);

  ASCSort (data, n);

  cout << "\nUrutan karakter setelah ascending sort: " << endl;
  printArray (data, n);

  DESCSort (data, n);

  cout << "\nUrutan karakter setelah descending sort: " << endl;
  printArray (data, n);  
}