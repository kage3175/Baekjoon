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
char p[100001];
char str_arr[400005];

int main(void){
	int t=0;int R_count=0;int cnt=0;int flag=0;
	int num=0;int j=1;int where_to_pop=0;//where_to_pop�� 0�̸� pop_front, 1�̸� pop_back�� �����ϰ� �Ѵ�. 
	int size=0;
	
	int n;char trash;
	scanf("%d", &t);
	
	initDequeue(&dequeue);
	
	for(int i=0;i<t;i++){
		R_count=0;
		flag=0;
		j=1;
		where_to_pop=0;
		scanf("%c", &trash);
		scanf("%s", p);
		scanf("%d", &n);
		
		scanf("%c", &trash);
		scanf("%s", str_arr);
		//size=strlen(str_arr);
		if(n!=0){
			while(str_arr[j]!='\0'){
				num=0;
				while(str_arr[j]!=','&&str_arr[j]!=']'){
					num=num*10+(int)str_arr[j]-'0';
					j++;
				}
				j++;
				push_back(&dequeue, num);
			}
		}
		
		//printf("%s\n\n", p);
		for(int j=0;p[j]!='\0';j++){
			if(p[j]=='R'){
				where_to_pop=where_to_pop==1?0:1;
				R_count=R_count==0?1:0;//R_count�� 0�̸� ������, 1�̸� �������̶�� ���̴�. 
			}
			else{
				if(n==0){
					flag=1;
					break;
				}
				else if(dequeue.count==0){
					flag=1;
					break;
				}
				else{
					if(where_to_pop==0) pop_front(&dequeue);
					else pop_back(&dequeue);
				}
			}
		}
		if(flag){
			printf("error\n");
			continue;
		}
		printf("[");
		cnt=dequeue.count;
		if(R_count){
			for(int j=0;j<cnt;j++){
				printf("%d", pop_back(&dequeue));
				if(j<cnt-1) printf(",");
			}
			
		}
		else{
			for(int j=0;j<cnt;j++){
				printf("%d", pop_front(&dequeue));
				if(j<cnt-1) printf(",");
			}
		}
		printf("]\n");
		
	}
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
	if(is_empty(dequeue)){//queue�� ������� �� 
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
	if(is_empty(dequeue)){//queue�� ������� �� 
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
	if(is_empty(dequeue)) return -1;//������� -1 ��ȯ 
	return dequeue->front->data;
}

int rear_value(Dequeue *dequeue){
	if(is_empty(dequeue)) return -1;//������� -1 ��ȯ 
	return dequeue->rear->data;
}

int size(Dequeue *dequeue){
	return dequeue->count;
}

int pop_front(Dequeue *dequeue){//���� ù ���� ������, �� ���� ��ȯ�Ѵ�. 
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

int pop_back(Dequeue *dequeue){//���� ù ���� ������, �� ���� ��ȯ�Ѵ�. 
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
