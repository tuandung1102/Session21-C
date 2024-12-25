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

    return 0;
}

