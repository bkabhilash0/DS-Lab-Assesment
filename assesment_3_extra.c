//Expression Evaluation
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct stack{
	int top;
	unsigned int capacity ;
	char *data;
} Stack;

int getPrecedence(char ch);
char *postfix;

void push(Stack *s,char ch){
	int top = s->top;
	unsigned int capacity = s->capacity;
//	printf("\nPushing => %c\n",ch);
	if(top == capacity - 1){
		printf("Stack is Full!\n");
	}else{
		s->data[++s->top] = ch;
	}
}

void pop(Stack *s){
	int top = s->top;
	char curr = s->data[top];
	unsigned int capacity = s->capacity;
	if(top == - 1){
		printf("Stack is Empty!\n");
	}else{
		printf("%c",curr);
		strncat(postfix,&curr,1);
		s->top = s->top - 1;
	}
}

void popTillBracket(Stack *s){
	int top = s->top;
	char curr = s->data[top];
	if(curr == '('){
		return;
	}else{
		pop(s);
		popTillBracket(s);
	}
}

void popAll(Stack *s){
	int top = s->top;
	int i;
	for(i=top;i>=0;i--){
		pop(s);
	}
}

void checkPrecedence(Stack *s,char ch){
	int top = s->top;
	char curr = s->data[s->top];
	if(top == -1 || curr == '(' || ch == '('){
		push(s,ch);
		return;
	}
	if(ch == ')'){
		popTillBracket(s);
		s->top = s->top - 1;
		return;
	}
	if(getPrecedence(ch) > getPrecedence(curr)){
		push(s,ch);
	}else{
		pop(s);
		checkPrecedence(s,ch);
	}
}

int getPrecedence(char ch){
	switch(ch){
		case '+':
		case '-': return 1;
		case '*':
		case '/': return 2;
		case '^': return 3;
		default: return 0;
	}
}

void evaluate(Stack *s){
	int i,l,res=0;
	char ch;
	l = strlen(postfix);
	for(i=0;i<l;i++){
		ch = postfix[i];
		if(isdigit(ch)){
			push(s,ch);
		}else{
			int top = s->top;
			char a = s->data[top-1];
			printf("\nTop is %d %d\n",top,atoi(a));
			printf("A => %d\n",atoi(&(s->data[top - 1])));
			printf("B => %d\n",atoi(&(s->data[top])));
			int b = atoi(&(s->data[top]));
//			printf("\n%d %c %d\n",a,ch,b);
			s->top = s->top - 1;
//			switch(ch){
//				case '+': res = a+ b;
//						break;
//				case '-': res = a-b;
//						break;
//				case '*': res = a*b;
//						break;
//				case '/': res = a/b;
//						break;
//				case '^': res = pow(a,b);
//						break;
//				default: break;
//			}
//			s->data[s->top] = res;
		}
	}
}

void main(){
	char ch[] = "1+5*(4-7)+3";
	int l = strlen(ch);
	Stack s = {.top = -1,.capacity = l};
	s.data = (char*)calloc(l,sizeof(char));
	postfix = (char*)calloc(l,sizeof(char));
	int i;
	char c;
	for(i=0;i<l;i++){
		c = ch[i];
		if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
			strncat(postfix,&c,1);
			printf("%c",c);
		}else{
			checkPrecedence(&s,c);
		}
	}
	popAll(&s);
	printf("\n%s",postfix);
	evaluate(&s);
}
