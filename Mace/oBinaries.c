#include <stdio.h>
#include <string.h>

struct admin {
    char nama[20], id[20], pass[20], telp[20];
}a[20];

struct reguler {
    char nama[20], id[20], pass[20], telp[20];
}r[20];

struct premium {
    char nama[20], id[20], pass[20], telp[20];
    int vouch;
}p[20];

void registerp(int i);
void login();

char bolu1[20]= "kotak", bolu2[20] = "bulat", bolu3[20] = "Kubus", bolu4[20] = "Lingkaran", bolu5[20] = "Piramida";
int z=0;

void main() {
    char entry[10];

    system ("cls");
    printf("Register/ Login: ");
    gets(entry);
    if(strcmp(entry,"Register")==0) registerp(z);
    else login();

}


void registerp(int i) {
    char nama[20], telp[20], id[20], pass[20];
    int tipe, vouch;

    system ("cls");

    printf("Masukkan tipe akun yang diinginkan: \n1. Admin \n2. Reguler \n3. Premium");
    scanf("%d", &tipe); getchar();

    switch(tipe) {
        case 1: FILE *registrasi;
                registrasi = fopen("Program Registrasi.dat", "ab");

                printf("Masukkan nama: "); // help
                gets(a.nama);
                printf("Masukkan nomor telepon: ");
                gets(a.telp);
                printf("Masukkan id: ");
                gets(a.id);
                printf("Masukkan password: ");
                gets(a.pass);
                fwrite(&a, sizeof (a), 1, registrasi);

                fclose(registrasi);
                break;

        case 2: printf("Masukkan nama: "); // help
                gets(r[z].nama);
                printf("Masukkan nomor telepon: ");
                gets(r[z].telp);
                printf("Masukkan id: ");
                gets(r[z].id);
                printf("Masukkan password: ");
                gets(r[z].pass);
                z++;
                break;

        case 3 : printf("Masukkan nama: "); // help
                gets(p[z].nama);
                printf("Masukkan nomor telepon: ");
                gets(r[z].telp);
                printf("Masukkan id: ");
                gets(p[z].id);
                printf("Masukkan password: ");
                gets(p[z].pass);
                z++;
                break;
    }
    main();
}


void login() {
    int tipe;
    char id[20], pass[20];

    system ("cls");
    printf("Login\n\n");
    printf("Masukkan id: ");
    gets(id);
    printf("Masukkan password: ");
    gets(pass);

    for(int i=0;i<20;i++) {
        if(strcmp(id, a[i].id)==0 && strcmp(pass, a[i].pass)==0) {
            tipe = 1;
            }

        else if(strcmp(id, r[i].id)==0 && strcmp(pass, r[i].pass)==0) {
            printf("Selamat datang reguler!");
            tipe = 2;
            }

        else if(strcmp(id, p[i].id)==0 && strcmp(pass, p[i].pass)==0) {
            printf("Selamat datang premium!");
            tipe = 3;
            }
    }

    switch(tipe) {
        case 1: admin();
                break;

        case 2: //reguler();
                break;

        case 3: //premium();
                break;

        default: printf("\nID/Password salah atau akun belum terdaftar");
                 break;
    }
    }


    void admin() {
        int aksi;

        typedef struct admin node;
        printf("Selamat datang Admin!\n");
        printf("Akun admin: \n");

        node temp;
       /* for (int i=0;i>=0;i++)
                for (int j=1;j<=i;j++) {
                    if (strlen(a[j-1].nama) > strlen(a[j].nama)) {
                        temp=a[j-1];
                        a[j-1]=a[j];
                        a[j]=temp;
                    }
                }*/
        for(int i=0;i<20;i++) {
        printf("%d. %s\n", i+1, a[i].nama);
        }


        printf("Akun reguler: \n");
        for(int i=0;i<20;i++) {
            printf("%d. %s\n", i+1, r[i].nama);
        }

        printf("Akun premium: \n");
        for(int i=0;i<20;i++) {
            printf("%d. %s\n", i+1, p[i].nama);
        }

        printf("Menu aksi: 1. Tambah jenis kue\n 2. Tambah Kota\n 3. Kasih voucher\n 4. Hapus akun");
        scanf("%d", &aksi); getchar();

        int gantiBolu;
        char namaBolu[20];

        switch(aksi) {
        case 1: printf("Daftar bolu: \n1. %s \n2. %s \n3. %s \n4. %s \n5. %s \n", bolu1, bolu2, bolu3, bolu4, bolu5);
                printf("Silahkan pilih bolu yang ingin diganti: ");
                scanf("%d", &gantiBolu); getchar();
                printf("\nSilahkan masukkan nama bolu: ");
                gets(namaBolu);
                switch(gantiBolu) {
                case 1: strcpy(bolu1, gantiBolu);
                break;

                case 2: gets(bolu1);
                break;

                case 3: bolu3[20] = namaBolu[20];
                break;

                case 4: bolu5[20] = namaBolu[20];
                break;
                }
                printf("Daftar bolu: \n1. %s \n2. %s \n3. %s \n4. %s \n5. %s \n", bolu1, bolu2, bolu3, bolu4, bolu5);

        }
    }
