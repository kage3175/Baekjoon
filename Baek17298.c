#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_{
	struct node_ *next;
	struct node_ *previous;
	int data;
}NODE;

typedef	struct stack_{
	NODE *front;
	NODE *rear;
	int size;
}STACK;

void InitStack(STACK *stack);
int is_empty(STACK *stack);
void push(STACK *stack, int num);
int pop(STACK *stack);

STACK *stack;
STACK x;
STACK answer;
STACK *ptr;
int arr[1000001];
int n;

int main(void){
	stack=&x;
	ptr=&answer;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	for(int i=n-1;i>=0;i--){
		while(1){
			int temp=pop(stack);
			if(temp==-1){
				push(ptr, -1);
				push(stack, arr[i]);
				break;
			}
			else{
				if(temp>arr[i]){
					push(ptr, temp);
					push(stack, temp);
					push(stack, arr[i]);
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		printf("%d ", pop(ptr));
	}
	
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

void push(STACK *stack, int num){
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

int pop(STACK *stack){
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






