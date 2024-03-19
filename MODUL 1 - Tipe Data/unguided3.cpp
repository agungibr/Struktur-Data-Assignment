#include <iostream> //input preprocessor directive
#include <map> //input map
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main() { //main program 
	map <int, string> character; //membuat map dengan key int dan bertipe data string

	//menginputkan karakter
	character[0] = "Spongebob Squarepants";
	character[1] = "Patrick Star";
	character[2] = "Sandy Cheeks";
	character[3] = "Squidward Tentacles";
	character[4] = "Mr. Krabs";

	//menampilkan karakter yang sudah dibuat
	cout << "==========CHARACTER LIST==========" << endl;
	cout << "Karakter pertama : " << character[0] << endl;
	cout << "Karakter kedua : " << character[1] << endl;
	cout << "Karakter ketiga : " << character[2] << endl;
	cout << "Karakter keempat : " << character[3] << endl;
	cout << "Karakter kelima : " << character[4] << endl;

	return 0;
}