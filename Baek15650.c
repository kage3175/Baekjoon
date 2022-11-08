#include <stdio.h>
#include <stdlib.h>

void print_combinations(int depth, int start);
void print_arr(int size);

int* arr;
int n;int m;

int main(void){
	int i=0;
	scanf("%d %d", &n,&m);
	arr=(int*)malloc(sizeof(int)*n);
	
	print_combinations(0,1);
	
	free(arr);
	
	return 0;
}

void print_combinations(int depth, int start){
	int i=0;
	if(depth==m){
		print_arr(m);
		return;
	}
	for(i=start;i<=n;i++){
		arr[depth]=i;
		print_combinations(depth+1,i+1);
	}
	
}

void print_arr(int size){
	int i=0;
	for(i=0;i<size;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
