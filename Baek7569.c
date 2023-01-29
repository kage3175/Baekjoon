	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	typedef struct Node{
		int x;
		int y;
		int z;
		struct Node *next;
	}Node;
	
	typedef struct Queue{
		Node *front;
		Node *rear;
		int count;
	}Queue;
	
	void initQueue(Queue *queue);
	int is_empty(Queue *queue);
	void push(Queue *queue, int x,int y, int z);
	/*int front_value(Queue *queue);
	int rear_value(Queue *queue);*/
	int size(Queue *queue);
	int pop(Queue *queue, int result[]);
	
	int m, n,h;
	int visited[102][102][102]={0};
	int dx[6]={1,-1,0,0,0,0};int dy[6]={0,0,1,-1,0,0};int dz[6]={0,0,0,0,1,-1};
	Queue queue1;Queue queue2;
	int board[102][102][102];
	int pos[3];
	
	int main(void){
		int depth=0;int newx;int newy;int newz;
		int flag=0;
		scanf("%d %d %d", &m, &n, &h);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=h;k++){
					scanf("%d", &board[i][j][k]);
					if(board[i][j][k]==1){
						push(&queue1, i,j,k);
						visited[i][j][k]=1;
					}
				}
				
			}
		}
		
		while(!is_empty(&queue1)||!is_empty(&queue2)){
			depth++;
			while(!is_empty(&queue1)){
				if(pop(&queue1, pos)==-1){
					break;
				}
				for(int i=0;i<6;i++){
					//printf("%d %d\n", pos[0], pos[1]);
					newx=*(pos)+dx[i];newy=*(pos+1)+dy[i];newz=*(pos+2)+dz[i];
					//printf("%d %d", newx, newy);
					if(board[newx][newy][newz]==0&&!visited[newx][newy][newz]&&(newx>0&&newx<=n)&&(newy>0&&newy<=m)&&(newz>0&&newz<=h)){
						push(&queue2, newx, newy, newz);
						//printf("1, %d %d\n", newx, newy);
						//printf("new %d %d\n", newx, newy);
						visited[newx][newy][newz]=1;
						board[newx][newy][newz]=1;
					}
				}
			}
			if(is_empty(&queue2)) break;
			depth++;
			while(!is_empty(&queue2)){
				if(pop(&queue2, pos)==-1){
					break;
				}
				
				for(int i=0;i<6;i++){
					newx=*(pos)+dx[i];newy=*(pos+1)+dy[i];newz=*(pos+2)+dz[i];
					if(board[newx][newy][newz]==0&&!visited[newx][newy][newz]&&(newx>0&&newx<=n)&&(newy>0&&newy<=m)&&(newz>0&&newz<=h)){
						push(&queue1, newx, newy, newz);
						//printf("2, %d %d\n", newx, newy);
						visited[newx][newy][newz]=1;
						board[newx][newy][newz]=1;
					}
				}
			}
			if(is_empty(&queue1)) break;
		}
		
		flag=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=1;k<=h;k++){
						if(board[i][j][k]==0){
						flag=1;
						break;
					}
				}
			}
		}
		if(flag){
			printf("-1");
		}
		else{
			printf("%d", depth-1);
		}
		
		return 0;
	}
	
	void initQueue(Queue *queue){
		queue->front=NULL;
		queue->rear=NULL;
		queue->count=0;
	}
	
	int is_empty(Queue *queue){//비었으면 1, 아니면 0 
		return queue->count==0;
	}
	
	void push(Queue *queue, int x, int y, int z){
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->x=x;
		newNode->y=y;
		newNode->z=z;
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
	
	/*int front_value(Queue *queue){
		if(is_empty(queue)) return -1;//비었으면 -1 반환 
		return queue->front->data;
	}*/
	
	/*int rear_value(Queue *queue){
		if(is_empty(queue)) return -1;//비었으면 -1 반환 
		return queue->rear->data;
	}*/
	
	int size(Queue *queue){
		return queue->count;
	}
	
	int pop(Queue *queue, int result[]){//가장 첫 값을 빼내고, 그 값을 반환한다. 
		Node *ptr;
		if(is_empty(queue)){
			return -1;
		}
		ptr=queue->front;
		result[0]=ptr->x;
		result[1]=ptr->y;
		result[2]=ptr->z;
		//printf("pop %d %d %d %d\n", ptr->x, ptr->y, result[0], result[1]);
		queue->front=ptr->next;
		free(ptr);
		queue->count--;
		return 0;
	}
	
	
	

