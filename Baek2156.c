#include <stdio.h>
#include <stdlib.h>

int *wine;
int **dp;//dp[n+1][2] i번째 와인까지 마셨을 때의 최댓값. dp[n-1][0]는 n번째 와인을 안 마셨다는 가정하의 값이고, dp[n-1][1]은 n번째를 마셨을 때 

int max(int a, int b){
	return a>b?a:b;
}

int main(void){
	int n=0;
	
	scanf("%d", &n);
	wine=(int*)malloc(sizeof(int)*(n+1));
	dp=(int**)malloc(sizeof(int*)*(n+1));
	for(int i=0;i<n+1;i++) dp[i]=(int*)malloc(sizeof(int)*2);
	wine[0]=0;
	for(int i=1;i<n+1;i++){
		scanf("%d",&wine[i]);
	}
	
	dp[0][0]=0;dp[0][1]=0;dp[1][1]=wine[1];dp[1][0]=wine[1];
	if(n>=2){
		dp[2][1]=wine[2];dp[2][0]=wine[2]+wine[1];
	}
	
	for(int i=3;i<n+1;i++){
		dp[i][0]=wine[i]+max(max(dp[i-1][1], dp[i-2][0]), dp[i-3][0]);
		dp[i][1]=wine[i]+max(dp[i-2][0], dp[i-3][0]);
	}
	
	printf("%d", max(dp[n][0], dp[n-1][0]));
	
	free(wine);
	for(int i=0;i<n+1;i++) free(dp[i]);
	free(dp);
	return 0;
}
