#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main() { //main program
	int length, op, a, i; //mendeklarasikan variabel
	float average = 0, minimum = 99999, maximum = 0;

	cout << "Input jumlah array: "; //menginputkan panjang array
	cin >> length;
	int array[length];

	cout << "Input " << length << " angka kedalam array" << endl; //menginputkan angka kedalam elemen
	for (i = 0; i < length; ++i) { //looping menginputkan angka ke elemen sesuai jumlah array
        cout << "Array[" << i << "]: ";
        cin >> array[i];
    }

    for (i = 0; i < length; ++i) { //mencari nilai maximum
    	if (array[i] > maximum) { //jika nilai array lebih kecil dari variabel maximum
    		maximum = array[i]; //maka nilai maximum diubah menjadi nilai array
    	}
    }

    for (i = 0; i < length; ++i) { //mencari nilai minimum
    	if (array[i] < minimum) { //jika nilai array lebih besar dari variabel minimum
    		minimum = array[i]; //maka nilai minimum diubah menjadi nilai array
    	}
    }

    for (i = 0; i < length; ++i) { //mencari rata-rata
    	average += array[i]; //menjumlahkan seluruh elemen
    }
    float summary = average / length; //mencari rata-rata

    do //looping menu
    {
    	cout << "\n===== MENU =====" << endl;
        cout << "1. Nilai Maksimum" << endl;
        cout << "2. Nilai Minimum" << endl;
        cout << "3. Nilai Rata-rata" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> op;

        switch(op)
        {
        case 1: //jika memilih 1 maka akan mencari nilai maksimum
        	cout << "\nNilai Maksimum: " << maximum << endl;
        	break;
        case 2: //jika memilih 2 maka akan mencari nilai minimum
        	cout << "\nNilai Minimum: " << minimum << endl;
            break;
        case 3: //jika memilih angka 3 maka akan mencari nilai rata-rata
        	cout << "\nNilai Rata-rata: " << summary << endl;
            break;
        case 0: //jika ingin keluar dari looping maka bisa menginputkan angka 0
        	cout << "\nThank you for using this program. Goodbye!" << endl;
            break;
        default: //error message jika menginputkan selain angka 1, 2, 3, dan 0
    		cout << "\nInvalid input. Please enter either '1', '2', '3', or '0'." << endl;
    		break;
        }
    } while (op != 0); //jika user menginputkan angka selain 0 maka program otomatis akan mengulang hingga user menginputkan angka 0 untuk mengakhiri loop

    return 0;
}