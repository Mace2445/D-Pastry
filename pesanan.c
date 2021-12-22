#include <stdio.h>
#include <string.h>  

int main()
{
	struct
{
    char nama[50], userid[50], password[50],nomortelfon[50];
} a;
	 int n, i;

FILE *pesanan;
    pesanan = fopen("Pesanan.dat", "rb");
	printf("Menu Pesan Bolu\n");
    printf("1. Bolu Kotak\n");
    printf("2. Bolu tabung\n");
    printf("3. Bolu limas segitiga\n\n");
    printf("Pilih pesanan : \n");
    scanf("%d", &n);
    getchar();
    for (i = 1; i <= n; i++)
    {
      switch (n)
{
case 1:printf("Anda Memilih Bolu kotak\n");
	printf("1. menambah pesanan\n");
	printf("2. membatalkan pesanan\n");
	printf("apa yang adna lakukan selanjutnya\n");
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
    {
      switch (n)
{
	case 1: 
    pesanan = fopen("Pesanan.dat", "ab");
    printf("pesanan ditambahkan");
	fwrite (&a, sizeof (a), 1, pesanan);
	break;  	
case 2:printf("Bolu tabung");break;
case 3:printf("Bolu limas segitiga");break;
}
getchar();
fwrite (&a, sizeof (a), 1, pesanan);
}
    fclose(pesanan);
    

    return 0;
    
}
}
}
