#include<stdio.h>
#include<stdlib.h>

//prototype
void menu();
void addBook();
void viewBooks();
void deleteBook();
void updateBook();

//creating structure for BOOK 
struct Book{
	int id;
	char name[30];
	float price;
};

int main(){
	int choice;
	while(1){
		menu();
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				addBook();
				break;
			case 2:
				viewBooks();
				break;
			case 3:
				deleteBook();
				break;
			case 4:
				updateBook();
				break;
			case 5:
				exit(0);			
		}//end of switch-case
	}//end of while loop

	
}
//updating book record
void updateBook(){
	FILE *fp;
	struct Book b1;
	int bookId;
	
	system("cls");
	
	fp=fopen("MyBook.txt","r+");
	if(fp==NULL){
		printf("Error Opening File!!!");
		getch();
		return;
	}
	printf("Enter book ID to update: ");
	scanf("%d",&bookId);
	fflush(stdin);
	
	while(fread(&b1, sizeof(b1),1,fp)==1){
		if(bookId == b1.id){
			printf("Enter new Book Name:");
			gets(b1.name);
			fflush(stdin);
			
			printf("Enter new Price :");
			scanf("%f",&b1.price);
			fflush(stdin);
			
			fseek(fp,-sizeof(b1),SEEK_CUR);
			fwrite(&b1, sizeof(b1),1,fp);
			printf("Recod is updated \n");
			getch();
			break;
		}
	
	}//end of while loop
	fclose(fp);
}
//deleting a record according to book id
void deleteBook(){
	FILE *fp, *ft;
	struct Book b1;
	int bookId;
	int stat=0;
	
	system("cls");
	
	fp=fopen("MyBook.txt","r");
	ft=fopen("temp.txt","w");
	if(fp==NULL || ft==NULL){
		printf("Error Opening File!!!");
		getch();
		return;
	}
	
	printf("Enter book ID to delete: ");
	scanf("%d",&bookId);
	fflush(stdin);
	
	while(fread(&b1, sizeof(b1),1,fp)==1){
		if(b1.id!=bookId){
			fwrite(&b1, sizeof(b1),1,ft);
		}
		else{
			stat=1;
		}
		
	}//end while loop
	
	fclose(fp);
	fclose(ft);
	
	remove("MyBook.txt"); //deleting my main file
	rename("temp.txt","MyBook.txt");
	
	if(stat==1)
		printf("Book id: %d has been deleted\n",bookId);
	else
		printf("Book id: %d record is NOT FOUND.\n", bookId);
	getch();
	
}

//Diplaying all books records
void viewBooks(){
	FILE *fp;
	struct Book b1;
	
	system("cls");
	
	fp=fopen("MyBook.txt","r");
	if(fp==NULL){
		printf("Error Opening File!!!");
		getch();
		return;
	}
	
	printf("========== Books Record ==========\n\n");
	while(fread(&b1, sizeof(b1),1,fp)==1){
		printf("ID : %d\n", b1.id);
		printf("Name : %s \n", b1.name);
		printf("Price : $ %0.2f\n",b1.price);
		printf("-------------------------------------\n");
		
	}
	getch();
	fclose(fp);
}
//adding new book into a file
void addBook(){
	getch();

	FILE *fp;
	struct Book b1;
	
	system("cls");
	
	fp=fopen("MyBook.txt","a+");
	if(fp==NULL){
		printf("Error Opening File!!!");
		getch();
		return;
	}
	
	printf("Enter book ID:");
	scanf("%d",&b1.id);
	fflush(stdin);
	printf("Enter Book Name: ");
	gets(b1.name);
	fflush(stdin);
	printf("Enter book Price: ");
	scanf("%f",&b1.price);
	fflush(stdin);
	
	fwrite(&b1, sizeof(b1),1,fp);
	
	fclose(fp);
	
	getch();
}

void menu(){
	//clrscr();
	system("cls"); // same as clear screen clrscr()
	printf("1. Add new Book \n");
	printf("2. View all Books \n");
	printf("3. Delete book\n");
	printf("4. Update Book \n");
	printf("5. Exit\n");
	printf("Enter your choice [1-5]: ");
}
