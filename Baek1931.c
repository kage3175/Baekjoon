#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** arr;

void swap(int i, int j);
int static compare(const void*first, const void*second);

int main(void){
	int n;int end_now=0;int cnt=0;
	scanf("%d", &n);
	arr=(int**)malloc(sizeof(int*)*(n+1));
	for(int i=1;i<n+1;i++) arr[i]=(int*)malloc(sizeof(int)*2);
	for(int i=1;i<n+1;i++) scanf("%d %d", &arr[i][0], &arr[i][1]);
	
	for(int i=n;i>1;i--){
		for(int j=1;j<i;j++){
			if(arr[j][1]>arr[j+1][1]) swap(j, j+1);
		}
	}
	
	end_now=arr[1][1];
	cnt++;
	
	for(int i=2;i<n+1;i++){
		if(arr[i][0]>=end_now){
			end_now=arr[i][1];
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	for(int i=0;i<n+1;i++) free(arr[i]);
	free(arr);
	return 0;
}

void swap(int i, int j){
	int temp;
	for(int k=0;k<2;k++){
		temp=arr[i][k];
		arr[i][k]=arr[j][k];
		arr[j][k]=temp;
	}
}
