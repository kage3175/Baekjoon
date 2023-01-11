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

Queue queue1;Queue queue2;

int n;int k;int flag=0;
int depth=0;int node;
int visited[100001]={0};

int main(void){
	scanf("%d %d", &n, &k);
	initQueue(&queue1);initQueue(&queue2);
	push(&queue1, n);
	visited[n]=1;
	
	/*while(!is_empty(&queue)){
		node=pop(&queue);
		if(node=100000){//2배, +1 하면 안됨 
			if(visited[node-1]==0){
				push(&queue, node-1);
				visited[node-1]=1;
			}
		}
		else if(node==0){//-1 하면 안됨 
			if(visited[node+1]==0){
				push(&queue, node+1);
				visited[node+1]=1;
			}
		}
		else if(node>50000){//2배하면 안됨 
			if(visited[node-1]==0){
				push(&queue, node-1);
				visited[node-1]=1;
			}
			if(visited[node+1]==0){
				push(&queue, node+1);
				visited[node+1]=1;
			}
		}
		else{
			if(visited[node-1]==0){
				push(&queue, node-1);
				visited[node-1]=1;
			}
			if(visited[node+1]==0){
				push(&queue, node+1);
				visited[node+1]=1;
			}
			if(visited[node*2]==0){
				push(&queue, node*2);
				visited[node*2]=1;
			}
		}
	}*/
	
	while(1){
		depth++;
		while(!is_empty(&queue1)){
			//printf("1 ");
			node=pop(&queue1);
			//printf("%d\n", node);
			if(node==k){
				flag=1;
				break;
			}
			if(node==100000){//2배, +1 하면 안됨
				if(visited[node-1]==0){
					push(&queue2, node-1);
					visited[node-1]=1;
				}
			}
			else if(node==0){//-1 하면 안됨
				if(visited[node+1]==0){
					push(&queue2, node+1);
					visited[node+1]=1;
				}
			}
			else if(node>50000){//2배하면 안됨
				if(visited[node-1]==0){
					push(&queue2, node-1);
					visited[node-1]=1;
				}
				if(visited[node+1]==0){
					push(&queue2, node+1);
					visited[node+1]=1;
				}
			}
			else{
				if(visited[node-1]==0){
					push(&queue2, node-1);
					visited[node-1]=1;
				}
				if(visited[node+1]==0){
					push(&queue2, node+1);
					visited[node+1]=1;
				}
				if(visited[node*2]==0){
					push(&queue2, node*2);
					visited[node*2]=1;
				}
			}
		}
		if(flag) break;
		depth++;
		while(!is_empty(&queue2)){
			//printf("2 ");
			node=pop(&queue2);
			//printf("%d\n", node);
			if(node==k){
				flag=1;
				break;
			}
			if(node==100000){//2배, +1 하면 안됨 
				if(visited[node-1]==0){
					push(&queue1, node-1);
					visited[node-1]=1;
				}
			}
			else if(node==0){//-1 하면 안됨 
				if(visited[node+1]==0){
					push(&queue1, node+1);
					visited[node+1]=1;
				}
			}
			else if(node>50000){//2배하면 안됨 
				if(visited[node-1]==0){
					push(&queue1, node-1);
					visited[node-1]=1;
				}
				if(visited[node+1]==0){
					push(&queue1, node+1);
					visited[node+1]=1;
				}
			}
			else{
				if(visited[node-1]==0){
					push(&queue1, node-1);
					visited[node-1]=1;
				}
				if(visited[node+1]==0){
					push(&queue1, node+1);
					visited[node+1]=1;
				}
				if(visited[node*2]==0){
					push(&queue1, node*2);
					visited[node*2]=1;
				}
			}
		}
		if(flag) break;
	}
	
	printf("%d", depth-1);
	
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




