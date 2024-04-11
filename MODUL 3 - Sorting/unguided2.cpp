#include <iostream> //input preprocessor directive
#include <cstring> //include the C Standard Library header file
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

void BubbleSort (char arr[][5], int n) {
	char temp[5]; //temporary veriable

	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n-1-i; j++) {
			if (strcmp (arr[j], arr[j + 1]) > 0) {
				//swap string menggunakan strcmp
				strcpy (temp, arr[j]); //copy arr[j] ke variable temp
				strcpy (arr[j], arr[j + 1]); //copy arr[j + 1] ke arr[j]
				strcpy (arr[j + 1], temp); //copy temp ke arr[j + 1]
			}
		}
	}
}

int main() { //main program
	char arr[][5] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};
	int n = sizeof(arr) / sizeof (arr[0]);

	//proses sorting menggunakan variable yang sudah dibuat
	BubbleSort(arr, n);

	//print hasil
	printf("Urutan nama sesuai alfabet: ");
	for (int i = 0; i < n; i++)
        printf("\n Urutan %d adalah %s", i + 1, arr[i]);

	return 0;
}