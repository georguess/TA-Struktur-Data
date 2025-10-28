#include <iostream>
using namespace std;
const int SIZE = 10;
struct Node {
    int idBarang;
    int stok;
    Node* next;
};
void initTable(Node* table[]) {
    for (int i = 0; i < SIZE; i++) table[i] = nullptr;
}
int hashFunction(int key) {
    return (key % SIZE + SIZE) % SIZE;
}
void tambahBarang(Node* table[], int idBarang, int stok) {
    int index = hashFunction(idBarang);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->idBarang == idBarang) {
            cur->stok += stok;
            return;
        }
        cur = cur->next;
    }
    Node* baru = new Node;
    baru->idBarang = idBarang;
    baru->stok = stok;
    baru->next = table[index];
    table[index] = baru;
}
Node* cariBarang(Node* table[], int idBarang) {
    int index = hashFunction(idBarang);
    Node* cur = table[index];
    while (cur != nullptr) {
        if (cur->idBarang == idBarang) return cur;
        cur = cur->next;
    }
    return nullptr;
}
void hapusBarang(Node* table[], int idBarang) {
    int index = hashFunction(idBarang);
    Node* cur = table[index];
    Node* prev = nullptr;
    while (cur != nullptr) {
        if (cur->idBarang == idBarang) {
            if (prev == nullptr) table[index] = cur->next;
            else prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
void tampilkanTabel(Node* table[]) {
    cout << "\nIsi Hash Table (Separate Chaining - Stok Barang):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << i << ": ";
        if (table[i] == nullptr) cout << "EMPTY\n";
        else {
            Node* tmp = table[i];
            while (tmp != nullptr) {
                cout << "(ID:" << tmp->idBarang << ",Stok:" << tmp->stok << ")";
                if (tmp->next != nullptr) cout << " -> ";
                tmp = tmp->next;
            }
            cout << "\n";
        }
    }
}
int main() {
    Node* table[SIZE];
    initTable(table);
    tambahBarang(table, 101, 50);
    tambahBarang(table, 111, 30);
    tambahBarang(table, 121, 20);
    tambahBarang(table, 202, 40);
    tampilkanTabel(table);
    Node* hasil = cariBarang(table, 111);
    if (hasil != nullptr) cout << "\nBarang dengan ID 111 ditemukan, stok = " << hasil->stok << "\n";
    else cout << "\nBarang dengan ID 111 tidak ditemukan\n";
    hapusBarang(table, 111);
    cout << "\nSetelah menghapus barang dengan ID 111:\n";
    tampilkanTabel(table);
    return 0;
}