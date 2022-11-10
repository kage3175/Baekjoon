#include <stdio.h>
#include <stdlib.h>

int* arr;


int main(void){
	int n=0;
	int max=-100000001;
	scanf("%d", &n);
	arr=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	for(int i=1;i<n;i++){
		if(arr[i]<arr[i]+arr[i-1]) arr[i]=arr[i]+arr[i-1];
	}
	for(int i=0;i<n;i++){
		if(max<arr[i]) max=arr[i];
	}
	printf("%d", max);
	free(arr);
	return 0;
}
