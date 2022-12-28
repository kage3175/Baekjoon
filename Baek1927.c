#include <stdio.h>
#include <stdlib.h>

int heap[100002];
int end=-1;

void push(int num);
int pop(void);

int main(void){
	int n;int key;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		scanf("%d", &key);
		if(key==0) printf("%d\n", pop());
		else push(key);
	}
	return 0;
}

void push(int num){
	int temp;int tempnum=0;
	if(end==-1){
		heap[0]=num;
		end++;
		return;
	}
	else{
		heap[end+1]=num;
		end++;
		temp=end;
		while(heap[temp]>heap[temp-1]){
			tempnum=heap[temp];
			heap[temp]=heap[temp-1];
			heap[temp-1]=tempnum;
			temp--;
			if(temp==0) break;
		}
	}	
}

int pop(void){
	if(end==-1) return 0;
	int data=heap[end];
	heap[end]=0;
	end--;
	return data;
}
