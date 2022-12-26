#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *x;
int start=1;int end=0;int mid=0;

int static compare(const void*first, const void *second);
int able(int n,int c, int dist);

int main(void){
	int n=0;int c=0;int result=0;
	scanf("%d %d", &n, &c);
	x=(int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d", &x[i]);
	
	qsort(x,n,sizeof(int),compare);
	end=x[n-1]-x[0];
	
	while(start<=end){
		mid=(start+end)/2;
		if(able(n,c,mid)){
			start=mid+1;
			if(result<mid) result=mid;
		}
		else{
			end=mid-1;
		}
	}
	
	//for(int i=0;i<n;i++) printf("%d ", x[i]);
	
	printf("%d", result);
	
	free(x);
	return 0;
}

int static compare(const void*first, const void *second){
	if(*(int*)first>*(int*)second) return 1;
	else if(*(int*)first<*(int*)second) return -1;
	else return 0;
}

int able(int n, int c, int dist){
	int prev_house=x[0];
	int cnt=1;
	for(int i=0;i<n;i++){
		if(x[i]>=prev_house+dist){
			cnt++;
			prev_house=x[i];
		}
	}
	if(cnt>=c) return 1;
	else return 0;
}
