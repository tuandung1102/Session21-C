#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE *file1, *file2;
    char chuoi[256];

    file1 = fopen("bt01.txt", "r");
    if (file1 == NULL) {
        printf("Khong the mo file bt01.txt de doc!\n");
        return 1;
    }

    file2 = fopen("bt06.txt", "w");
    if (file2 == NULL) {
        printf("Khong the mo file bt06.txt de ghi!\n");
        fclose(file1);
        return 1;
    }

    while (fgets(chuoi, sizeof(chuoi), file1) != NULL) {
        fputs(chuoi, file2);
    }

    fclose(file1);
    fclose(file2);

    printf("Noi dung da duoc sao chep tu bt01.txt sang bt06.txt thanh cong!\n");

    return 0;
}

