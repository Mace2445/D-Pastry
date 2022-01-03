#include <stdio.h>
#include <string.h>

struct
{
    char nama[50], userid[50], password[50],nomortelfon[50],tipeAkun[10];
} a;

void login();
void regis();
void TambahDaftarBolu();
void tambahvoucher();
void readBolu();
void apusdata();
void tambahkota();
void readkota();
void cari();
void reguler();
void simpanPesanan();
int benar;
int admin;


void main() {
    char entry[10];
    int pilih;

    system ("cls");
    printf("Register/ Login: ");
    gets(entry);
    if(strcmp(entry,"Register")==0) {regis(); main();}
    else login();

    if (benar==1) {
            system("cls");
            printf("\nAnda Masuk sebagai admin\n");
            printf("Pilih aksi yang akan dilakukan: \n1. Tambah kue \n2. Hapus akun\n 3.tambah kota\n 4. cari\n 5.tambah voucher\n");
            scanf("%d", &pilih);
            switch(pilih) {
            case 1: TambahDaftarBolu();
                    break;

            case 2: apusdata();
                    break;
                    
            case 3: tambahkota();
                    break;
            
            case 4: cari();
                    break;
                    
            case 5: tambahvoucher();
                    break;
                    
            }
        }
    if(admin==1)
    {
    	system("cls");
        void reguler();

        
   }
}


void login() {

	char idlogin [100],passwordlogin [100];
	 int status = 1, salah = 0;


 FILE *registrasi;
    registrasi = fopen("data user premium.dat", "rb");
    registrasi = fopen("data user reguler.dat", "rb");

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
      }
 if (strcmp (a.userid,"admin")==0 && strcmp(a.password, "password")==0)
 {
  printf("Akses diterima. Selamat Datang\n");
  admin = 1;
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

void reguler(){
	
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
    data = fopen("daftarbolu.dat", "rb");
    int i, pesanan;

    FILE *bolu;
    bolu = fopen("daftarBolu.dat", "rb");

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
    void simpanPesanan(){
    	
    	
	}

    
}



void regis(){
     int n, i;
 FILE *registrasi;
    registrasi = fopen("data user reguler.dat", "rb");
{ 
printf("1.Reguler\n");
printf("2.Premium\n");
printf("Apakah anda ingin buat account reguler / premium : ?\n");
scanf("%d",&i);
for(n=1;n<=i;n++);
{
switch (i)
{
    case 1:
    registrasi = fopen("data user reguler.dat", "wb");
    printf("\tNama Lengkap\t\t: ");
        gets(a.nama);
        printf("\tUser ID Account\t: ");
        gets(a.userid);
        printf("\tPassword Account\t: ");
        gets(a.password);
        printf("\tNomor Telfon Pengguna\t: ");
        gets(a.nomortelfon);
        printf("\nSelamat anda berhasil registrasi\n");
        printf("tekan apa saja untuk lanjut");
        getchar();
        fwrite (&a, sizeof (a), 1,registrasi); 
    fclose(registrasi); 
    break ;
    case 2:
    registrasi = fopen("data user premium.dat", "wb"); 
    printf("\tNama Lengkap\t\t: ");
        gets(a.nama);
        printf("\tUser ID Account\t\t: ");
        gets(a.userid);
        printf("\tPassword Account\t: ");
        gets(a.password);
        printf("\tNomor Telfon Pengguna\t: ");
        gets(a.nomortelfon);
        printf("\nSelamat anda berhasil registrasi\n");
        printf("tekan apa saja untuk lanjut");
        getchar();
        fwrite (&a, sizeof (a), 1,registrasi); 
    fclose(registrasi); 
}
}
}
}


struct{
    char bolu[20],kota[20];
    int harga;
}b;

void TambahDaftarBolu() {
    FILE *fb;
    fb = fopen("daftarBolu.dat", "ab");

    int i, n;

    printf("Masukkan jumlah kue yang ingin ditambahkan: ");
    scanf("%d", &n); getchar();

    for(i=0;i<n;i++) {
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
printf("pesanan telah dihapus");
}


struct{
    char kota[10];
    int harga;
}p;

void tambahkota(){
	    FILE *fk;
    fk = fopen("daftarkota.dat", "ab");

    int i, n;
    
    printf("Masukkan jumlah kue yang ingin ditambahkan: ");
    scanf("%d", &n); getchar();

    for(i=0;i<n;i++) {
    printf("Silahkan masukkan nama kota yang ingin ditambah ke dalam daftar: ");
    gets(p.kota);
    fwrite (&p, sizeof (p), 1, fk);
    }

fclose(fk);

printf("\nPenambahan berhasil! \nDaftar kota: \n");

readkota();
}

void readkota() {
    int i;
    FILE *fk;
    fk = fopen("daftarkota.dat", "rb");

    while(fread(&p,sizeof(p),1,fk)==1){
        i++;
        printf("%d. %s\n", i);
    }

    fclose(fk);
}

void cari(){
	FILE *f_struktur;
int no_struct;
long int offset_byte;
void rewind(FILE *stream);

struct {
char Menu [30];
double Harga;
} daftar;
f_struktur = fopen("Daftar Harga.dat", "rb");
printf("Silahkan masukkan nomor urutan yang ada pada menu: ");
scanf("%d", &no_struct);
offset_byte = (no_struct - 1) * sizeof(daftar);
fseek(f_struktur, offset_byte, SEEK_SET);
if (fread(&daftar, sizeof (daftar), 1, f_struktur) == 0){
printf("Menu yang dicari tidak dapat ditemukan pada daftar.\n");
} else {
printf("Menu : %s\n",daftar.Menu);
printf("Harga: %lf\n",daftar.Harga);
}
fclose(f_struktur);
}

void tambahvoucher(){
	printf("tambahvoucher");
}





	

