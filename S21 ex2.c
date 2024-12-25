#include <stdio.h>
#include <stdlib.h>

int main() {
  
    FILE *file;
    char chuoi[256];

    file = fopen("bt01.txt", "w");
    if (file == NULL) {
        printf("Khong the tao hoac mo file bt01.txt!\n");
        return 1;
    }

    printf("Nhap vao mot chuoi bat ki: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    fprintf(file, "%s", chuoi);

    fclose(file);

    printf("Chuoi da duoc ghi vao file bt01.txt thanh cong!\n");

    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de doc!\n");
        return 1;
    }

    char kyTuDau;
    kyTuDau = fgetc(file);

    if (kyTuDau != EOF) {
        printf("Ky tu dau tien trong file la: %c\n", kyTuDau);
    } else {
        printf("File rong hoac khong doc duoc!\n");
    }

    fclose(file);

    return 0;
}

