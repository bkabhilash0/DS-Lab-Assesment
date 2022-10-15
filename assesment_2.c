#include <stdio.h>
#include <stdlib.h>

int *stack,capacity,top=-1;
char *charStack;
int isCharStack=0;

void displayStack(){
	int i;
	if(top == -1){
		printf("The Stack is Empty!\n");
		return;
	}
	printf("----------------\n");
	for(i=top;i >= 0;i--){
		if(isCharStack){
			printf("|\t%c\t|\n",charStack[i]);
		}else{
			printf("|\t%d\t|\n",stack[i]);	
		}	
		printf("-----------------\n");
	}
}

void push(){
	if(top == capacity - 1){
		printf("Stack is Full!\n");
	}else{
		int e;
		if(isCharStack){
			char ch;
			printf("Enter the Element to Push to the Stack: ");
			gets(&ch);
			scanf("%c",&ch);
			charStack[++top] = ch;
			printf("Element pushed Successfully into the Stack!\n");
			return;
		}
		printf("Enter the Element to Push to the Stack: ");
		scanf("%d",&e);
		stack[++top] = e;
		printf("Element pushed Successfully into the Stack!\n");
	}
}

void pop(){
	if(top == -1){
		printf("The Stack is Empty!\n");
	}else{
		if(isCharStack){
			printf("Poping out the element %c from the Stack\n",charStack[top--]);
			printf("Pop Successful!\n");
		}else{
			printf("Poping out the element %d from the Stack\n",stack[top--]);
			printf("Pop Successful!\n");
		}
	}
}

void peek(){
	if(top == -1){
		printf("Stack is Empty!\n");
	}else{
		if(isCharStack){
			printf("The top of the Stack is %c\n",charStack[top]);
			return;
		}
		printf("The top of the Stack is %d\n",stack[top]);
	}
}

void selectOperation(int choice){
	switch(choice){
		case 1: push();
			break;
		case 2: pop();
			break;
		case 3: peek();
				break;
		case 4: displayStack();
				break;
		default: printf("Enter a Valid Choice!\n");
	}
}

void displayOptions(){
	int ch;
	while(1){
		printf("Stack Program - ");
		printf(isCharStack ? "Character Stack" : "Number Stack");
		printf("\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Peek\n");
		printf("4. Display Stack\n");
		printf("5. Exit\n");
		printf("Enter you Choice: ");
		scanf("%d",&ch);
		if(ch == 5){
			printf("Program Exited Successfully!\n");
			break;
		}
		selectOperation(ch);
	}

}

void main(){
	int ch;
	printf("Stack Program\n");
	printf("1. Number Stack\n");
	printf("2. Character Stack\n");
	printf("Enter the Choice: ");
	scanf("%d",&ch);
	if(ch == 1){
		stack = (int*)malloc(capacity * sizeof(int));	
	}else{
		isCharStack = 1;
		charStack = (char*)malloc(capacity * sizeof(char));
	}
	printf("Enter the size of the stack: ");
	scanf("%d",&capacity);
	
	displayOptions();
}
