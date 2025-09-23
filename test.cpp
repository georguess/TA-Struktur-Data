#include <iostream>
using namespace std;

int main() 
{
    float alas, tinggi, hasil;
    cout << "=== Kalkulator segitiga ===" << endl;
    cout << "Masukkan angka pertama sebagai alas: ";
    cin >> alas;
    cout << "Masukkan angka kedua sebagai tinggi: ";
    cin >> tinggi;
    hasil = ( alas * tinggi ) / 2 ;
    cout << "Hasil luas segitiga: " << hasil << endl;
    return 0;
}
