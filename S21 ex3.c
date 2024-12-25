#include <stdio.h>
#include <stdlib.h>

int main() {
  
    FILE *file;
    char chuoi[256];

    file = fopen("bt01.txt", "a");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de ghi them!\n");
        return 1;
    }

    printf("Nhap vao mot chuoi de ghi them vao file: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    fprintf(file, "%s", chuoi);

    fclose(file);

    printf("Chuoi da duoc ghi them vao file bt01.txt thanh cong!\n");

    return 0;
}

