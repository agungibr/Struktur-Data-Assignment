#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

//function menampilkan simpul
void tampilGraph_2311110067(const vector<string>& simpul, const vector<vector<int>>& busur) {
    cout << setw(10) << " ";
    for (const auto& s : simpul) {
        cout << setw(10) << s;
    }
    cout << endl;

    // Print rows
    for (int i = 0; i < simpul.size(); i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < simpul.size(); j++) {
            cout << setw(10) << busur[i][j];
        }
        cout << endl;
    }
}

int main() {
    int jumlahSimpul; //tambah simpul
    cout << "Silakan masukkan jumlah simpul : ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    vector<vector<int>> busur(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    cout << "Silakan masukkan nama simpul:" << endl; //tambah nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> simpul[i];
    }

    cout << "Silakan masukkan bobot antar simpul:" << endl; //tambah bobot antar simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << " --> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    cout << endl << "Graf yang telah dimasukkan:" << endl;
    tampilGraph_2311110067(simpul, busur);

    return 0;
}
