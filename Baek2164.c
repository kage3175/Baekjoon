#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node *next;
}Node;

typedef struct Queue{
	Node *front;
	Node *rear;
	int count;
}Queue;

void initQueue(Queue *queue);
int is_empty(Queue *queue);
void push(Queue *queue, int data);
int front_value(Queue *queue);
int rear_value(Queue *queue);
int size(Queue *queue);
int pop(Queue *queue);


int main(void){
	int n=0;int temp=0;
	scanf("%d", &n);
	Queue queue;
	initQueue(&queue);
	for(int i=0;i<n;i++) push(&queue, i+1);//카드 더미 초기화. 1이 front고 n이 rear에 존재한다. 
	while(queue.count>1){
		pop(&queue);
		temp=queue.front->data;
		pop(&queue);
		push(&queue, temp);
	}
	
	
	printf("%d", queue.front->data); 
	
	return 0;
}

void initQueue(Queue *queue){
	queue->front=NULL;
	queue->rear=NULL;
	queue->count=0;
}

int is_empty(Queue *queue){
	return queue->count==0;
}

void push(Queue *queue, int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	if(is_empty(queue)){//queue가 비어있을 때 
		queue->front=newNode;
	}
	else{
		queue->rear->next=newNode;
	}
	queue->rear=newNode;
	queue->count++;
}

int front_value(Queue *queue){
	if(is_empty(queue)) return -1;//비었으면 -1 반환 
	else return queue->front->data;
}

int rear_value(Queue *queue){
	if(is_empty(queue)) return -1;//비었으면 -1 반환 
	return queue->rear->data;
}

int size(Queue *queue){
	return queue->count;
}

int pop(Queue *queue){//가장 첫 값을 빼내고, 그 값을 반환한다. 
	int data;
	Node *ptr;
	if(is_empty(queue)){
		printf("-1\n");
		return 0;
	}
	ptr=queue->front;
	data=ptr->data;
	queue->front=ptr->next;
	free(ptr);
	queue->count--;
	return data;
}




