
#include <stdio.h>
#include <string.h>  

int main()
{
	struct
{
    char nama[50], userid[50], password[50],nomortelfon[50];
} a;
	char idlogin [100],passwordlogin [100];
	 int status = 1, salah = 1;


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
         break;
      }else{
         printf("Username dan Password tidak match\n");
         salah++;
         if(salah == 3){
            printf("Akses ditolak\n");
         }
      }
      status++;
   }
    fclose(registrasi);
   return 0;
}
