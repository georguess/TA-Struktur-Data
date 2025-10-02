#include <iostream>
using namespace std;

void tukar(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int jumlah_npm;
    long long npm[100];

    cout << "Masukkan jumlah NPM yang akan diurutkan: ";
    cin >> jumlah_npm;

    cout << "\nMasukkan " << jumlah_npm << " NPM (dipisah spasi atau enter):\n";
    for (int i = 0; i < jumlah_npm; i++) {
        cin >> npm[i];
    }

    for (int i = 0; i < jumlah_npm - 1; i++) {
        int posisi_min = i;
        
        for (int j = i + 1; j < jumlah_npm; j++) {
            if (npm[j] < npm[posisi_min]) {
                posisi_min = j;
            }
        }
        
        tukar(&npm[i], &npm[posisi_min]);
    }

    cout << "\nNPM setelah diurutkan (Selection Sort):\n";
    for (int i = 0; i < jumlah_npm; i++) {
        cout << npm[i] << " ";
    }
    cout << endl;

    return 0;
}