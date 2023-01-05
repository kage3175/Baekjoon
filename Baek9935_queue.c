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

/*main 함수가 들어갈 곳*/

Queue queue[500001];
char str[1000001];
char bomb[37];

int main(void){
	char trash;char ch;int str_len;int bomb_len;int is_frula;/*is_frula가 0이면 frula를 출력해야함*/int queue_num=0;int bomb_ptr;int flag=0;
	scanf("%s", str);
	scanf("%c", &trash);
	scanf("%s", bomb);
	str_len=strlen(str);
	bomb_len=strlen(bomb);
	
	/*bomb이 1일 경우*/
	if(bomb_len==1){
		for(int i=0;i<str_len;i++){
			if(str[i]!=bomb[0]){
				printf("%c", str[i]);
				is_frula++;
			}
		}
	}
	
	else{
		for(int i=0;i<str_len;i++){
			if(str[i]!=bomb[0]){
				printf("%c", str[i]);
				is_frula++;
			}
			else{//bomb[0]와 일치할 경우
				queue_num=0;
				bomb_ptr=0;
				push(&queue[queue_num],bomb[0]);
				i++;
				while(1){
					flag=0;
					
					for(int j=queue[queue_num].count;j<bomb_len;j++){
						
						if(str[i]==bomb[j]){
							push(&queue[queue_num], str[i]);
							i++;
						}
						else if(str[i]==bomb[0]){
							queue_num++;
							flag=1;
							push(&queue[queue_num], bomb[0]);
							i++;
							break;
						}
						else{//while 1까지 완전 탈출 
							flag=2;
							//printf("%d %c\n", queue_num, queue[queue_num].rear->data);
							for(int k=0;k<=queue_num;k++){
								for(int l=queue[k].count;l>0;l--){
									printf("%c", pop(&queue[k]));
									is_frula++;
								}
							}
							printf("%c", str[i]);
							is_frula++;
							break;
						}
					}
					if(flag==1) continue;
					else if(flag==2) break;
					else{
						for(int j=0;j<bomb_len;j++){
							pop(&queue[queue_num]);
						}
						queue_num--;
						if(queue_num==-1){
							i--;
							break;
						}
					}
				}
			}
		}
	}
	
	if(!is_frula) printf("FRULA");
	
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
	return queue->front->data;
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
		//printf("-1\n");
		return 0;
	}
	ptr=queue->front;
	data=ptr->data;
	queue->front=ptr->next;
	free(ptr);
	queue->count--;
	return data;
}




