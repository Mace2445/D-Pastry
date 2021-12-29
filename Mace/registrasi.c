#include <stdio.h>

struct
{
    char nama[50], userid[50], password[50],nomortelfon[50];
} a;

void main()
{
    FILE *registrasi;
    registrasi = fopen("Program Registrasi.dat", "ab");
    printf("Karena Anda belum memiliki akun silahkan registrasi dengan mengisi form dibawah ini\n");
        printf("\tNama Lengkap\t\t: ");
        gets(a.nama);
        printf("\tUser ID Account\t\t: ");
        gets(a.userid);
        printf("\tPassword Account\t: ");
        gets(a.password);
        printf("\tNomor Telfon Pengguna\t: ");
         gets(a.nomortelfon);
        fwrite (&a, sizeof (a), 1, registrasi);
    fclose(registrasi);
    printf("\nSelamat anda berhasil registrasi\n");
}
