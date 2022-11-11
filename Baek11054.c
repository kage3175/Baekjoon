#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n=0;int flag=0;
	int max=1;
	scanf("%d", &n);
	int arr[1001]={0};
	int dp[1001][2]={0};//dp[n][0]는 자기자신을 제외한 왼쪽 최대 바이토닉. [1]은 오른쪽 
	for(int i=1;i<n+1;i++) scanf("%d", &arr[i]);
	for(int i=1;i<n+1;i++){
		for(int j=1;j<i;j++){
			if(arr[i]>arr[j]){
				if(dp[i][0]<dp[j][0]+1) dp[i][0]=dp[j][0]+1;
			}
		}
	}
	for(int i=n;i>0;i--){
		for(int j=n;j>i;j--){
			if(arr[i]>arr[j]){
				if(dp[i][1]<dp[j][1]+1) dp[i][1]=dp[j][1]+1;
			}
		}
	}
	for(int i=1;i<n+1;i++){
		if(dp[i][0]+dp[i][1]+1>max) max=dp[i][0]+dp[i][1]+1;
	}
	
	printf("%d", max);
	
	return 0;
}
