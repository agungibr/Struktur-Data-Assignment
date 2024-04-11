#include <iostream>
using namespace std;

void selection (float arr[], float n) {
	int i, j, small;

	for (i = 0; i < n-1; i++) {
		small = i;

		for (j = i+1; j < n; j++)
		if (arr[j] > arr[small])
			small = j;

		float temp = arr[small];
		arr[small] = arr[i];
		arr[i] = temp;
	}
}

void printArr (float a[], float n) {
	int i;

	for (i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main() {
	float a[] = {3.8, 2.9, 3.3, 4.0, 2.4};
	float n = sizeof(a) / sizeof(a[0]);

	cout << "Indeks Prestasi Mahasiswa sebelum di sorting: " << endl;
	printArr (a, n);
	cout << endl << endl;

	selection (a, n);
	
	cout << "Indeks Prestasi Mahasiswa setelah di sorting: " << endl;
	printArr(a, n);

	return 0;
}