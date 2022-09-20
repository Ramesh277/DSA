#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>

void push(int);
int pop();
int vstack[100];
int tos = -1;

int main(){
	
	int i, res, len, op1, op2, value[100];
	char postfix[100], ch;
	

	
	printf("Enter a valid postfix\n");
	gets(postfix);
	
	len = strlen(postfix);
	for(i=0;i<=len-1;i++){
		
		if(isalpha(postfix[i]))
		{
			printf("Enter value of %c ",postfix[i]);
			scanf("%d",&value[i]);
			push(value[i]);
		}else{
			ch = postfix[i];
			op2 = pop();
			op1 = pop();
			switch(ch){
				case '+':
					push(op1+op2);
					break;
			    case '-':
			    	push(op1-op2);
			    	break;
			    case '*':
				    push(op1*op2);
					break;
				case '/':
				    push(op1/op2);
					break;
				case '$':
				    push(op1/op2);
					break;
				case '%':
				    push(op1%op2);
					break;
									
				    		
			}
		}
	}
	
	//result
	printf("The result is :");
	res = pop();
	printf("%d",res);
	return 0;	
}

void push(int val){
	vstack[++tos]=val;
	
	
}

int pop(){
	int n;
	n = vstack[tos--];
	return(n);
}

