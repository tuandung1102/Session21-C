#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct{
	char id[20]; //ma sach
	char title[50]; //ten sach
	char author[50]; //tac gia
	float price[100]; //gia sach
	char type[50];	 //the loai
} Book;
  Book books[MAX_BOOKS];
  int n=0;
  void nhapThongtinSach(){
  	printf("Nhap so luong sach: ");
  	scanf("%d",&n);
  	getchar();
  	
  	for (int i=0;i<n;i++){
  		printf("Nhap thong tin sach thu %d:\n",i+1);
  		fgets(books[i].id,sizeof(books[i].id),stdin);
  		strtok(books[i].id,"\n");
  		printf("Ten sach: ");
  		fgets(books[i].title,sizeof(books[i].title),stdin);
  		strtok(books[i].title,"\n");
  		printf("Tac gia: ");
  		fgets(books[i].author,sizeof(books[i].author),stdin);
  		strtok(books[i].title,"\n");
  		printf("Gia sach: ");
  		fgets(books[i].price,sizeof(books[i].price),stdin);
  	    strtok(books[i].price,"\n");
  		printf("The loai: ");
  		fgets(books[i].type,sizeof(books[i].type),stdin);
  		strtok(books[i].type,"\n");;
	  }
  }
  void saveBook(){
  	FILE *file = fopen ("Books.bin","wb");
  	if (file==NULL){
  		printf("\nKhong the mo file de ghi!\n");
  		return 1;
	  }
  	fwrite(&n,sizeof(int),1,file);
  	fwrite(books,sizeof(Book),n,file);
  	fclose(file);
  	printf("\nDa luu thong tin sach vao file!\n");
  }
  void loadBook(){
  		FILE *file = fopen ("Books.bin","wb");
  	if (file==NULL){
  		printf("\nKhong the mo file de doc!\n");
  		return 1;
	  }
	  fread(n,sizeof(Book),1,file);
	  fread(books,sizeof(Book),n,file);
	  fclose(file);
	  printf("\nDa lay thong tin sach tu file!\n");
  }
  void showBook(){
  	if (n==0){
  		printf("\nKhong co thong tin sach de hien thi\n");
  		return 1;
	  }
	   printf("\nDanh sach thong tin sach:\n");
    for (int i = 0; i < n; i++) {
        printf("\nSach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", books[i].id);
        printf("Ten sach: %s\n", books[i].title);
        printf("Tac gia: %s\n", books[i].author);
        printf("Gia tien: %.2f\n", books[i].price);
        printf("The loai: %s\n", books[i].type);
    }
  }
  
  int main(){
  	int chose;
  	do {
  		 printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Luu thong tin sach vao file\n");
        printf("3. Lay thong tin sach tu file\n");
        printf("4. Hien thi thong tin sach\n");
        printf("5. Thoat\n");
        printf("\nLua chon cua ban: ");
        scanf("%d", &chose);
        getchar(); 
        switch(chose){
        	case 1:
        		nhapThongtinSach();
        		break;
        	case 2:
        		saveBook();
        		break;
        	case 3: 
        	    loadBook();
        	    break;
        	case 4:
        		showBook();
        		break;
        	case 5:
        		printf("\nThoat chuong trinh\n");
        		break;
        	default:
        		printf("\nLua chon khong hop le\n");
		}
	  } while(chose!=5);
	  return 0;
  }

