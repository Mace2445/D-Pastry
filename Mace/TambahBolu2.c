//Program writing dan reading biner untuk pendataan pesanan
#include <stdio.h>

void readBolu();

struct
{
    char bolu[10];
    int harga;
} b;
int i, n;
void main()
{
    FILE *pesanan;
    pesanan = fopen("Daftar Bolu.dat", "wb"); //(b). Tentukan modenya
    printf("Banyak pesanan : ");
    scanf("%d", &n);
    getchar();
    for (i = 1; i <= n; i++)
    {
        printf("Silahkan masukkan nama bolu yang ingin ditambah ke dalam daftar: ");
        gets(b.bolu);
        fwrite(&b, sizeof(b), 1, pesanan); //Tentukan (B). sintaks  dan (C). lengkapi
    }
    fclose(pesanan); //(D). Lengkapi sintaksnya

    readBolu();
}

void readBolu() {
    int i;
    FILE *bolu;
    bolu = fopen("Daftar Bolu.dat", "rb");

    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }

    fclose(bolu);
}
