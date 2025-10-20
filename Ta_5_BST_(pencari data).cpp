#include <iostream>
using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k): key(k), left(nullptr), right(nullptr) {}
};
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key) root->left = insertNode(root->left, key);
    else if (key > root->key) root->right = insertNode(root->right, key);
    return root;
}
bool searchNode(Node* root, int key) {
    if (!root) return false;
    if (root->key == key) return true;
    if (key < root->key) return searchNode(root->left, key);
    return searchNode(root->right, key);
}
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
void preorder(Node* root) {
    if (!root) return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}
int main() {
    Node* root = nullptr;
    int pilih, x;
    do {
        cout << "\n=== Implementasi BST Pencari Data ===\n";
        cout << "1. Insert\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        if (pilih == 1) {
            cout << "Masukkan nilai: ";
            cin >> x;
            root = insertNode(root, x);
        } else if (pilih == 2) {
            cout << "Cari nilai: ";
            cin >> x;
            cout << (searchNode(root, x) ? "Ditemukan\n" : "Tidak ditemukan\n");
        } else if (pilih == 3) {
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
        } else if (pilih == 4) {
            cout << "Preorder: ";
            preorder(root);
            cout << "\n";
        } else if (pilih == 5) {
            cout << "Postorder: ";
            postorder(root);
            cout << "\n";
        }
    } while (pilih != 6);
    return 0;
}