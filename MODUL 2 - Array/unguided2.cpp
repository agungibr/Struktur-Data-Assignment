#include <iostream> //input preprocessor directive
using namespace std; //supaya tidak perlu menggunakan std:: disetiap input object or function

int main() //main program
{
    int x, y, z; //mendeklarasikan variabel x, y, z dengan tipe data integer
    
    cout << "Input jumlah matrix: "; //input panjang matrix
    cin >> x;
    cout << "Input jumlah baris: "; //input panjang baris
    cin >> y;
    cout << "Input jumlah kolom: "; //input panjang kolom
    cin >> z;
    cout << endl;
    
    int arr[x][y][z]; //mendeklarasikan array sesuai input

    for (int i = 0; i < x; i++) //looping input elemen
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Input Array[" << i << "][" << j << "][" << k << "] = "; //input nilai setiap elemen
                cin >> arr[i][j][k];
            }
        }
        cout << endl;
    }

    for (int i = 0; i < x; i++) //looping untuk menampilkan inputan array
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << "Data Array[" << i << "][" << j << "][" << k << "] = " << arr[i][j][k] << endl; //menampilkan inputan array
            }
        }
    }
    cout << endl;

    for (int i = 0; i < x; i++) //looping untuk menampilkan hasil array
    {
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                cout << arr[i][j][k] << " "; //menampilkan hasil array
            }
            cout << endl;
        }
        cout << endl;
    }
}