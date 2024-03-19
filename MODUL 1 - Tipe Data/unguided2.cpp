#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

struct figure { //membuat struct figure
	string name; //berisi variable name yang bertipe data string
	int age; //dan variable age yang bertipe data int

};

class character { //membuat class character
	public:
		string species; //berisi variable species yang bertipe data string
		string citizenship; //variable citizenship yang bertipe data string
		string pets; //variable pets yang bertipe data string
};

int main() { //program utama atau main program
	struct figure one; //memanggil struct figure yang sudah dibuat diatas

	//memasukan data ke dalam struct
	one.name = "Patrick Star"; 
	one.age = 18;

	//menampilkan data struct yang sudah masukan tadi
	cout << "=====STRUCT=====" << endl;
	cout << "Name: " << one.name << endl;
	cout << "Age: " << one.age << endl;

	//memanggil class character
	character two;

	//memasukan data ke dalam class
	two.species = "Starfish";
	two.citizenship = "Bikini Bottom";
	two.pets = "Rocky, Ouchie, Tinkle, Fabio";

	//menampilkan data class yang sudah dimasukkan
	cout << "=====CLASS=====" << endl;
	cout << "Species: " << two.species << endl;
	cout << "Citizenship: " << two.citizenship << endl;
	cout << "Pets: " << two.pets << endl;

	return 0;
}