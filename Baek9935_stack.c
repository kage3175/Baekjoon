#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_{
	struct node_ *next;
	struct node_ *previous;
	char data;
}NODE;

typedef	struct stack_{
	NODE *front;
	NODE *rear;
	int size;
}STACK;

void InitStack(STACK *stack);
int is_empty(STACK *stack);
void push(STACK *stack, char num);
char pop(STACK *stack);

char str[1000001];
char temp[1000001];

int main(void){
	char bomb[37];
	char ch;
	STACK stack;
	InitStack(&stack);
	while((ch=getchar())!='\n'){
		push(&stack, ch);
	}
	scanf("%s", bomb);
	//printf("%s", bomb);
	
	
	
	return 0;
}

void InitStack(STACK *stack){
	stack->front=NULL;
	stack->rear=NULL;
	stack->size=0;
}

int is_empty(STACK *stack){
	return stack->size==0;
}

void push(STACK *stack, char num){
	NODE *Newnode;
	Newnode=(NODE*)malloc(sizeof(NODE));
	Newnode->data=num;
	Newnode->next=NULL;
	if(is_empty(stack)){
		Newnode->previous=NULL;
		stack->front=Newnode;
		stack->rear=Newnode;
	}
	else{
		Newnode->previous=stack->rear;
		stack->rear->next=Newnode;
		stack->rear=Newnode;
	}
	stack->size++;
}

char pop(STACK *stack){
	NODE *ptr;
	if(is_empty(stack)){
		return -1;
	}
	ptr=stack->rear;
	int data=ptr->data;
	stack->size--;
	stack->rear=ptr->previous;
	free(ptr);
	return data;
}






