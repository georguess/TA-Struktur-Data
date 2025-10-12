#include <iostream>
using namespace std;
const int MAX = 100;
int st[MAX];
int topIdx = -1;
bool isEmpty();
bool isFull();
void push(int x);
void pop();
void display();
void peek();
int main()
{
    int pilih, val;
    do
    {
        cout << "\n=== STACK NILAI UJIAN MAHASISWA ===\n";
        cout << "1. Tambah Nilai (Push)\n2. Hapus Nilai Teratas (Pop)\n3. Lihat Nilai Teratas (Peek)\n4. Tampilkan Semua Nilai\n5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        if (pilih == 1)
        {
            cout << "Masukkan nilai ujian: ";
            cin >> val;
            push(val);
        }
        else if (pilih == 2)
            pop();
        else if (pilih == 3)
            peek();
        else if (pilih == 4)
            display();
    } while (pilih != 5);
    return 0;
}
bool isEmpty()
{
    return topIdx == -1;
}
bool isFull()
{
    return topIdx == MAX - 1;
}
void push(int x)
{
    if (isFull())
    {
        cout << "Stack penuh, tidak dapat menambah nilai baru.\n";
        return;
    }
    st[++topIdx] = x;
    cout << "Nilai " << x << " berhasil ditambahkan ke stack.\n";
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack kosong, tidak ada nilai yang dihapus.\n";
        return;
    }
    cout << "Nilai " << st[topIdx--] << " telah dihapus dari stack.\n";
}
void peek()
{
    if (isEmpty())
    {
        cout << "Stack kosong, tidak ada nilai untuk dilihat.\n";
        return;
    }
    cout << "Nilai teratas saat ini: " << st[topIdx] << '\n';
}
void display()
{
    if (isEmpty())
    {
        cout << "Stack kosong, belum ada nilai yang tersimpan.\n";
        return;
    }
    cout << "Daftar nilai ujian (atas ke bawah): ";
    for (int i = topIdx; i >= 0; --i)
    {
        cout << st[i] << " ";
    }
    cout << '\n';
}