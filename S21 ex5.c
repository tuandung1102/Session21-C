#include <stdio.h>
#include <stdlib.h>

int main() {
 
    FILE *file;
    char chuoi[256];
    int soDong;

    file = fopen("bt05.txt", "w");
    if (file == NULL) {
        printf("Kong the tao hoac mo file bt05.txt!\n");
        return 1;
    }

    printf("Nhap so dong: ");
    scanf("%d", &soDong);
    getchar(); 

    for (int i = 0; i < soDong; i++) {
        printf("Nhap noi dung dong %d: ", i + 1);
        fgets(chuoi, sizeof(chuoi), stdin);
        fprintf(file, "%s", chuoi);
    }

    fclose(file);

    file = fopen("bt05.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file bt05.txt de doc!\n");
        return 1;
    }

    printf("\nNoi dung trong file bt05.txt:\n");
    while (fgets(chuoi, sizeof(chuoi), file) != NULL) {
        printf("%s", chuoi);
    }

    fclose(file);

    return 0;
}

