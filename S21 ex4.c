#include <stdio.h>
#include <stdlib.h>

int main() {
 
    FILE *file;
    char chuoi[256];

    file = fopen("bt01.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt01.txt de doc!\n");
        return 1;
    }

    if (fgets(chuoi, sizeof(chuoi), file) != NULL) {
        printf("Dong dau tien trong file la: %s\n", chuoi);
    } else {
        printf("File rong hoac khong doc duoc!\n");
    }

    fclose(file);

    return 0;
}

