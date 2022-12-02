#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	int data;
	struct Node *next;
	struct Node *previous;
}Node;

typedef struct Dequeue{
	Node *front;
	Node *rear;
	int count;
}Dequeue;

void initDequeue(Dequeue *dequeue);
int is_empty(Dequeue *dequeue);
void push_front(Dequeue *dequeue, int data);
void push_back(Dequeue *dequeue, int data);
int front_value(Dequeue *dequeue);
int rear_value(Dequeue *dequeue);
int size(Dequeue *dequeue);
int pop_front(Dequeue *dequeue);
int pop_back(Dequeue *dequeue);

Dequeue dequeue;

int main(void){
	int n, m;
	int cnt=0;
	int cnt_temp=0;
	int arr[50]={0};
	scanf("%d %d", &n, &m);
	initDequeue(&dequeue);
	for(int i=0;i<n;i++) push_back(&dequeue, i+1);
	for(int i=0;i<m;i++) scanf("%d", &arr[i]);
	for(int i=0;i<m;i++){
		cnt_temp=0;
		while(1){
			if(dequeue.front->data==arr[i]){
				if(dequeue.count-cnt_temp<cnt_temp) cnt+=dequeue.count-cnt_temp;
				else cnt+=cnt_temp;
				//printf("%d, %d\n", arr[i], cnt_temp);
				pop_front(&dequeue);
				break;
			}
			else{
				push_back(&dequeue, dequeue.front->data);
				pop_front(&dequeue);
				cnt_temp++;
			}
		}
	}
	printf("%d", cnt);
	
	return 0;
}

void initDequeue(Dequeue *dequeue){
	dequeue->front=NULL;
	dequeue->rear=NULL;
	dequeue->count=0;
}

int is_empty(Dequeue *dequeue){
	return dequeue->count==0;
}

void push_back(Dequeue *dequeue, int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	if(is_empty(dequeue)){//queue가 비어있을 때 
		dequeue->front=newNode;
		newNode->previous=NULL;
	}
	else{
		newNode->previous=dequeue->rear;
		dequeue->rear->next=newNode;
	}
	dequeue->rear=newNode;
	dequeue->count++;
}

void push_front(Dequeue *dequeue, int data){
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data=data;
	newNode->previous=NULL;
	if(is_empty(dequeue)){//queue가 비어있을 때 
		dequeue->rear=newNode;
		newNode->next=NULL;
	}
	else{
		newNode->next=dequeue->front;
		dequeue->front->previous=newNode;
	}
	dequeue->front=newNode;
	dequeue->count++;
}

int front_value(Dequeue *dequeue){
	if(is_empty(dequeue)) return -1;//비었으면 -1 반환 
	return dequeue->front->data;
}

int rear_value(Dequeue *dequeue){
	if(is_empty(dequeue)) return -1;//비었으면 -1 반환 
	return dequeue->rear->data;
}

int size(Dequeue *dequeue){
	return dequeue->count;
}

int pop_front(Dequeue *dequeue){//가장 첫 값을 빼내고, 그 값을 반환한다. 
	int data;
	Node *ptr;
	if(is_empty(dequeue)){
		return -1;
	}
	ptr=dequeue->front;
	data=ptr->data;
	dequeue->front=ptr->next;
	free(ptr);
	dequeue->count--;
	return data;
}

int pop_back(Dequeue *dequeue){//가장 첫 값을 빼내고, 그 값을 반환한다. 
	int data;
	Node *ptr;
	if(is_empty(dequeue)){
		return -1;
	}
	ptr=dequeue->rear;
	data=ptr->data;
	dequeue->rear=ptr->previous;
	free(ptr);
	dequeue->count--;
	return data;
}
