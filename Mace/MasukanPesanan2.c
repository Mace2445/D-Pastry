//fseek file sekuensial
#include <stdio.h>

int main() {
struct
{
    char bolu[10];
    int harga;
}b;

struct{
    char nama[50], userid[50], password[50],nomortelfon[50], bolu[9];
}a;

    FILE *data;
    int no_struct;
    long int offset_byte;
    char boluTambah[15], hargaTambah[15];
    data = fopen("Daftar Bolu.dat", "rb");
    int i, pesanan;

    FILE *bolu;
    bolu = fopen("Daftar Bolu.dat", "rb");

    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }

    fclose(bolu);

    printf("Silahkan masukkan nomor urutan yang ada pada menu: ");
    scanf("%d", &no_struct);
    	offset_byte = (no_struct - 1) * sizeof(b);
    	fseek(data, offset_byte, SEEK_SET);

    if (fread(&b, sizeof(b), 1, data) == 0)
    {
        printf("Menu yang dicari tidak dapat ditemukan pada b.\n");
    }
    else
    {
        printf("Menu\t: %s\n", b.bolu);
        printf("Harga\t: %d", b.harga);
        pesanan = no_struct;
        strcpy(boluTambah, b.bolu);
    }

    fclose(data);

    FILE *acc1;
    FILE *acc2;
    char gantiBolu[9];

    acc1 = fopen("Program Registrasi.dat", "rb");
    acc2 = fopen("Program Registrasi.dat", "wb");


    fclose(acc1);
    fclose(acc2);
    remove("Program Registrasi.dat");
    rename("Program Registrasi2.dat","Program Registrasi.dat");
    return 0;
}


