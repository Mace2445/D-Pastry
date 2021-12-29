
#include <stdio.h>
#include <string.h>


void main() {
    struct{
    char bolu[10];
    int harga;
}b;

    FILE *bolu;
    bolu = fopen("daftarBolu.dat", "rb");
    int i, pesan, offset_byte;
    char boluTambah[10];

    //daftar bolu
    printf("Silahkan pilih kue yang ingin dimasukkan keranjang: \n");
    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }

    //pilih bolu yang ingin dipesan
    scanf("%s", &pesan);
    offset_byte = (pesan - 1) * sizeof(b);
    fseek(bolu, offset_byte, SEEK_SET);


    if (fread(&b, sizeof (b), 1, bolu) == 0){
        printf("Kue yang dicari tidak dapat ditemukan pada daftar.\n");
        } else {

            printf("%s", boluTambah);
            printf("Harga\t: %d", b.harga);
            strcpy(boluTambah, b.bolu);
            }

    fclose(bolu);


    printf("Pesanan berhasil disimpan!");
    for(i=0; i<10; i++) {

    }
}
