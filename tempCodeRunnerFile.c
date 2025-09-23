#include <stdio.h>

int main() {
    int nilai[5];
    int i;

    printf("Masukkan 5 nilai mahasiswa:\n");
    for(i=0; i<5; i++) {
        printf("Nilai ke-%d: ", i+1);
        scanf("%d", &nilai[i]);
    }

    printf("\nDaftar Nilai Mahasiswa:\n");
    for(i=0; i<5; i++) {
        printf("Nilai ke-%d = %d\n", i+1, nilai[i]);
    }

    return 0;
}
