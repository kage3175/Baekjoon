#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long right=0;
long long left=0;
long long mid=0;

int able(long long height[], int n, long long m, long long mid);

int main(void){
	int n; long long m;
	long long* height;
	scanf("%d %lld", &n, &m);
	height=(long long*)malloc(sizeof(long long)*n);
	for(int i=0;i<n;i++){
		scanf("%lld", &height[i]);
		if(height[i]>right) right=height[i];
	}
	right++;
	while(left<=right){
		mid=(left+right)/2;
		//printf("%lld %lld\n", left, right);
		if(mid==right||mid==left){
			if(able(height, n, m, right)) mid=right;
			else mid=left;
			break;
		}
		if(able(height, n, m, mid)) left=mid;
		else right=mid;
	}
	
	printf("%lld", mid);
	
	free(height);
	return 0;
}

int able(long long height[], int n, long long k, long long mid){
	long long cnt=0;
	for(int i=0;i<n;i++){
		if(height[i]>mid){
			cnt+=height[i]-mid;
		}
	}
	if(cnt>=k) return 1;
	else return 0;
}

