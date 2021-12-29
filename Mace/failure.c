#include <stdio.h>
#include <string.h>

struct
{
    char nama[50], userid[50], password[50],nomortelfon[50],tipeAkun[10];
} a;

void login();
void regis();
void TambahDaftarBolu();
void readBolu();
void apusdata();
int benar;


void main() {
    char entry[10];
    int pilih;

    system ("cls");
    printf("Register/ Login: ");
    gets(entry);
    if(strcmp(entry,"Register")==0) {regis(); main();}
    else login();

    if (benar == 1) {
            system("cls");
            printf("Pilih aksi yang akan dilakukan: \n1. Tambah \n2. Hapus");
            scanf("%d", &pilih);
            switch(pilih) {
            case 1: TambahDaftarBolu();
                    break;

            case 2: apusdata();
                    break;
            }
    }


}

void login() {

	char idlogin [100],passwordlogin [100];
	 int status = 1, salah = 0;


 FILE *registrasi;
    registrasi = fopen("Program Registrasi.dat", "rb");

 while (status<4)	 {
 printf("===SELAMAT DATANG DI D'PASTRY SILAHKAN LOGIN\n");
 printf("   ID : ");
 gets(idlogin);
 printf("   Password : ");
 gets(passwordlogin);
 while(fread(&a,sizeof(a),1,registrasi)==1){
}


 if(strcmp (a.userid,idlogin)==0 && strcmp(a.password, passwordlogin)==0)
 {
  printf("Akses diterima. Selamat Datang\n");
  benar = 1;
         break;
      }else{
         printf("Username dan Password tidak match\n");
         salah++;
         benar = 0;
         if(salah == 3){
            printf("Akses ditolak\n");
            break;
         }
      }
   }
    fclose(registrasi);
}


void regis()
{
    FILE *registrasi;
    registrasi = fopen("Program Registrasi.dat", "wb");
    printf("Karena Anda belum memiliki akun silahkan registrasi dengan mengisi form dibawah ini\n");
        printf("\tNama Lengkap\t\t: ");
        gets(a.nama);
        printf("\tUser ID Account\t\t: ");
        gets(a.userid);
        printf("\tPassword Account\t: ");
        gets(a.password);
        printf("\tNomor Telfon Pengguna\t: ");
         gets(a.nomortelfon);
        getchar();
        fwrite (&a, sizeof (a), 1, registrasi);
    fclose(registrasi);
    printf("\nSelamat anda berhasil registrasi\n");
}

struct{
    char bolu[10];
    int harga;
}b;



void TambahDaftarBolu() {
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

struct{
    char bolu[10];
}daftar;

void apusdata(){
FILE *pesanan;
FILE *pesanan2;
char dicari[50];
struct {
char bolu[30];
} order;
pesanan = fopen("Pesanan.dat", "rb");
pesanan2 = fopen("Pesanan2.dat", "wb");
printf("Silahkan masukkan pesanan bolu yang ingin dihapus: "); gets(dicari);
while (fread(&daftar,sizeof (daftar),1, pesanan)==1){
if (strcmp(order.bolu, dicari)!=0){
fwrite(&order, sizeof(order), 1, pesanan2);
}
}

fclose(pesanan);
fclose(pesanan2);
remove("Pesanan.dat");
rename("Pesanan2.dat","Pesanan.dat");
}
