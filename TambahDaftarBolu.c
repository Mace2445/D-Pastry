#include <stdio.h>
#include <string.h>

struct{
    char bolu[10];
    int harga;
}b;

void readBolu();

void main() {
    FILE *fb;
    fb = fopen("daftarBolu.dat", "ab");

    int i, n;

    printf("Masukkan jumlah kue yang ingin ditambahkan: ");
    scanf("%d", &n); getchar();

    for(int i=0;i<n;i++) {
    printf("Silahkan masukkan nama bolu yang ingin ditambah ke dalam daftar: ");
    gets(b.bolu);
    fwrite (&b, sizeof (b), 1, fb);
    }

fclose(fb);

printf("\nPenambahan berhasil! \nDaftar kue: \n");

readBolu();
}

void readBolu() {
    int i;
    FILE *bolu;
    bolu = fopen("daftarBolu.dat", "rb");

    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }

    fclose(bolu);
}
