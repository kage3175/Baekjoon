#include <stdio.h>
#include <stdlib.h>

int n; int*arr;
int count=0;

void nqueen(int depth);
int is_right(int idx);

int main(void){
	int i=0;
	scanf("%d", &n);
	arr=(int*)malloc(sizeof(int)*n);
	nqueen(0);
	
	printf("%d", count);
	
	free(arr);
	
	return 0;
}

int is_right(int depth){
	for(int i=0;i<depth;i++){
		if(arr[depth]==arr[i]||arr[depth]-arr[i]==depth-i||arr[i]-arr[depth]==depth-i){
			return 0;
		}
	}
	return 1;
}

void nqueen(int depth){
	if(depth==n){
		count++;
		return;
	}
	for(int i=0;i<n;i++){
		arr[depth]=i;
		if(is_right(depth)){
			nqueen(depth+1);
		}
	}
	
}
