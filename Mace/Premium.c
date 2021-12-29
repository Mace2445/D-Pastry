#include <stdio.h>
#include <string.h>

struct premium{
    char nama[50], userid[50], password[50],nomortelfon[50];
    int voucher;
}p;

struct daftarbolu{
    char bolu;
}b;


void main() {
    int i;
    FILE *bolu;
    bolu = fopen("daftarBolu.dat", "rb");

    while(fread(&b,sizeof(b),1,bolu)==1){
        i++;
        printf("%d. %s\n", i, b.bolu);
    }

    fclose(bolu);


fclose(bolu);
}
