#include<stdio.h>
#define SIZE 5
int rear =-1;
int front = 0;
int queue[SIZE];

void Enqueue();
void Dequeue();
void Display();

void main(){
	
	int n;	
	while(1){
	printf("1 - Enqueue:\n");
	printf("2 - Dequeue:\n");
	printf("3 - Display:\n");
	printf("4 - Exit:\n");
	scanf("%d", &n);
		switch(n){
			case 1:
				Enqueue();
				break;
		    case 2:
			    Dequeue();
				break;
			case 3:
			    Display();
				break;	
//			case 4:
//			    exit(0);
//				default:
//				printf("Incorrect \n");			
		}
	}
	getch();
}
	
	// enqueue 
	void Enqueue(){
		int insert_items;
	
		if(rear == SIZE-1){
         printf("Queue OVERFLOW\n");		
			
		}else{
			printf("Enter elements :\n");
		    scanf("%d",&insert_items);
		    rear = rear + 1;
		   queue[rear] = insert_items;
			
		}
		getch();
			
	}
	
	
	//dequeue
	void Dequeue(){
		int items;
		
		if(front ==-1|| front>rear){
			printf("queue is Empty:\n");
			
		}else{
			items = queue[front];
			front = front+1;
		}
		getch();
	}
	
    //display
	void Display(){
		int i;
		if(rear<front){
			printf("Queue is Empty:\n");
			
		}else{
			printf("Enter queue:\n");
			for(i=front; i <= rear; i++)
				printf("%d\n", queue[i]);
					printf("\n");
			
			
		}
		getch();
	
	}	
	
	
	
