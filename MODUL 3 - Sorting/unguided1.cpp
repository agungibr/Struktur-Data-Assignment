#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

void selection (float arr[], float n) { //function untuk selection sort
	int i, j, small;

	for (i = 0; i < n-1; i++) {
		small = i; //minimum elemen di array yang belum di sorting

		for (j = i+1; j < n; j++)
		if (arr[j] > arr[small]) //karena descending maka menggunakan >
			small = j;

		//swap minimum elemen dengan elemen pertama
		float temp = arr[small];
		arr[small] = arr[i];
		arr[i] = temp;
	}
}

//function untuk mencetak array
void printArr (float a[], float n) {
	int i;

	for (i = 0; i < n; i++)
		cout << a[i] << " ";
}

int main() { //main program
	float a[] = {3.8, 2.9, 3.3, 4.0, 2.4};
	float n = sizeof(a) / sizeof(a[0]);

	//print before
	cout << "Indeks Prestasi Mahasiswa sebelum di sorting: " << endl;
	printArr (a, n);
	cout << endl << endl;

	//proses sorting dengan variable yang sudah dibuat
	selection (a, n);

	//print after
	cout << "Indeks Prestasi Mahasiswa setelah di sorting: " << endl;
	printArr(a, n);

	return 0;
}