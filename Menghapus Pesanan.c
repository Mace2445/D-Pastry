#include <stdio.h> 
#include <string.h> 
 
int apusdata(){ 
FILE *pesanan;
FILE *pesanan2;
char dicari[50];
struct { 
char bolu[30];
} order;
pesanan = fopen("Pesanan.dat", "rb");
pesanan2 = fopen("Pesanan2.dat", "wb");
printf("Silahkan masukkan pesanan bolu yang ingin dihapus: "); gets(dicari);
while (fread(&daftar,sizeof (daftar),1, f_struktur)==1){ 
if (strcmp(order.bolu, dicari)!=0){ 
fwrite(&order, sizeof(order), 1, pesanan2);
} 
} 
 
fclose(pesanan);
fclose(pesanan2);
remove("Pesanan.dat");
rename("Pesanan2.dat","Pesanan.dat");
return 0;
}
