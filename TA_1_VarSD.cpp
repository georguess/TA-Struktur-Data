#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

// Konstanta 
const int JUMLAH_MAHASISWA = 5;
const int JUMLAH_MATKUL = 3;

// Deklarasi Array
string namaMahasiswa[JUMLAH_MAHASISWA];
int nilai[JUMLAH_MAHASISWA][JUMLAH_MATKUL];
string namaMatkul[JUMLAH_MATKUL] = {"Struktur Data", "Rekayasa Perangkat Lunak", "Sistem Operasi"};


int jumlahData = 0;

//  Menu
void tampilkanMenu() {
    cout << "\n===== SISTEM NILAI MAHASISWA =====\n";
    cout << "1. Masukkan Data Nilai Mahasiswa\n";
    cout << "2. Tampilkan Data Nilai Mahasiswa\n";
    cout << "3. Keluar\n";
    cout << "====================================\n";
    cout << "Pilih menu: ";
}

int main() {
    int pilihan;

    while (true) {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (jumlahData >= JUMLAH_MAHASISWA) {
                    cout << "Penyimpanan data sudah penuh!" << endl;
                    break;
                }

                cout << "\n--- Input Data Mahasiswa ke-" << jumlahData + 1 << " ---\n";

                cin.ignore(); 
                
                cout << "Masukkan Nama Mahasiswa: ";
                getline(cin, namaMahasiswa[jumlahData]);

                for (int i = 0; i < JUMLAH_MATKUL; ++i) {
                    cout << "Masukkan nilai " << namaMatkul[i] << ": ";
                    cin >> nilai[jumlahData][i];
                }

                jumlahData++;
                cout << "\nData berhasil ditambahkan!" << endl;
                break;
            }
            case 2: {
                if (jumlahData == 0) {
                    cout << "\nBelum ada data yang dimasukkan." << endl;
                    break;
                }

                cout << "\n--- Data Nilai Mahasiswa ---\n";
                cout << left << setw(5) << "No." 
                     << setw(30) << "Nama Mahasiswa" 
                     << setw(25) << "Struktur Data" 
                     << setw(30) << "Rekayasa Perangkat Lunak" 
                     << setw(20) << "Sistem Operasi" << endl;
                cout << "------------------------------------------------------------------------------------------------------------------\n";

                for (int i = 0; i < jumlahData; ++i) {
                    cout << left << setw(5) << to_string(i + 1) + "." 
                         << setw(30) << namaMahasiswa[i] 
                         << setw(25) << nilai[i][0] 
                         << setw(30) << nilai[i][1] 
                         << setw(20) << nilai[i][2] << endl;
                }
                break;
            }
            case 3:
                cout << "\nProgram selesai." << endl;
                return 0;
            default:
                cout << "\nPilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    }

    return 0;
}