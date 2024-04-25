#include <iostream> //input preprocessor directive

using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

bool vokal (char c) { //function untuk menentukan apakah karakter merupakan huruf vokal or no
	c = toupper(c); //convert char ke uppercase jika kata dalam lowercase

	return c=='A'||c=='E'||c=='I'||c=='O' ||c=='U'; //return true jika kondisi sesuai
}

int main() { //main program
	char str[100] = "pneumonoultramicroscopicsilicovolcanoconiosis";
    int vokals = 0;

    cout << "Kata dalam array: " << str << endl; 

    for(int i = 0; str[i]; i++) //looping untuk menghitung karakter vokal  
    {
        if(vokal(str[i]))
		    vokals++;
    }

    cout << "Total huruf vokal: " << vokals;
    
    return 0;
}