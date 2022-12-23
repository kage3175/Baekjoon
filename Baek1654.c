#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INT 2147483647

long long left=1;long long right=1;

int able(long long lines[], long long k, long long n, long long length);

int main(void){
	long long *lines;
	int n, k;long long mid=0;
	scanf("%d %d", &k, &n);
	lines=(long long*)malloc(sizeof(long long)*k);
	for(int i=0;i<k;i++){
		scanf("%lld", &lines[i]);
		if(right<lines[i]) right=lines[i];
	}
	right++;
	while(left<=right){
		mid=(left+right)/2;
		if(mid==right){
			if(!able(lines, k, n, mid)) mid=left;
			break;
		}
		else if(mid==left){
			if(!able(lines, k, n, mid)) mid=right;
			break;
		}
		if(able(lines, k, n, mid)) left=mid;
		else right=mid;
	}
	
	printf("%lld", mid);
	
	free(lines);
	return 0;
}

int able(long long lines[], long long k, long long n, long long length){
	long long cnt=0;
	for(int i=0;i<k;i++){
		cnt+=lines[i]/length;
	}
	if(cnt>=n) return 1;
	else return 0;
}
