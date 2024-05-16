#include <iostream>
#include <stack>

using namespace std;

bool palindrome(string kalimat) {
  for (int i = 0; i < kalimat.length(); i++) { //konversi kalimat ke uppercase
    kalimat[i] = tolower(kalimat[i]);
  }

  stack<char> s; //stack buat nyimpen character

  for (int i = 0; i < kalimat.length(); i++) { //push kalimat ke stack
    s.push(kalimat[i]);
  }

  for (int i = 0; i < kalimat.length() / 2; i++) { //membandingkan kalimat
    if (kalimat[i] != s.top()) {
      return false;
    }
    s.pop();
  }
  return true;
}

int main() { //main program
  string kalimat;

  do {
    cout << "\nMasukkan kalimat: "; //input kalimat
    getline(cin, kalimat);

    if (palindrome(kalimat)) { //memeriksa
      cout << "Kalimat " << kalimat << " merupakan palindrom" << endl;
    } else {
      cout << "Kalimat " << kalimat << " bukan palindrom" << endl;
    }
  } while (kalimat != "0");

  return 0;
}