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

void initDedequeue(Dequeue *dequeue);
int is_empty(Dequeue *dequeue);
void push_front(Dequeue *dequeue, int data);
void push_back(Dequeue *dequeue, int data);
int front_value(Dequeue *dequeue);
int rear_value(Dequeue *dequeue);
int size(Dequeue *dequeue);
int pop_front(Dequeue *dequeue);
int pop_back(Dequeue *dequeue);

char str[1000001];
char bomb[37];
Dequeue dequeue;

int main(void){
	
	Dequeue *ptr;
	ptr=&dequeue;
	int str_len;int bomb_len;int cnt=0;int push_count=0;int flag=0;int temp;
	char trash;
	scanf("%s", str);
	scanf("%c", &trash);
	scanf("%s", bomb);
	str_len=strlen(str);
	bomb_len=strlen(bomb);
	
	if(bomb_len==1){
		for(int i=0;i<str_len;i++){
			if(str[i]!=bomb[0]){
				printf("%c", str[i]);
				cnt++;
			}
		}
		if(!cnt){//cnt�� 0�� ��� 
			printf("FRULA");
		}
	}
	else{
		/*bomb len�� 1�� �ƴ� ���*/
		for(int i=0;i<str_len;i++){
			if(str[i]!=bomb[0]){
				printf("%c", str[i]);
				cnt++;
			}
			else{//bomb�� ù ���ڿ� �Ȱ��� ���ڰ� ������ ���
				push_count=0;
				while(str[i]==bomb[0]&&str[i]!='/0'){
					push_front(ptr, bomb[0]);
					i++;
					push_count++;
				}
				flag=0;
				while(str[i]!='\0'&&push_count>0){
					for(int j=1;j<bomb_len;j++){
						i++;
						if(str[i]=='\0') break;
						if(str[i]==bomb[j]){
							push_front(ptr, bomb[j]);
						}
						else{
							flag=1;
							break;
						}
					}
					if(!flag){//bomb�� ��Ȯ�� ��ġ�� ��� 
						for(int j=0;j<bomb_len;j++){
							pop_front(ptr);
						}
					}
					else{
						while((temp=pop_back(ptr))!=-1){//bomb�� ��ġ���� ���� ��쿡�� ���� ���� ����, ����Ѵ�. 
							printf("%c", temp);
							cnt++;
						}
						break;
					}
					push_count--;
				}
				if(str[i]=='\0'){
					while((temp=pop_back(ptr))!=-1){
						printf("%c", temp);
						cnt++;
					}
					break;
				}
			}
		}
		if(!cnt){
			printf("FRULA")
		}
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
		//printf("-1\n");
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
		//printf("-1\n");
		return -1;
	}
	ptr=dequeue->rear;
	data=ptr->data;
	dequeue->rear=ptr->previous;
	free(ptr);
	dequeue->count--;
	return data;
}


