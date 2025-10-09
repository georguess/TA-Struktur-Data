#include <iostream>
using namespace std;
int main()
{
    const int x = 15;
    int absen[x] = {3, 8, 1, 9, 0, 6, 7, 5, 2, 2, 1, 6, 2, 5, 12};
    int cariNomor;
    int i = 0;
    int counter = 0;
    cout << "Masukkan nomor absen yang ingin dicari : ";
    cin >> cariNomor;
    while (i < x)
    {
        if (absen[i] == cariNomor)
        {
            counter++;
        }
        i++;
    }
    if (counter > 0)
    {
        cout << "Nomor absen " << cariNomor << " ditemukan sebanyak " << counter << " kali." << endl;
    }
    else
    {
        cout << "Nomor absen " << cariNomor << " tidak ditemukan dalam daftar." << endl;
    }
    return 0;
}